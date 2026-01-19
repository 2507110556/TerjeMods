class TerjeGadgetWorkspaceWidget : TerjeGadgetComponentWidget
{
	protected TerjeGadgetComponentWidget m_bodyWidget = null;
	protected ref array<TerjeGadgetBarWidget> m_statusBarWidgets = new array<TerjeGadgetBarWidget>;
	protected ref array<TerjeGadgetBarWidget> m_notificationBarWidgets = new array<TerjeGadgetBarWidget>;
	
	override void OnSoftwareInit()
	{
		super.OnSoftwareInit();
		
		TerjeGadgetBase gadget = GetGadgetEntity();
		if (gadget)
		{
			if (gadget.m_ProgramChangedEvent != null)
			{
				gadget.m_ProgramChangedEvent.Insert(OnProgramChanged);
			}
		}
		
		TerjeSoftwareBase software = GetSoftwareData();
		if (software != null)
		{
			OnProgramChanged(null, software.GetActiveProgram());
		}
	}
	
	override void OnDispose()
	{
		super.OnDispose();
		
		TerjeGadgetBase gadget = GetGadgetEntity();
		if (gadget)
		{
			if (gadget.m_ProgramChangedEvent != null)
			{
				gadget.m_ProgramChangedEvent.Remove(OnProgramChanged);
			}
		}
		
		if (m_bodyWidget != null)
		{
			m_bodyWidget.OnDispose();
			m_bodyWidget = null;
		}
		
		foreach (TerjeGadgetBarWidget statusBarWidget : m_statusBarWidgets)
		{
			if (statusBarWidget != null)
			{
				statusBarWidget.OnDispose();
			}
		}
		
		m_statusBarWidgets.Clear();
		
		foreach (TerjeGadgetBarWidget notificationBarWidget : m_notificationBarWidgets)
		{
			if (notificationBarWidget != null)
			{
				notificationBarWidget.OnDispose();
			}
		}
		
		m_notificationBarWidgets.Clear();
	}
	
	override void OnCommand(TerjeWidgetCommand command, float timeslice)
	{
		super.OnCommand(command, timeslice);
		
		if (command.IsInherited(TerjeWidgetCommand_TerjeGadgetWorkspaceChanged))
		{
			TerjeWidgetCommand_TerjeGadgetWorkspaceChanged commandChanged = TerjeWidgetCommand_TerjeGadgetWorkspaceChanged.Cast(command);
			OnProgramChangedCommand(commandChanged.m_oldProgram, commandChanged.m_newProgram);
		}
	}
	
	protected void OnProgramChanged(TerjeProgramBase oldProgram, TerjeProgramBase newProgram)
	{
		PushCommand(new TerjeWidgetCommand_TerjeGadgetWorkspaceChanged(oldProgram, newProgram));
	}
	
	protected void OnProgramChangedCommand(TerjeProgramBase oldProgram, TerjeProgramBase newProgram)
	{
		if (m_bodyWidget != null)
		{
			m_bodyWidget.OnDispose();
			DestroyTerjeWidget(m_bodyWidget);
			m_bodyWidget = null;
		}
		
		if (newProgram != null)
		{
			m_bodyWidget = TerjeGadgetComponentWidget.Cast(CreateTerjeWidgetEx(GetWindowWidgetType(), GetNativeBodyWidget()));
			if (m_bodyWidget != null)
			{
				m_bodyWidget.SetSoftwareData(GetSoftwareData());
				TerjeGadgetWindowWidget windowWidget = TerjeGadgetWindowWidget.Cast(m_bodyWidget);
				if (windowWidget != null)
				{
					windowWidget.SetProgramData(newProgram);
				}
			}
		}
		else
		{
			m_bodyWidget = TerjeGadgetComponentWidget.Cast(CreateTerjeWidgetEx(GetDesktopWidgetType(), GetNativeBodyWidget()));
			if (m_bodyWidget != null)
			{
				m_bodyWidget.SetSoftwareData(GetSoftwareData());
			}
		}
	}
	
	protected typename GetDesktopWidgetType()
	{
		return TerjeGadgetDesktopWidget;
	}
	
	protected typename GetWindowWidgetType()
	{
		return TerjeGadgetWindowWidget;
	}
	
	protected Widget GetNativeBodyWidget()
	{
		return GetNativeWidget().FindAnyWidget("WorkspaceBody");
	}
	
	protected Widget GetNativeStatusBarWidget()
	{
		return GetNativeWidget().FindAnyWidget("WorkspaceBarRight");
	}
	
	protected Widget GetNativeNotificationBarWidget()
	{
		return GetNativeWidget().FindAnyWidget("WorkspaceBarLeft");
	}
	
	protected TerjeGadgetBarWidget CreateStatusBarWidget(typename type)
	{
		TerjeGadgetBarWidget result = TerjeGadgetBarWidget.Cast(CreateTerjeWidgetEx(type, GetNativeStatusBarWidget()));
		if (result != null)
		{
			result.SetSoftwareData(GetSoftwareData());
			m_statusBarWidgets.Insert(result);
		}
		
		return result;
	}
	
	protected TerjeGadgetBarWidget CreateNotificationBarWidget(typename type)
	{
		TerjeGadgetBarWidget result = TerjeGadgetBarWidget.Cast(CreateTerjeWidgetEx(type, GetNativeNotificationBarWidget()));
		if (result != null)
		{
			result.SetSoftwareData(GetSoftwareData());
			m_notificationBarWidgets.Insert(result);
		}
		
		return result;
	}
}

class TerjeWidgetCommand_TerjeGadgetWorkspaceChanged : TerjeWidgetCommand
{
	TerjeProgramBase m_oldProgram;
	TerjeProgramBase m_newProgram;
	
	void TerjeWidgetCommand_TerjeGadgetWorkspaceChanged(TerjeProgramBase oldProgram, TerjeProgramBase newProgram)
	{
		m_oldProgram = oldProgram;
		m_newProgram = newProgram;
	}
}