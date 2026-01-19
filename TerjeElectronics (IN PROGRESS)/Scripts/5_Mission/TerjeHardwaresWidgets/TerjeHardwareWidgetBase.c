class TerjeHardwareWidgetBase : TerjeWidgetBase
{
	protected TerjeGadgetBase m_gadgetEntity = null;
	protected TerjeHardwareBase m_hardwareData = null;
	protected TerjeSoftwareWidgetBase m_softwareWidget = null;
	protected ref TerjeWidgetData_TerjeHardwareDisplay m_nativeDisplay;
	protected ref array<ref TerjeWidgetData_TerjeHardwareButton> m_nativeButtons;
	protected ref array<ref TerjeWidgetData_TerjeHardwareLed> m_nativeLeds;
	
	void SetHardwareData(TerjeHardwareBase hardware)
	{
		if (hardware != null)
		{
			m_gadgetEntity = hardware.GetGadget();
		}
		
		m_hardwareData = hardware;
		m_softwareWidget = null;
		PushCommand(new TerjeWidgetCommand_TerjeHardwareInit);
	}
	
	TerjeGadgetBase GetGadgetEntity()
	{
		return m_gadgetEntity;
	}
	
	TerjeHardwareBase GetHardwareData()
	{
		return m_hardwareData;
	}
	
	protected void OnHardwareSetup()
	{
		m_nativeDisplay = null;
		m_nativeButtons = new array<ref TerjeWidgetData_TerjeHardwareButton>;
		m_nativeLeds = new array<ref TerjeWidgetData_TerjeHardwareLed>;
		
		TerjeGadgetBase entity = GetGadgetEntity();
		if (entity != null)
		{
			if (entity.m_PowerChangedEvent != null)
			{
				entity.m_PowerChangedEvent.Insert(OnHardwarePowerChanged);
			}
			
			if (entity.m_NetSignalReceivedEvent != null)
			{
				entity.m_NetSignalReceivedEvent.Insert(OnHardwareNetSignalReceived);
			}
			
			if (entity.m_NetSignalSentEvent != null)
			{
				entity.m_NetSignalSentEvent.Insert(OnHardwareNetSignalSent);
			}
		}
	}
	
	protected void OnHardwareInit()
	{
		TerjeHardwareBase hardware = GetHardwareData();
		if (hardware != null)
		{
			if ((hardware.HasDisplay()) && (hardware.GetSoftware() != null))
			{
				string softwareWidgetClass = hardware.GetSoftware().GetWidgetClassname();
				if ((m_nativeDisplay != null) && (m_nativeDisplay.m_controlWidget != null) && (softwareWidgetClass != string.Empty))
				{
					typename softwareWidgetType = softwareWidgetClass.ToType();
					if (softwareWidgetType && (softwareWidgetType.IsInherited(TerjeSoftwareWidgetBase)))
					{
						m_softwareWidget = TerjeSoftwareWidgetBase.Cast(CreateTerjeWidgetEx(softwareWidgetType, m_nativeDisplay.m_controlWidget));
						if (m_softwareWidget != null)
						{
							m_softwareWidget.SetSoftwareData(hardware.GetSoftware());
						}
					}
					
					HandleNativeDisplayCommand(new TerjeWidgetCommand_TerjeHardwareDisplay(hardware.GetPowerMode() == TerjeHardwarePowerMode.ENABLED));
				}
			}
		}
		
		for (int nbtnId = 0; nbtnId < m_nativeButtons.Count(); nbtnId++)
		{
			TerjeWidgetData_TerjeHardwareButton nbtnData = m_nativeButtons.Get(nbtnId);
			if ((nbtnData != null) && (nbtnData.m_buttonWidget != null))
			{
				HandleNativeButtonOverlayCommand(new TerjeWidgetCommand_TerjeHardwareButtonOverlay(nbtnId, false));
			}
		}
		
		for (int nledId = 0; nledId < m_nativeLeds.Count(); nledId++)
		{
			TerjeWidgetData_TerjeHardwareLed nledData = m_nativeLeds.Get(nledId);
			if ((nledData != null) && (nledData.m_overlayWidget != null))
			{
				HandleNativeLedCommand(new TerjeWidgetCommand_TerjeHardwareLed(nledId, false));
			}
		}
	}
	
	protected void OnHardwarePowerChanged(TerjeHardwarePowerMode oldState, TerjeHardwarePowerMode newState)
	{
		PushCommand(new TerjeWidgetCommand_TerjeHardwareDisplay(newState == TerjeHardwarePowerMode.ENABLED));
	}
	
	protected void OnHardwareNetSignalReceived(string id)
	{
	
	}
	
	protected void OnHardwareNetSignalSent(string id)
	{
	
	}
	
	void OnDispose()
	{
		TerjeGadgetBase entity = GetGadgetEntity();
		if (entity != null)
		{
			if (entity.m_PowerChangedEvent != null)
			{
				entity.m_PowerChangedEvent.Remove(OnHardwarePowerChanged);
			}
			
			if (entity.m_NetSignalReceivedEvent != null)
			{
				entity.m_NetSignalReceivedEvent.Remove(OnHardwareNetSignalReceived);
			}
			
			if (entity.m_NetSignalSentEvent != null)
			{
				entity.m_NetSignalSentEvent.Remove(OnHardwareNetSignalSent);
			}
		}
		
		if (m_softwareWidget != null)
		{
			m_softwareWidget.OnDispose();
			m_softwareWidget = null;
		}
	}
	
	override void OnCommand(TerjeWidgetCommand command, float timeslice)
	{
		super.OnCommand(command, timeslice);
		
		if (command.IsInherited(TerjeWidgetCommand_TerjeHardwareInit))
		{
			DestroyAllChildren();
			OnHardwareSetup();
			OnHardwareInit();
		}
		else if (command.IsInherited(TerjeWidgetCommand_TerjeHardwareButtonOverlay))
		{
			HandleNativeButtonOverlayCommand(TerjeWidgetCommand_TerjeHardwareButtonOverlay.Cast(command));
		}
		else if (command.IsInherited(TerjeWidgetCommand_TerjeHardwareLed))
		{
			HandleNativeLedCommand(TerjeWidgetCommand_TerjeHardwareLed.Cast(command));
		}
		else if (command.IsInherited(TerjeWidgetCommand_TerjeHardwareDisplay))
		{
			HandleNativeDisplayCommand(TerjeWidgetCommand_TerjeHardwareDisplay.Cast(command));
		}
	}
	
	override bool OnMouseLeave(Widget w, Widget enterW, int x, int y)
	{
		if (w != null)
		{
			if (ProcessNativeButtonOverlayCommand(w, 0))
			{
				return true;
			}
		}
		
		return super.OnMouseLeave(w, enterW, x, y);
	}
	
	override bool OnMouseEnter(Widget w, int x, int y)
	{
		if (w != null)
		{
			if (ProcessNativeButtonOverlayCommand(w, 1))
			{
				return true;
			}
		}
		
		return super.OnMouseEnter(w, x, y);
	}
	
	override bool OnMouseButtonDown(Widget w, int x, int y, int button)
	{
		if ((w != null) && (button == MouseState.LEFT))
		{
			if (ProcessNativeButtonOverlayCommand(w, 2))
			{
				return true;
			}
		}
		
		return super.OnMouseButtonDown(w, x, y, button);
	}
	
	override bool OnClick(Widget w, int x, int y, int button)
	{
		if ((w != null) && (button == MouseState.LEFT))
		{
			if (ProcessNativeButtonOverlayCommand(w, 3))
			{
				return true;
			}
		}
		
		return super.OnClick(w, x, y, button);
	}
	
	protected void SetupDisplayWidget(string controlName, string overlayName)
	{
		Widget w = GetNativeWidget().FindAnyWidget(controlName);
		Widget o = GetNativeWidget().FindAnyWidget(overlayName);
		if ((w != null) && (o != null))
		{
			m_nativeDisplay = new TerjeWidgetData_TerjeHardwareDisplay(w, o);
		}
	}
	
	protected int SetupButtonWidget(string buttonName, string overlayName, ScriptCaller callback)
	{
		Widget w = GetNativeWidget().FindAnyWidget(buttonName);
		Widget o = GetNativeWidget().FindAnyWidget(overlayName);
		if ((w != null) && (o != null))
		{
			return m_nativeButtons.Insert(new TerjeWidgetData_TerjeHardwareButton(w, o, callback));
		}
		
		return -1;
	}
	
	protected int SetupLedWidget(string overlayName)
	{
		Widget o = GetNativeWidget().FindAnyWidget(overlayName);
		if (o != null)
		{
			return m_nativeLeds.Insert(new TerjeWidgetData_TerjeHardwareLed(o));
		}
		
		return -1;
	}
	
	protected bool GetLedState(int id)
	{
		if (id >= 0 && id < m_nativeLeds.Count())
		{
			TerjeWidgetData_TerjeHardwareLed ledData = m_nativeLeds.Get(id);
			if (ledData != null)
			{
				return ledData.m_actualState;
			}
		}
		
		return false;
	}
	
	protected void SetLedState(int id, bool state)
	{
		if ((m_hardwareData != null) && (m_hardwareData.GetPowerMode() != TerjeHardwarePowerMode.DISABLED) && (id >= 0) && (id < m_nativeLeds.Count()))
		{
			TerjeWidgetData_TerjeHardwareLed ledData = m_nativeLeds.Get(id);
			if ((ledData != null) && (ledData.m_actualState != state))
			{
				ledData.m_actualState = state;
				PushCommand(new TerjeWidgetCommand_TerjeHardwareLed(id, state));
			}
		}
	}
	
	protected bool ProcessNativeButtonOverlayCommand(Widget w, int state)
	{
		for (int i = 0; i < m_nativeButtons.Count(); i++)
		{
			TerjeWidgetData_TerjeHardwareButton btnData = m_nativeButtons.Get(i);
			if ((btnData != null) && (btnData.m_buttonWidget != null) && (btnData.m_buttonWidget == w))
			{
				PushCommand(new TerjeWidgetCommand_TerjeHardwareButtonOverlay(i, state));
				return true;
			}
		}
		
		return false;
	}
	
	protected void HandleNativeButtonOverlayCommand(TerjeWidgetCommand_TerjeHardwareButtonOverlay cmd)
	{
		for (int btnOverlayId = 0; btnOverlayId < m_nativeButtons.Count(); btnOverlayId++)
		{
			TerjeWidgetData_TerjeHardwareButton btnData = m_nativeButtons.Get(btnOverlayId);
			if (btnData != null)
			{
				Widget btnOverlayWidget = btnData.m_overlayWidget;
				if (btnOverlayWidget != null)
				{
					if (cmd.m_index == btnOverlayId)
					{
						if (cmd.m_state == 1)
						{
							btnOverlayWidget.SetColor(ARGB(128, 255, 255, 255));
						}
						else if (cmd.m_state == 2)
						{
							btnOverlayWidget.SetColor(ARGB(255, 255, 255, 255));
						}
						else if (cmd.m_state == 3)
						{
							btnOverlayWidget.SetColor(ARGB(128, 255, 255, 255));
							
							if ((btnData.m_callback != null) && (btnData.m_callback.IsValid()))
							{
								btnData.m_callback.Invoke();
							}
							
							if (m_hardwareData != null)
							{
								m_hardwareData.PlaySound("TerjeGadgetButtonClick_SoundSet");
							}
						}
						else
						{
							btnOverlayWidget.SetColor(ARGB(0, 255, 255, 255));
						}
					}
					else if (cmd.m_state > 0)
					{
						btnOverlayWidget.SetColor(ARGB(0, 255, 255, 255));
					}
				}
			}
		}
	}
	
	protected void HandleNativeLedCommand(TerjeWidgetCommand_TerjeHardwareLed cmd)
	{
		if (cmd.m_index >= 0 && cmd.m_index < m_nativeLeds.Count())
		{
			TerjeWidgetData_TerjeHardwareLed ledData = m_nativeLeds.Get(cmd.m_index);
			if ((ledData != null) && (ledData.m_overlayWidget != null))
			{
				ledData.m_overlayWidget.Show(cmd.m_state);
			}
		}
	}
	
	protected void HandleNativeDisplayCommand(TerjeWidgetCommand_TerjeHardwareDisplay cmd)
	{
		if (m_nativeDisplay != null)
		{
			if (m_nativeDisplay.m_controlWidget != null)
			{
				m_nativeDisplay.m_controlWidget.Show(cmd.m_state);
			}
			
			if (m_nativeDisplay.m_overlayWidget != null)
			{
				m_nativeDisplay.m_overlayWidget.Show(cmd.m_state);
			}
		}
	}
}

