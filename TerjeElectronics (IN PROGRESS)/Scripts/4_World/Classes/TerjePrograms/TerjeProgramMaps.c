class TerjeProgramMaps : TerjeProgramBase
{
	override string GetWidgetClassname()
	{
		return string.Empty;
	}
	
	override string GetName()
	{
		return "#STR_TERJEGADGETS_PROG_MAPS";
	}
	
	override string GetIcon(int type)
	{
		if (type == 1)
		{
			return "set:TerjeProgramIcons image:maps_m";
		}
		
		return "set:TerjeProgramIcons image:maps_c";
	}
}
