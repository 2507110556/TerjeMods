class TerjeProgramBrowser : TerjeProgramBase
{
	override string GetWidgetClassname()
	{
		return string.Empty;
	}
	
	override string GetName()
	{
		return "#STR_TERJEGADGETS_PROG_BROWSER";
	}
	
	override string GetIcon(int type)
	{
		if (type == 1)
		{
			return "set:TerjeProgramIcons image:browser_m";
		}
		
		return "set:TerjeProgramIcons image:browser_c";
	}
}
