class TerjeGadgetBase : ItemBase
{
	protected ref TerjeHardwareBase m_hardware = null;
	protected float m_LastHardwareUpdatedTime = 0;
	
	ref ScriptInvoker m_PowerChangedEvent = new ScriptInvoker();
	ref ScriptInvoker m_BootChangedEvent = new ScriptInvoker();
	ref ScriptInvoker m_ProgramChangedEvent = new ScriptInvoker();
	ref ScriptInvoker m_NetSignalReceivedEvent = new ScriptInvoker();
	ref ScriptInvoker m_NetSignalSentEvent = new ScriptInvoker();
	
	bool CanOpenGadgetMenu()
	{
		if (GetHardware() != null)
		{
			return true;
		}
		
		return false;
	}
	
	float GetAvailablePower()
	{
		return 1.0;
	}
	
	float GetSignalPower()
	{
		return 1.0;
	}
	
	TerjeHardwareBase GetHardware()
	{
		if (GetGame() && GetGame().IsDedicatedServer() && (m_hardware == null))
		{
			string hardwareClass = GetTerjeGameConfig().ConfigGetStringRaw("CfgVehicles " + GetType() + " hardwareClass");
			if (hardwareClass != string.Empty)
			{
				typename hardwareTypename = hardwareClass.ToType();
				if (hardwareTypename && hardwareTypename.IsInherited(TerjeHardwareBase))
				{
					m_hardware = TerjeHardwareBase.Cast(hardwareTypename.Spawn());
					if (m_hardware != null)
					{
						m_hardware.OnInit(this);
						m_hardware.OnSetup();
					}
				}
			}
		}
		
		return m_hardware;
	}
	
	override void EEInit()
	{
		super.EEInit();
		
		if (GetGame())
		{
			if (GetGame().IsClient())
			{
				TerjeSendToServer("init.req", null);
			}
			
			ScheduleTerjeGadgetUpdate();
		}
	}
	
	override void OnTerjeRPC(PlayerIdentity sender, string id, ParamsReadContext ctx)
	{
		TerjeStreamRpc stream;
		TerjeHardwareBase hardware;
		TerjeSoftwareBase software;
		if (id == "init.req")
		{
			hardware = GetHardware();
			if (GetGame() && GetGame().IsDedicatedServer() && (sender != null) && (hardware != null))
			{
				TerjeStreamToClient("init.res", sender, stream);
				stream.Write(hardware.Type().ToString());
				hardware.OnSyncSend(stream);
				stream.Flush();
			}
		}
		else if (id == "init.res")
		{
			if (GetGame() && GetGame().IsClient())
			{
				string hardwareClass;
				if (ctx.Read(hardwareClass))
				{
					typename hardwareTypename = hardwareClass.ToType();
					if (hardwareTypename && hardwareTypename.IsInherited(TerjeHardwareBase))
					{
						m_hardware = TerjeHardwareBase.Cast(hardwareTypename.Spawn());
						if (m_hardware != null)
						{
							m_hardware.OnInit(this);
							m_hardware.OnSyncReceive(ctx);
						}
					}
				}
			}
		}
		else if (id == "hwd.rpc")
		{
			hardware = GetHardware();
			if (hardware != null)
			{
				string hwdStreamId;
				if (ctx.Read(hwdStreamId))
				{
					hardware.OnRPC(hwdStreamId, ctx);
				}
			}
		}
		else if (id == "sft.rpc")
		{
			hardware = GetHardware();
			if (hardware != null)
			{
				software = hardware.GetSoftware();
				if (software != null)
				{
					string sftStreamId;
					if (ctx.Read(sftStreamId))
					{
						software.OnRPC(sftStreamId, ctx);
					}
				}
			}
		}
		else if (id == "prg.rpc")
		{
			hardware = GetHardware();
			if (hardware != null)
			{
				software = hardware.GetSoftware();
				if (software != null)
				{
					string programClassname;
					string programStreamId;
					if (ctx.Read(programClassname) && ctx.Read(programStreamId) )
					{
						TerjeProgramBase programObject;
						typename programTypename = programClassname.ToType();
						if (programTypename && software.FindProgram(programTypename, programObject) && (programObject != null))
						{
							programObject.OnRPC(programStreamId, ctx);
						}
					}
				}
			}
		}
		
		if (m_NetSignalReceivedEvent != null)
		{
			m_NetSignalReceivedEvent.Invoke(id);
		}
	}
	
	override void OnTerjeStoreSave(TerjeStorageWritingContext ctx)
	{
		super.OnTerjeStoreSave(ctx);
		
		if (m_hardware != null)
		{
			ctx.WriteString("hwc", m_hardware.Type().ToString());
			m_hardware.OnStoreSave(ctx.WriteSubcontext("hwd"));
		}
	}
	
	override void OnTerjeStoreLoad(TerjeStorageReadingContext ctx)
	{
		super.OnTerjeStoreLoad(ctx);
		
		string hardwareClass;
		TerjeStorageReadingContext hardwareData = ctx.ReadSubcontext("hwd");
		if (ctx.ReadString("hwc", hardwareClass) && (hardwareData != null))
		{
			typename hardwareTypename = hardwareClass.ToType();
			if (hardwareTypename && hardwareTypename.IsInherited(TerjeHardwareBase))
			{
				m_hardware = TerjeHardwareBase.Cast(hardwareTypename.Spawn());
				if (m_hardware != null)
				{
					m_hardware.OnInit(this);
					m_hardware.OnStoreLoad(hardwareData);
				}
			}
		}
	}
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTerjeGadgetUse);
	}
	
	void TerjeGadgetSendRPC(string id, out TerjeStreamRpc stream)
	{
		if (GetGame())
		{
			if (GetGame().IsDedicatedServer())
			{
				TerjeStreamToAll(id, stream);
			}
			else if (GetGame().IsClient())
			{
				TerjeStreamToServer(id, stream);
			}
			
			if (m_NetSignalSentEvent != null)
			{
				m_NetSignalSentEvent.Invoke(id);
			}
		}
	}
	
	protected void ScheduleTerjeGadgetUpdate()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(HandleTerjeGadgetUpdate, 1000);
	}
	
	protected void HandleTerjeGadgetUpdate()
	{
		ScheduleTerjeGadgetUpdate();
		OnTerjeGadgetUpdate();
	}
	
	protected void OnTerjeGadgetUpdate()
	{
		TerjeHardwareBase hardware = GetHardware();
		if (hardware != null)
		{
			float currentTime = GetGame().GetTickTime();
			if (m_LastHardwareUpdatedTime == 0)
			{
				m_LastHardwareUpdatedTime = currentTime;
			}
			
			float deltaTime = currentTime - m_LastHardwareUpdatedTime; 
			m_LastHardwareUpdatedTime = currentTime;
			
			hardware.OnUpdate(deltaTime);
		}
	}
}
