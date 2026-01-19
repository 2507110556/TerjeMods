class TerjeGadgetWindowWidget : TerjeGadgetComponentWidget
{
	protected TerjeProgramWidgetBase m_programWidget = null;
	protected TerjeProgramBase m_programData = null;
	
	void SetProgramData(TerjeProgramBase program)
	{
		m_programData = program;
	}
	
	override void OnSoftwareInit()
	{
		super.OnSoftwareInit();
		
		if (m_programData != null)
		{
			typename widgetTypename = m_programData.GetWidgetClassname().ToType();
			if (widgetTypename && widgetTypename.IsInherited(TerjeProgramWidgetBase))
			{
				m_programWidget = TerjeProgramWidgetBase.Cast(CreateTerjeWidgetEx(widgetTypename, GetNativeContentWidget()));
				if (m_programWidget != null)
				{
					m_programWidget.SetProgramData(m_programData);
				}
			}
		}
	}
	
	override void OnDispose()
	{
		super.OnDispose();
		
		if (m_programWidget != null)
		{
			m_programWidget.OnDispose();
			m_programWidget = null;
		}
	}
	
	protected Widget GetNativeContentWidget()
	{
		return GetNativeWidget().FindAnyWidget("WindowContent");
	}
}