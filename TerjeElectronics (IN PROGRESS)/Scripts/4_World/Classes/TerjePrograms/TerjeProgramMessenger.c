class TerjeProgramMessenger : TerjeProgramBase
{
	override string GetWidgetClassname()
	{
		return string.Empty;
	}
	
	override string GetName()
	{
		return "#STR_TERJEGADGETS_PROG_MSG";
	}
	
	override string GetIcon(int type)
	{
		if (type == 1)
		{
			return "set:TerjeProgramIcons image:messenger_m";
		}
		
		return "set:TerjeProgramIcons image:messenger_c";
	}
}
