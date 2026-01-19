class TerjeHardwareBase
{
	protected TerjeGadgetBase m_gadget;
	protected int m_serialNumber;
	protected ref TerjeSoftwareBase m_software = null;
	protected ref set<int> m_soundLocalCache = new set<int>;
	protected TerjeHardwarePowerMode m_powerMode = TerjeHardwarePowerMode.DISABLED;
	
	TerjeGadgetBase GetGadget()
	{
		return m_gadget;
	}
	
	TerjeSoftwareBase GetSoftware()
	{
		return m_software;
	}
	
	void OnInit(TerjeGadgetBase gadget)
	{
		m_gadget = gadget;
	}
	
	void OnSetup()
	{
		m_serialNumber = Math.RandomInt(100000000, 999999999);
		
		TerjeGadgetBase gadget = GetGadget();
		if (GetGame() && GetGame().IsDedicatedServer() && gadget && (m_software == null))
		{
			string softwareClass = GetTerjeGameConfig().ConfigGetStringRaw("CfgVehicles " + gadget.GetType() + " softwareClass");
			if (softwareClass != string.Empty)
			{
				typename softwareTypename = softwareClass.ToType();
				if (softwareTypename && softwareTypename.IsInherited(TerjeSoftwareBase))
				{
					m_software = TerjeSoftwareBase.Cast(softwareTypename.Spawn());
					if (m_software != null)
					{
						m_software.OnInit(gadget);
						m_software.OnSetup();
					}
				}
			}
		}
	}
	
	void OnUpdate(float deltaTime)
	{
		if ((m_software != null) && (GetPowerMode() == TerjeHardwarePowerMode.ENABLED))
		{
			m_software.OnUpdate(deltaTime);
		}
		
		if (GetGame() && GetGame().IsDedicatedServer())
		{
			UpdatePowerMode();
		}
	}
	
	void OnStoreLoad(TerjeStorageReadingContext ctx)
	{
		ctx.ReadInt("ser", m_serialNumber);
		
		int oldPowerMode = GetPowerMode();
		if (ctx.ReadInt("pow", m_powerMode) && (m_powerMode != oldPowerMode))
		{
			OnPowerModeChanged(oldPowerMode, m_powerMode);
		}
		
		string softwareClass;
		TerjeStorageReadingContext softwareData = ctx.ReadSubcontext("swd");
		if (ctx.ReadString("swc", softwareClass) && (softwareData != null))
		{
			typename softwareTypename = softwareClass.ToType();
			if (softwareTypename && softwareTypename.IsInherited(TerjeSoftwareBase))
			{
				m_software = TerjeSoftwareBase.Cast(softwareTypename.Spawn());
				if (m_software != null)
				{
					m_software.OnInit(GetGadget());
					m_software.OnStoreLoad(softwareData);
				}
			}
		}
	}
	
	void OnStoreSave(TerjeStorageWritingContext ctx)
	{
		ctx.WriteInt("ser", m_serialNumber);
		
		TerjeSoftwareBase software = GetSoftware();
		if (software != null)
		{
			ctx.WriteString("swc", software.Type().ToString());
			software.OnStoreSave(ctx.WriteSubcontext("swd"));
		}
		
		ctx.WriteInt("pow", m_powerMode);
	}
	
	void OnSyncReceive(ParamsReadContext ctx)
	{
		int newPowerMode;
		if (!ctx.Read(newPowerMode))
			return;
		
		int oldPowerMode = GetPowerMode();
		if (newPowerMode != oldPowerMode)
		{
			m_powerMode = newPowerMode;
			OnPowerModeChanged(oldPowerMode, newPowerMode);
		}
		
		if (!ctx.Read(m_serialNumber))
			return;
		
		string softwareClass;
		if (ctx.Read(softwareClass) && (softwareClass != string.Empty))
		{
			typename softwareTypename = softwareClass.ToType();
			if (softwareTypename && softwareTypename.IsInherited(TerjeSoftwareBase))
			{
				m_software = TerjeSoftwareBase.Cast(softwareTypename.Spawn());
				if (m_software != null)
				{
					m_software.OnInit(GetGadget());
					m_software.OnSyncReceive(ctx);
				}
			}
		}
	}
	
	void OnSyncSend(ParamsWriteContext ctx)
	{
		ctx.Write(m_powerMode);
		ctx.Write(m_serialNumber);
		
		TerjeSoftwareBase software = GetSoftware();
		if (software != null)
		{
			ctx.Write(software.Type().ToString());
			software.OnSyncSend(ctx);
		}
		else
		{
			ctx.Write(string.Empty);
		}
	}
	
	void OnRPC(string id, ParamsReadContext ctx)
	{
		if (id == "snd")
		{
			OnRPC_Sound(ctx);
		}
		else if (id == "pow")
		{
			OnRPC_Power(ctx);
		}
	}
	
	string GetWidgetClassname()
	{
		return string.Empty;
	}
	
	bool HasDisplay()
	{
		return false;
	}
	
	bool HasSpeaker()
	{
		return false;
	}
	
	TerjeHardwarePowerMode GetPowerMode()
	{
		return m_powerMode;
	}
	
	int GetSerialNumberInt()
	{
		return m_serialNumber;
	}
	
	string GetSerialNumberHex()
	{
		return TerjeStringHelper.EncodeToHex(m_serialNumber.ToString());
	}
	
	void SetPowerMode(TerjeHardwarePowerMode mode)
	{
		TerjeHardwarePowerMode oldPowerMode = m_powerMode;
		if (GetGame() && GetGadget() && (mode != oldPowerMode))
		{
			bool valid = false;
			if (mode == TerjeHardwarePowerMode.ENABLED)
			{
				if (CanBePoweredOn())
				{
					valid = true;
				}
			}
			else if (mode == TerjeHardwarePowerMode.HIBERNATED)
			{
				if (CanBeHibernated())
				{
					valid = true;
				}
			}
			else if (mode == TerjeHardwarePowerMode.DISABLED)
			{
				if (CanBePoweredOff())
				{
					valid = true;
				}
			}
			
			if (valid)
			{
				if (GetGame().IsDedicatedServer())
				{
					m_powerMode = mode;
					OnPowerModeChanged(oldPowerMode, mode);
				}
				
				TerjeStreamRpc stream;
				SendRPC("pow", stream);
				stream.Write(mode);
				stream.Flush();
			}
		}
	}
	
	protected void UpdatePowerMode()
	{
		if ((GetPowerMode() != TerjeHardwarePowerMode.DISABLED) && (GetGadget().GetAvailablePower() <= 0))
		{
			SetPowerMode(TerjeHardwarePowerMode.DISABLED);
		}
	}
	
	protected bool CanBePoweredOn()
	{
		return (GetGadget() != null) && (GetGadget().GetAvailablePower() > 0);
	}
	
	protected bool CanBeHibernated()
	{
		return CanBePoweredOn();
	}
	
	protected bool CanBePoweredOff()
	{
		return true;
	}
	
	
	protected void OnPowerModeChanged(TerjeHardwarePowerMode oldState, TerjeHardwarePowerMode newState)
	{
		TerjeSoftwareBase software = GetSoftware();
		if (software != null)
		{
			software.OnPowerModeChanged(oldState, newState);
		}
		
		TerjeGadgetBase gadget = GetGadget();
		if (gadget && (gadget.m_PowerChangedEvent != null))
		{
			gadget.m_PowerChangedEvent.Invoke(oldState, newState);
		}
	}
	
	protected void OnRPC_Power(ParamsReadContext ctx)
	{
		int powerMode;
		if (GetGame() && ctx.Read(powerMode))
		{
			TerjeHardwarePowerMode oldPowerMode = GetPowerMode();
			if (GetGame().IsDedicatedServer())
			{
				SetPowerMode(powerMode);
			}
			else if (GetGame().IsClient())
			{
				m_powerMode = powerMode;
				if (oldPowerMode != powerMode)
				{
					OnPowerModeChanged(oldPowerMode, powerMode);
				}
			}
		}
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
	
	void SendRPC(string id, out TerjeStreamRpc stream)
	{
		if (GetGadget())
		{
			GetGadget().TerjeGadgetSendRPC("hwd.rpc", stream);
			stream.Write(id);
		}
	}
}