modded class Edible_Base
{
	override int TerjeOverrideDescriptionByConsumableEffects()
	{
		if (GetGame().IsClient())
		{
			PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
			if (player && player.GetTerjeSkills())
			{
				if ((!GetTerjeGameConfig().ConfigGetBool("CfgVehicles " + GetType() + " medicalPillsCategory")) && player.GetTerjeSkills().GetPerkLevel("surv", "expert") > 0)
				{
					return 2;
				}
			}
		}
		
		return super.TerjeOverrideDescriptionByConsumableEffects();
	}
}