class TerjeSoftwareBase
{
	protected float m_bootTimer = 0;
	protected TerjeGadgetBase m_gadget;
	protected TerjeSoftwareBootMode m_bootMode = TerjeSoftwareBootMode.DISABLED;
	protected ref set<int> m_soundLocalCache = new set<int>;
	protected ref map<typename, ref TerjeProgramBase> m_programs = new map<typename, ref TerjeProgramBase>;
	protected ref array<typename> m_orderedPrograms = new array<typename>;
	protected TerjeProgramBase m_activeProgram = null;
	protected string m_passlock = string.Empty;
	
	float GetBootTimer()
	{
		return m_bootTimer;
	}
	
	void SetBootTimer(float value)
	{
		m_bootTimer = value;
	}
	
	TerjeGadgetBase GetGadget()
	{
		return m_gadget;
	}
	
	string GetPasslock()
	{
		return m_passlock;
	}
	
	void OnInit(TerjeGadgetBase gadget)
	{
		m_gadget = gadget;
	}
	
	void OnSetup()
	{
		TerjeGadgetBase gadget = GetGadget();
		if (GetGame() && GetGame().IsDedicatedServer() && gadget)
		{
			TStringArray programsClassList();
			GetTerjeGameConfig().ConfigGetTextArrayRaw("CfgVehicles " + gadget.GetType() + " programsClassList", programsClassList);
			foreach (string programClassname : programsClassList)
			{
				typename programTypename = programClassname.ToType();
				if (programTypename && programTypename.IsInherited(TerjeProgramBase) && !m_programs.Contains(programTypename))
				{
					TerjeProgramBase program = TerjeProgramBase.Cast(programTypename.Spawn());
					if (program != null)
					{
						m_programs.Set(programTypename, program);
						m_orderedPrograms.Insert(programTypename);
						program.OnInit(gadget);
						program.OnInstall();
					}
				}
			}
		}
	}
	
	void OnUpdate(float deltaTime)
	{
		TerjeProgramBase program = GetActiveProgram();
		if (program != null)
		{
			program.OnUpdate(deltaTime);
		}
	}
	
	void OnStoreLoad(TerjeStorageReadingContext ctx)
	{
		int oldBootMode = GetBootMode();
		if (ctx.ReadInt("sbm", m_bootMode) && (m_bootMode != oldBootMode))
		{
			OnBootModeChanged(oldBootMode, m_bootMode);
		}
		
		TerjeStorageReadingContext progsCtx = ctx.ReadSubcontext("progs");
		if (progsCtx != null)
		{
			m_programs.Clear();
			m_orderedPrograms.Clear();
			TStringArray programClassnamesList();
			progsCtx.GetSubcontextKeysArray(programClassnamesList);
			foreach (string programClassname : programClassnamesList)
			{
				TerjeStorageReadingContext programCtx = progsCtx.ReadSubcontext(programClassname);
				if (programCtx != null)
				{
					typename programTypename = programClassname.ToType();
					if (programTypename && programTypename.IsInherited(TerjeProgramBase) && !m_programs.Contains(programTypename))
					{
						TerjeProgramBase program = TerjeProgramBase.Cast(programTypename.Spawn());
						if (program != null)
						{
							m_programs.Set(programTypename, program);
							m_orderedPrograms.Insert(programTypename);
							program.OnInit(GetGadget());
							program.OnStoreLoad(programCtx);
						}
					}
				}
			}
		}
		
		
		string activeProgramClass = string.Empty;
		if (ctx.ReadString("apt", activeProgramClass))
		{
			TerjeProgramBase activeProgram = null;
			if (activeProgramClass != string.Empty)
			{
				typename activeProgramTypename = activeProgramClass.ToType();
				if (activeProgramTypename && activeProgramTypename.IsInherited(TerjeProgramBase))
				{
					if (!FindProgram(activeProgramTypename, activeProgram))
					{
						activeProgram = null;
					}
				}
			}
			
			if (m_activeProgram != activeProgram)
			{
				OnProgramChanged(m_activeProgram, activeProgram);
			}
		}
	}
	
	void OnStoreSave(TerjeStorageWritingContext ctx)
	{
		TerjeStorageWritingContext progsCtx = ctx.WriteSubcontext("progs");
		foreach (typename progTypename : m_orderedPrograms)
		{
			TerjeProgramBase progObject;
			if (m_programs.Find(progTypename, progObject) && (progObject != null))
			{
				progObject.OnStoreSave(progsCtx.WriteSubcontext(progTypename.ToString()));
			}
		}
		
		ctx.WriteInt("sbm", GetBootMode());
		ctx.WriteString("apt", GetActiveProgramType());
	}
	
