class TerjeProgramGallery : TerjeProgramBase
{
	override string GetWidgetClassname()
	{
		return string.Empty;
	}
	
	override string GetName()
	{
		return "#STR_TERJEGADGETS_PROG_GALLERY";
	}
	
	override string GetIcon(int type)
	{
		if (type == 1)
		{
			return "set:TerjeProgramIcons image:gallery_m";
		}
		
		return "set:TerjeProgramIcons image:gallery_c";
	}
}
