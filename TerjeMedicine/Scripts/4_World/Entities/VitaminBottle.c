modded class VitaminBottle
{
	override int TerjeOverrideDescriptionByConsumableEffects()
	{
		if (g_Game.IsClient())
		{
			return 2;
		}
		
		return super.TerjeOverrideDescriptionByConsumableEffects();
	}
}