	void OnSyncReceive(ParamsReadContext ctx)
	{
		// Programs list
		int programsCount;
		m_programs.Clear();
		m_orderedPrograms.Clear();
		if (!ctx.Read(programsCount))
			return;
		
		for (int progId = 0; progId < programsCount; progId++)
		{
			string programClassname;
			if (!ctx.Read(programClassname))
				return;
			
			typename programTypename = programClassname.ToType();
			if (programTypename && programTypename.IsInherited(TerjeProgramBase) && !m_programs.Contains(programTypename))
			{
				TerjeProgramBase program = TerjeProgramBase.Cast(programTypename.Spawn());
				if (program != null)
				{
					m_programs.Set(programTypename, program);
					m_orderedPrograms.Insert(programTypename);
					program.OnInit(GetGadget());
					program.OnSyncReceive(ctx);
				}
			}
		}
		
		// Boot mode
		int newBootMode;
		if (!ctx.Read(newBootMode))
			return;
		
		int oldBootMode = GetBootMode();
		if (newBootMode != oldBootMode)
		{
			m_bootMode = newBootMode;
			OnBootModeChanged(oldBootMode, newBootMode);
		}
		
		// Active program
		string newActiveProgramType;
		if (!ctx.Read(newActiveProgramType))
			return;
		
		TerjeProgramBase newActiveProgram;
		if (!FindProgram(newActiveProgramType, newActiveProgram))
		{
			newActiveProgram = null;
		}
		
		TerjeProgramBase oldActiveProgram = GetActiveProgram();
		if (newActiveProgram != oldActiveProgram)
		{
			m_activeProgram = newActiveProgram;
			OnProgramChanged(oldActiveProgram, newActiveProgram);
		}
	}
	
	void OnSyncSend(ParamsWriteContext ctx)
	{
		ctx.Write(m_programs.Count());
		foreach (typename progTypename : m_orderedPrograms)
		{
			TerjeProgramBase progObject;
			if (m_programs.Find(progTypename, progObject) && (progObject != null))
			{
				ctx.Write(progTypename.ToString());
				progObject.OnSyncSend(ctx);
			}
		}
		
		ctx.Write(GetBootMode());
		ctx.Write(GetActiveProgramType());
	}
	
	void OnRPC(string id, ParamsReadContext ctx)
	{
		if (id == "sbm")
		{
			OnRPC_BootMode(ctx);
		}
		else if (id == "snd")
		{
			OnRPC_Sound(ctx);
		}
		else if (id == "apt")
		{
			OnRPC_ActiveProgram(ctx);
		}
	}
	
	void OnPowerModeChanged(TerjeHardwarePowerMode oldState, TerjeHardwarePowerMode newState)
	{
		
	}
	
	void OnBootModeChanged(TerjeSoftwareBootMode oldState, TerjeSoftwareBootMode newState)
	{
		TerjeGadgetBase gadget = GetGadget();
		if (gadget && (gadget.m_BootChangedEvent != null))
		{
			gadget.m_BootChangedEvent.Invoke(oldState, newState);
		}
	}
	
	void OnProgramChanged(TerjeProgramBase oldProgram, TerjeProgramBase newProgram)
	{
		if (oldProgram != null)
		{
			oldProgram.OnClose();
		}
		
		if (newProgram != null)
		{
			newProgram.OnStart();
		}
		
		TerjeGadgetBase gadget = GetGadget();
		if (gadget && (gadget.m_ProgramChangedEvent != null))
		{
			gadget.m_ProgramChangedEvent.Invoke(oldProgram, newProgram);
		}
	}
	
	TerjeSoftwareBootMode GetBootMode()
	{
		return m_bootMode;
	}
	
	void SetBootMode(TerjeSoftwareBootMode mode)
	{
		TerjeSoftwareBootMode oldBootMode = m_bootMode;
		if (GetGame() && GetGadget() && (mode != oldBootMode))
		{
			if (GetGame().IsDedicatedServer())
			{
				m_bootMode = mode;
				OnBootModeChanged(oldBootMode, mode);
			}
			
			TerjeStreamRpc stream;
			SendRPC("sbm", stream);
			stream.Write(mode);
			stream.Flush();
		}
	}
	
	bool FindProgram(string classname, out TerjeProgramBase result)
	{
		typename type = classname.ToType();
		if (type && type.IsInherited(TerjeProgramBase))
		{
			return FindProgram(type, result);
		}
		
		return false;
	}
	
	bool FindProgram(typename type, out TerjeProgramBase result)
	{
		return m_programs.Find(type, result);
	}
	
	bool AddProgram(typename type)
	{
		TerjeGadgetBase gadget = GetGadget();
		if (GetGame() && GetGame().IsDedicatedServer() && gadget)
		{
			if ((type.IsInherited(TerjeProgramBase)) && (!m_programs.Contains(type)))
			{
				TerjeProgramBase program = TerjeProgramBase.Cast(type.Spawn());
				if (program != null)
				{
					m_programs.Set(type, program);
					m_orderedPrograms.Insert(type);
					program.OnInit(gadget);
					program.OnInstall();
					return true;
				}
			}
		}
		
		return false;
	}
	
	bool RemoveProgram(typename type)
	{
		if (GetGame() && GetGame().IsDedicatedServer())
		{
			TerjeProgramBase program;
			if (m_programs.Find(type, program))
			{
				if (program != null)
				{
					program.OnUninstall();
				}
				
				m_programs.Remove(type);
				
				int orderedIndex = m_orderedPrograms.Find(type);
				if (orderedIndex != -1)
				{
					m_orderedPrograms.RemoveOrdered(orderedIndex);
				}
				
				return true;
			}
		}
		
		return false;
	}
	
