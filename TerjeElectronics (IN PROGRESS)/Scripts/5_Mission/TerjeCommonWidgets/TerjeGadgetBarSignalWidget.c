class TerjeGadgetBarSignalWidget : TerjeGadgetBarWidget
{
	protected string m_lastIconPath = string.Empty;
	
	protected ImageWidget GetNativeIconWidget()
	{
		return ImageWidget.Cast(GetNativeWidget().FindAnyWidget("BarSignalIcon"));
	}
	
	protected string GetSignalIconPath()
	{
		float power01 = 0;
		TerjeGadgetBase gadget = GetGadgetEntity();
		if (gadget)
		{
			power01 = Math.Clamp(gadget.GetSignalPower(), 0, 1);
		}
		
		if (power01 > 0.8)
		{
			return "set:TerjeSoftwareIcons image:signal_5";
		}
		else if (power01 > 0.6)
		{
			return "set:TerjeSoftwareIcons image:signal_4";
		}
		else if (power01 > 0.4)
		{
			return "set:TerjeSoftwareIcons image:signal_3";
		}
		else if (power01 > 0.2)
		{
			return "set:TerjeSoftwareIcons image:signal_2";
		}
		else if (power01 > 0.0)
		{
			return "set:TerjeSoftwareIcons image:signal_1";
		}
		
		return "set:TerjeSoftwareIcons image:signal_0";
	}
	
	override string GetNativeLayout()
	{
		return "TerjeElectronics/Layouts/Widgets/SoftwareBarSignal.layout";
	}
	
	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);
		
		string iconPath = GetSignalIconPath();
		ImageWidget widget = GetNativeIconWidget();
		if ((widget != null) && (m_lastIconPath != iconPath))
		{
			m_lastIconPath = iconPath;
			widget.LoadImageFile(0, iconPath);
		}
	}
}