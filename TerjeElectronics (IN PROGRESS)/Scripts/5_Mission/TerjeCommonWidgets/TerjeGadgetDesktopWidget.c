class TerjeGadgetDesktopWidget : TerjeGadgetComponentWidget
{
	override void OnSoftwareInit()
	{
		super.OnSoftwareInit();
		
		TerjeSoftwareBase software = GetSoftwareData();
		if (software != null)
		{
			array<TerjeProgramBase> programs();
			software.GetAllPrograms(programs);
			foreach (TerjeProgramBase program : programs)
			{
				TerjeGadgetDesktopItemWidget itemWidget = TerjeGadgetDesktopItemWidget.Cast(CreateTerjeWidgetEx(GetItemWidgetType(), GetNativeBodyWidget()));
				itemWidget.SetSoftwareData(software);
				itemWidget.SetProgramData(program);
			}
		}
	}
	
	protected typename GetItemWidgetType()
	{
		return TerjeGadgetDesktopItemWidget;
	}
	
	protected Widget GetNativeBodyWidget()
	{
		return GetNativeWidget().FindAnyWidget("DesktopContent");
	}
}