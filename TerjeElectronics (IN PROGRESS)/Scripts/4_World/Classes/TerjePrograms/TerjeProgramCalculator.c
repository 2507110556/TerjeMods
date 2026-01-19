class TerjeProgramCalculator : TerjeProgramBase
{
	override string GetWidgetClassname()
	{
		return "TerjeProgramWidgetCalculator";
	}
	
	override string GetName()
	{
		return "#STR_TERJEGADGETS_PROG_CALC";
	}
	
	override string GetIcon(int type)
	{
		if (type == 1)
		{
			return "set:TerjeProgramIcons image:calculator_m";
		}
		
		return "set:TerjeProgramIcons image:calculator_c";
	}
}
