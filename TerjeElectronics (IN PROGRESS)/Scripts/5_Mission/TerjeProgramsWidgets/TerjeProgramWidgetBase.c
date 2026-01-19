class TerjeProgramWidgetBase : TerjeWidgetBase
{
	protected TerjeGadgetBase m_gadgetEntity = null;
	protected TerjeHardwareBase m_hardwareData = null;
	protected TerjeSoftwareBase m_softwareData = null;
	protected TerjeProgramBase m_programData = null;
	
	void SetProgramData(TerjeProgramBase program)
	{
		if (program != null)
		{
			m_gadgetEntity = program.GetGadget();
			if (m_gadgetEntity)
			{
				m_hardwareData = m_gadgetEntity.GetHardware();
				if (m_hardwareData != null)
				{
					m_softwareData = m_hardwareData.GetSoftware();
				}
			}
		}
		
		m_programData = program;
		PushCommand(new TerjeWidgetCommand_TerjeProgramInit);
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
	
	TerjeProgramBase GetProgramData()
	{
		return m_programData;
	}
	
	protected void OnProgramInit()
	{
		
	}
	
	void OnDispose()
	{
		
	}
	
	override void OnCommand(TerjeWidgetCommand command, float timeslice)
	{
		super.OnCommand(command, timeslice);
		
		if (command.IsInherited(TerjeWidgetCommand_TerjeProgramInit))
		{
			OnProgramInit();
		}
	}
}

class TerjeWidgetCommand_TerjeProgramInit : TerjeWidgetCommand
{

}