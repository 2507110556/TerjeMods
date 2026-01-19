class TerjeGadgetBarTimeWidget : TerjeGadgetBarWidget
{
	protected string m_lastTimeString = string.Empty;
	
	protected TextWidget GetNativeTextWidget()
	{
		return TextWidget.Cast(GetNativeWidget().FindAnyWidget("BarTimeText"));
	}
	
	protected string GetTimeString()
	{
		if (GetGame() && GetGame().GetWorld())
		{
			int year;
			int month;
			int day;
			int hour;
			int minute;
			GetGame().GetWorld().GetDate(year, month, day, hour, minute);
			
			string hourStr = hour.ToString();
			if (hourStr.Length() == 1)
			{
				hourStr = "0" + hourStr;
			}
			
			string minuteStr = minute.ToString();
			if (minuteStr.Length() == 1)
			{
				minuteStr = "0" + minuteStr;
			}
			
			return hourStr + ":" + minuteStr;
		}
		
		return string.Empty;
	}
	
	override string GetNativeLayout()
	{
		return "TerjeElectronics/Layouts/Widgets/SoftwareBarTime.layout";
	}
	
	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);
		
		string timeString = GetTimeString();
		TextWidget widget = GetNativeTextWidget();
		if ((widget != null) && (m_lastTimeString != timeString))
		{
			m_lastTimeString = timeString;
			widget.SetText(timeString);
		}
	}
}