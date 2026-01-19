class TerjeHardwarePDA : TerjeHardwareBase
{
	override string GetWidgetClassname()
	{
		return "TerjeHardwareWidgetPDA";
	}
	
	override bool HasDisplay()
	{
		return true;
	}
	
	override bool HasSpeaker()
	{
		return true;
	}
}