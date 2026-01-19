modded class VitaminBottle
{
	override int TerjeOverrideDescriptionByConsumableEffects()
	{
		if (GetGame().IsClient())
		{
			return 2;
		}
		
		return super.TerjeOverrideDescriptionByConsumableEffects();
	}
}