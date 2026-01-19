class TerjeProgramTetris : TerjeProgramBase
{
	override string GetWidgetClassname()
	{
		return string.Empty;
	}
	
	override string GetName()
	{
		return "#STR_TERJEGADGETS_PROG_TETRIS";
	}
	
	override string GetIcon(int type)
	{
		if (type == 1)
		{
			return "set:TerjeProgramIcons image:tetris_m";
		}
		
		return "set:TerjeProgramIcons image:tetris_c";
	}
}