	void GetAllPrograms(array<TerjeProgramBase> result)
	{
		foreach (typename progTypename : m_orderedPrograms)
		{
			TerjeProgramBase program;
			if (m_programs.Find(progTypename, program) && (program != null))
			{
				result.Insert(program);
			}
		}
	}
	
	TerjeProgramBase GetActiveProgram()
	{
		return m_activeProgram;
	}
	
	string GetActiveProgramType()
	{
		if (m_activeProgram != null)
		{
			return m_activeProgram.Type().ToString();
		}
		
		return string.Empty;
	}
	
	void SetActiveProgram(TerjeProgramBase program)
	{
		TerjeProgramBase oldActiveProgram = m_activeProgram;
		if (GetGame() && GetGadget() && (program != oldActiveProgram))
		{
			if (GetGame().IsDedicatedServer())
			{
				m_activeProgram = program;
				OnProgramChanged(oldActiveProgram, program);
			}
			
			TerjeStreamRpc stream;
			SendRPC("apt", stream);
			
			if (program != null)
			{
				stream.Write(program.Type().ToString());
			}
			else
			{
				stream.Write(string.Empty);
			}
			
			stream.Flush();
		}
	}
	
	void OpenProgram(typename programType)
	{
		TerjeProgramBase program;
		if (FindProgram(programType, program) && (program != null))
		{
			SetActiveProgram(program);
		}
	}
	
	void CloseProgram()
	{
		if (GetActiveProgram() != null)
		{
			SetActiveProgram(null);
		}
	}
	
	void BackProgram()
	{
		TerjeProgramBase program = GetActiveProgram();
		if (program != null)
		{
			program.OnBack();
		}
	}
	
	string GetWidgetClassname()
	{
		return string.Empty;
	}
	
	void PlaySoundClick()
	{
	
	}
	
	void PlaySound(string name, int idx = -1)
	{
		if (idx == -1)
		{
			idx = Math.RandomInt(0, int.MAX);
		}
		
		if (GetGame() && GetGame().IsClient())
		{
			EffectSound sound;
			OnPlaySound(name, idx, sound);
			m_soundLocalCache.Insert(idx);
		}
		
		TerjeStreamRpc stream;
		SendRPC("snd", stream);
		stream.Write(name);
		stream.Write(idx);
		stream.Flush();
	}
	
	protected void OnPlaySound(string soundName, int soundIdx, out EffectSound sound)
	{
		if (GetGame() && GetGame().IsClient())
		{
			int cacheIdx = m_soundLocalCache.Find(soundIdx);
			if (cacheIdx != -1)
			{
				m_soundLocalCache.Remove(cacheIdx);
				return;
			}
			
			GetGadget().PlaySoundSet(sound, soundName, 0, 0, false);
		}
	}
	
	void SendRPC(string id, out TerjeStreamRpc stream)
	{
		if (GetGadget())
		{
			GetGadget().TerjeGadgetSendRPC("sft.rpc", stream);
			stream.Write(id);
		}
	}
	
	protected void OnRPC_Sound(ParamsReadContext ctx)
	{
		string soundName;
		int soundIdx;
		if (ctx.Read(soundName) && ctx.Read(soundIdx))
		{
			if (GetGame() && GetGadget())
			{
				if (GetGame().IsDedicatedServer())
				{
					PlaySound(soundName, soundIdx);
				}
				else if (GetGame().IsClient())
				{
					EffectSound sound;
					OnPlaySound(soundName, soundIdx, sound);
				}
			}
		}
	}
	
	protected void OnRPC_BootMode(ParamsReadContext ctx)
	{
		int bootMode;
		if (GetGame() && ctx.Read(bootMode))
		{
			TerjeSoftwareBootMode oldBootMode = GetBootMode();
			if (GetGame().IsDedicatedServer())
			{
				SetBootMode(bootMode);
			}
			else if (GetGame().IsClient())
			{
				m_bootMode = bootMode;
				if (oldBootMode != bootMode)
				{
					OnBootModeChanged(oldBootMode, bootMode);
				}
			}
		}
	}
	
	protected void OnRPC_ActiveProgram(ParamsReadContext ctx)
	{
		string newActiveProgramType;
		if (GetGame() && ctx.Read(newActiveProgramType))
		{
			TerjeProgramBase newActiveProgram;
			if (!FindProgram(newActiveProgramType, newActiveProgram))
			{
				newActiveProgram = null;
			}
			
			TerjeProgramBase oldActiveProgram = GetActiveProgram();
			if (GetGame().IsDedicatedServer())
			{
				SetActiveProgram(newActiveProgram);
			}
			else if (GetGame().IsClient())
			{
				m_activeProgram = newActiveProgram;
				if (oldActiveProgram != newActiveProgram)
				{
					OnProgramChanged(oldActiveProgram, newActiveProgram);
				}
			}
		}
	}
}