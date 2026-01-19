class TerjeProgramSettings : TerjeProgramBase
{
	override string GetWidgetClassname()
	{
		return string.Empty;
	}
	
	override string GetName()
	{
		return "#STR_TERJEGADGETS_PROG_SETTINGS";
	}
	
	override string GetIcon(int type)
	{
		if (type == 1)
		{
			return "set:TerjeProgramIcons image:settings_m";
		}
		
		return "set:TerjeProgramIcons image:settings_c";
	}
}
