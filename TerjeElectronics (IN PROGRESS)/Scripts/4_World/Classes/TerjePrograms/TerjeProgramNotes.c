class TerjeProgramNotes : TerjeProgramBase
{
	override string GetWidgetClassname()
	{
		return string.Empty;
	}
	
	override string GetName()
	{
		return "#STR_TERJEGADGETS_PROG_NOTES";
	}
	
	override string GetIcon(int type)
	{
		if (type == 1)
		{
			return "set:TerjeProgramIcons image:notes_m";
		}
		
		return "set:TerjeProgramIcons image:notes_c";
	}
}
