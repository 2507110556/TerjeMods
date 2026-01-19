class TerjeSoftwareWidgetBase : TerjeWidgetBase
{
	protected TerjeGadgetBase m_gadgetEntity = null;
	protected TerjeHardwareBase m_hardwareData = null;
	protected TerjeSoftwareBase m_softwareData = null;
	protected TerjeGadgetComponentWidget m_contentWidget = null;
	
	void SetSoftwareData(TerjeSoftwareBase software)
	{
		if (software != null)
		{
			m_gadgetEntity = software.GetGadget();
			if (m_gadgetEntity)
			{
				m_hardwareData = m_gadgetEntity.GetHardware();
			}
		}
		
		m_softwareData = software;
		PushCommand(new TerjeWidgetCommand_TerjeSoftwareInit);
	}
	
	TerjeGadgetBase GetGadgetEntity()
	{
		return m_gadgetEntity;
	}
	
	TerjeHardwareBase GetHardwareData()
	{
		return m_hardwareData;
	}
	
	TerjeSoftwareBase GetSoftwareData()
	{
		return m_softwareData;
	}
	
	TerjeGadgetComponentWidget GetContentWidget()
	{
		return m_contentWidget;
	}
	
	protected void OnSoftwareSetup()
	{
		TerjeGadgetBase entity = GetGadgetEntity();
		if (entity != null)
		{
			if (entity.m_BootChangedEvent != null)
			{
				entity.m_BootChangedEvent.Insert(OnSoftwareBootChanged);
			}
			
			if (entity.m_NetSignalReceivedEvent != null)
			{
				entity.m_NetSignalReceivedEvent.Insert(OnSoftwareNetSignalReceived);
			}
			
			if (entity.m_NetSignalSentEvent != null)
			{
				entity.m_NetSignalSentEvent.Insert(OnSoftwareNetSignalSent);
			}
		}
		
		if (GetSoftwareData() != null)
		{
			PushCommand(new TerjeWidgetCommand_TerjeSoftwareBoot(GetSoftwareData().GetBootMode()));
		}
	}
	
	protected void OnSoftwareBootChanged(TerjeSoftwareBootMode oldState, TerjeSoftwareBootMode newState)
	{
		if (oldState != newState)
		{
			PushCommand(new TerjeWidgetCommand_TerjeSoftwareBoot(newState));
		}
	}
	
	protected void OnSoftwareNetSignalReceived(string id)
	{
	
	}
	
	protected void OnSoftwareNetSignalSent(string id)
	{
	
	}
	
	void OnDispose()
	{
		if (m_contentWidget != null)
		{
			m_contentWidget.OnDispose();
			m_contentWidget = null;
		}
		
		DestroyAllChildren();
		
		TerjeGadgetBase entity = GetGadgetEntity();
		if (entity != null)
		{
			if (entity.m_BootChangedEvent != null)
			{
				entity.m_BootChangedEvent.Remove(OnSoftwareBootChanged);
			}
			
			if (entity.m_NetSignalReceivedEvent != null)
			{
				entity.m_NetSignalReceivedEvent.Remove(OnSoftwareNetSignalReceived);
			}
			
			if (entity.m_NetSignalSentEvent != null)
			{
				entity.m_NetSignalSentEvent.Remove(OnSoftwareNetSignalSent);
			}
		}
	}
	
	override void OnCommand(TerjeWidgetCommand command, float timeslice)
	{
		super.OnCommand(command, timeslice);
		
		if (command.IsInherited(TerjeWidgetCommand_TerjeSoftwareInit))
		{
			OnSoftwareSetup();
		}
		else if (command.IsInherited(TerjeWidgetCommand_TerjeSoftwareBoot))
		{
			OnSoftwareBootCommand(TerjeWidgetCommand_TerjeSoftwareBoot.Cast(command));
		}
	}
	
	protected void OnSoftwareBootCommand(TerjeWidgetCommand_TerjeSoftwareBoot cmd)
	{
		if (m_contentWidget != null)
		{
			m_contentWidget.OnDispose();
			m_contentWidget = null;
		}
		
		DestroyAllChildren();
		
		if (GetSoftwareData() != null)
		{
			m_contentWidget = CreateActualContentWidget(cmd.m_mode);
			if (m_contentWidget != null)
			{
				m_contentWidget.SetSoftwareData(GetSoftwareData());
			}
		}
	}
	
	protected TerjeGadgetComponentWidget CreateActualContentWidget(TerjeSoftwareBootMode mode)
	{
		if (mode == TerjeSoftwareBootMode.INIT)
		{
			 return TerjeGadgetComponentWidget.Cast(CreateTerjeWidget(GetBootConsoleWidgetType()));
		}
		else if (mode == TerjeSoftwareBootMode.LOADING)
		{
			return TerjeGadgetComponentWidget.Cast(CreateTerjeWidget(GetLoadscreenWidgetType()));
		}
		else if (mode == TerjeSoftwareBootMode.LOCKSCREEN)
		{
			return null; // TODO
		}
		else if (mode == TerjeSoftwareBootMode.WORKSPACE)
		{
			return TerjeGadgetComponentWidget.Cast(CreateTerjeWidget(GetWorkspaceWidgetType()));
		}
		else if (mode == TerjeSoftwareBootMode.HACKED)
		{
			return null; // TODO
		}
		
		return null;
	}
	
	protected typename GetBootConsoleWidgetType()
	{
		return TerjeGadgetConsoleWidget;
	}
	
	protected typename GetLoadscreenWidgetType()
	{
		return TerjeGadgetLoadscreenWidget;
	}
	
	protected typename GetWorkspaceWidgetType()
	{
		return TerjeGadgetWorkspaceWidget;
	}
}

class TerjeWidgetCommand_TerjeSoftwareInit : TerjeWidgetCommand
{

}

class TerjeWidgetCommand_TerjeSoftwareBoot : TerjeWidgetCommand
{
	TerjeSoftwareBootMode m_mode;
	
	void TerjeWidgetCommand_TerjeSoftwareBoot(TerjeSoftwareBootMode mode)
	{
		m_mode = mode;
	}
}