class TerjeWidgetCommand_TerjeHardwareInit : TerjeWidgetCommand
{

}

class TerjeWidgetCommand_TerjeHardwareDisplay : TerjeWidgetCommand
{
	bool m_state;
	
	void TerjeWidgetCommand_TerjeHardwareDisplay(bool state)
	{
		m_state = state;
	}
}

class TerjeWidgetCommand_TerjeHardwareButtonOverlay : TerjeWidgetCommand
{
	int m_index;
	int m_state;
	
	void TerjeWidgetCommand_TerjeHardwareButtonOverlay(int index, int state)
	{
		m_index = index;
		m_state = state;
	}
}

class TerjeWidgetData_TerjeHardwareDisplay
{
	Widget m_controlWidget;
	Widget m_overlayWidget;
	
	void TerjeWidgetData_TerjeHardwareDisplay(Widget controlWidget, Widget overlayWidget)
	{
		m_controlWidget = controlWidget;
		m_overlayWidget = overlayWidget;
	}
}

class TerjeWidgetData_TerjeHardwareButton
{
	Widget m_buttonWidget;
	Widget m_overlayWidget;
	ref ScriptCaller m_callback;
	
	void TerjeWidgetData_TerjeHardwareButton(Widget buttonWidget, Widget overlayWidget, ScriptCaller callback)
	{
		m_buttonWidget = buttonWidget;
		m_overlayWidget = overlayWidget;
		m_callback = callback;
	}
}

class TerjeWidgetCommand_TerjeHardwareLed : TerjeWidgetCommand
{
	int m_index;
	bool m_state;
	
	void TerjeWidgetCommand_TerjeHardwareLed(int index, bool state)
	{
		m_index = index;
		m_state = state;
	}
}

class TerjeWidgetData_TerjeHardwareLed
{
	Widget m_overlayWidget;
	bool m_actualState;
	
	void TerjeWidgetData_TerjeHardwareLed(Widget overlayWidget)
	{
		m_overlayWidget = overlayWidget;
		m_actualState = false;
	}
}