class TerjeGadgetMenu : TerjeScriptedMenu
{
	protected TerjeGadgetBase m_gadgetEntity = null;
	protected TerjeHardwareWidgetBase m_hardwareWidget = null;
	
	void SetTerjeGadget(TerjeGadgetBase entity)
	{
		m_gadgetEntity = entity;
		m_hardwareWidget = null;
		PushCommand(new TerjeWidgetCommand_TerjeGadgetMenuInit);
	}
	
	TerjeGadgetBase GetGadget()
	{
		return m_gadgetEntity;
	}
	
	override void OnCommand(TerjeWidgetCommand command, float timeslice)
	{
		super.OnCommand(command, timeslice);
		
		if (command.IsInherited(TerjeWidgetCommand_TerjeGadgetMenuInit))
		{
			DestroyAllChildren();
			
			if ((m_gadgetEntity != null) && (m_gadgetEntity.GetHardware() != null))
			{
				string hardwareWidgetClass = m_gadgetEntity.GetHardware().GetWidgetClassname();
				if (hardwareWidgetClass != string.Empty)
				{
					typename hardwareWidgetType = hardwareWidgetClass.ToType();
					if (hardwareWidgetType && (hardwareWidgetType.IsInherited(TerjeHardwareWidgetBase)))
					{
						m_hardwareWidget = TerjeHardwareWidgetBase.Cast(CreateTerjeWidget(hardwareWidgetType));
						if (m_hardwareWidget != null)
						{
							m_hardwareWidget.SetHardwareData(m_gadgetEntity.GetHardware());
						}
					}
				}
			}
		}
	}
	
	override void OnClose()
	{
		if (m_hardwareWidget != null)
		{
			m_hardwareWidget.OnDispose();
			m_hardwareWidget = null;
		}
		
		m_gadgetEntity = null;
	}
	
	override bool CanBeClosed()
	{
		return true;
	}
	
	override bool IsHudVisible()
	{
		return true;
	}
	
	override bool IsCursorVisible()
	{
		return true;
	}
	
	override bool IsInputControllerDisabled()
	{
		return false;
	}
	
	override bool IsRestrictedInputUsed()
	{
		return true;
	}
	
	override bool IsSoundMuted()
	{
		return false;
	}
	
	override bool IsBlurEffectUsed()
	{
		return true;
	}
	
	override int GetBackgroundColor()
	{
		return ARGB(0, 0, 0, 0);
	}
}

class TerjeWidgetCommand_TerjeGadgetMenuInit : TerjeWidgetCommand
{

}