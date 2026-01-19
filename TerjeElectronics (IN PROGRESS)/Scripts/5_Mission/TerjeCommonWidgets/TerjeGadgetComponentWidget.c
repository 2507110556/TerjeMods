class TerjeGadgetComponentWidget : TerjeWidgetBase
{
	protected TerjeGadgetBase m_gadgetEntity = null;
	protected TerjeHardwareBase m_hardwareData = null;
	protected TerjeSoftwareBase m_softwareData = null;
	
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
		PushCommand(new TerjeWidgetCommand_TerjeSoftwareBootInit);
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
	
	void OnDispose()
	{
		
	}
	
	override void OnCommand(TerjeWidgetCommand command, float timeslice)
	{
		super.OnCommand(command, timeslice);
		
		if (command.IsInherited(TerjeWidgetCommand_TerjeSoftwareBootInit))
		{
			OnSoftwareInit();
		}
	}
	
	protected void OnSoftwareInit()
	{
	
	}
}

class TerjeWidgetCommand_TerjeSoftwareBootInit : TerjeWidgetCommand
{

}