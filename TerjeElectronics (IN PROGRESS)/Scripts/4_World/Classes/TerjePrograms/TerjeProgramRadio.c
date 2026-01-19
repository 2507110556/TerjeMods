class TerjeProgramRadio : TerjeProgramBase
{
	override string GetWidgetClassname()
	{
		return string.Empty;
	}
	
	override string GetName()
	{
		return "#STR_TERJEGADGETS_PROG_RADIO";
	}
	
	override string GetIcon(int type)
	{
		if (type == 1)
		{
			return "set:TerjeProgramIcons image:radio_m";
		}
		
		return "set:TerjeProgramIcons image:radio_c";
	}
}
