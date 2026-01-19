class TerjeHardwareWidgetPDA : TerjeHardwareWidgetBase
{
	protected float m_NetLedTimeout = 0;
	protected int m_NetLedControlId = -1;
	protected int m_PowerLedControlId = -1;
	protected int m_PowerBtnControlId = -1;
	protected int m_BackBtnControlId = -1;
	protected int m_CloseBtnControlId = -1;
	protected int m_VolupBtnControlId = -1;
	protected int m_VoldownBtnControlId = -1;
	
	override string GetNativeLayout()
	{
		return "TerjeElectronics/Layouts/Hardware/PDA.layout";
	}
	
	override void OnHardwareSetup()
	{
		super.OnHardwareSetup();
		
		SetupDisplayWidget("Display_Control", "Display_Overlay");
		m_NetLedControlId = SetupLedWidget("NetLed_Overlay");
		m_PowerLedControlId = SetupLedWidget("PowerLed_Overlay");
		m_PowerBtnControlId = SetupButtonWidget("PowerBtn_Control", "PowerBtn_Overlay", ScriptCaller.Create(OnPowerButtonClicked));
		m_BackBtnControlId = SetupButtonWidget("BackBtn_Control", "BackBtn_Overlay", ScriptCaller.Create(OnBackButtonClicked));
		m_CloseBtnControlId = SetupButtonWidget("CloseBtn_Control", "CloseBtn_Overlay", ScriptCaller.Create(OnCloseButtonClicked));
		m_VolupBtnControlId = SetupButtonWidget("VolupBtn_Control", "VolupBtn_Overlay", ScriptCaller.Create(OnVolumeUpButtonClicked));
		m_VoldownBtnControlId = SetupButtonWidget("VoldownBtn_Control", "VoldownBtn_Overlay", ScriptCaller.Create(OnVolumeDownButtonClicked));
	}
	
	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);
		
		if (m_NetLedTimeout > 0)
		{
			m_NetLedTimeout -= timeslice;
			if (m_NetLedTimeout <= 0)
			{
				SetLedState(m_NetLedControlId, false);
				m_NetLedTimeout = 0;
			}
		}
	}
	
	override void OnHardwarePowerChanged(TerjeHardwarePowerMode oldState, TerjeHardwarePowerMode newState)
	{
		super.OnHardwarePowerChanged(oldState, newState);
		
		SetLedState(m_PowerLedControlId, (newState != TerjeHardwarePowerMode.DISABLED));
	}
	
	override void OnHardwareNetSignalReceived(string id)
	{
		super.OnHardwareNetSignalReceived(id);
		
		SetLedState(m_NetLedControlId, true);
		m_NetLedTimeout = 0.05;
	}
	
	override void OnHardwareNetSignalSent(string id)
	{
		super.OnHardwareNetSignalSent(id);
		
		SetLedState(m_NetLedControlId, true);
		m_NetLedTimeout = 0.05;
	}
	
	protected void OnPowerButtonClicked()
	{
		TerjeHardwareBase hardware = GetHardwareData();
		if (hardware != null)
		{
			TerjeHardwarePowerMode powerMode = hardware.GetPowerMode();
			if ((powerMode == TerjeHardwarePowerMode.DISABLED) || (powerMode == TerjeHardwarePowerMode.HIBERNATED))
			{
				hardware.SetPowerMode(TerjeHardwarePowerMode.ENABLED);
			}
			else
			{
				hardware.SetPowerMode(TerjeHardwarePowerMode.HIBERNATED);
			}
		}
	}
	
	protected void OnBackButtonClicked()
	{
		TerjeHardwareBase hardware = GetHardwareData();
		if (hardware != null)
		{
			TerjeSoftwareBase software = hardware.GetSoftware();
			if (software != null)
			{
				software.BackProgram();
			}
		}
	}
	
	protected void OnCloseButtonClicked()
	{
		TerjeHardwareBase hardware = GetHardwareData();
		if (hardware != null)
		{
			TerjeSoftwareBase software = hardware.GetSoftware();
			if (software != null)
			{
				software.CloseProgram();
			}
		}
	}
	
	protected void OnVolumeUpButtonClicked()
	{
		// TODO
	}
	
	protected void OnVolumeDownButtonClicked()
	{
		// TODO
	}
}