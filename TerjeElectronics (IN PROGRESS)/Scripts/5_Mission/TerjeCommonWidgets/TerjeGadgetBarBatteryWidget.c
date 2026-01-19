class TerjeGadgetBarBatteryWidget : TerjeGadgetBarWidget
{
	protected string m_lastIconPath = string.Empty;
	
	protected ImageWidget GetNativeIconWidget()
	{
		return ImageWidget.Cast(GetNativeWidget().FindAnyWidget("BarBatteryIcon"));
	}
	
	protected string GetBatteryIconPath()
	{
		float power01 = 0;
		TerjeGadgetBase gadget = GetGadgetEntity();
		if (gadget)
		{
			power01 = Math.Clamp(gadget.GetAvailablePower(), 0, 1);
		}
		
		if (power01 > 0.8)
		{
			return "set:TerjeSoftwareIcons image:battery_4";
		}
		else if (power01 > 0.6)
		{
			return "set:TerjeSoftwareIcons image:battery_3";
		}
		else if (power01 > 0.4)
		{
			return "set:TerjeSoftwareIcons image:battery_2";
		}
		else if (power01 > 0.2)
		{
			return "set:TerjeSoftwareIcons image:battery_1";
		}
		
		return "set:TerjeSoftwareIcons image:battery_0";
	}
	
	override string GetNativeLayout()
	{
		return "TerjeElectronics/Layouts/Widgets/SoftwareBarBattery.layout";
	}
	
	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);
		
		string iconPath = GetBatteryIconPath();
		ImageWidget widget = GetNativeIconWidget();
		if ((widget != null) && (m_lastIconPath != iconPath))
		{
			m_lastIconPath = iconPath;
			widget.LoadImageFile(0, iconPath);
		}
	}
}