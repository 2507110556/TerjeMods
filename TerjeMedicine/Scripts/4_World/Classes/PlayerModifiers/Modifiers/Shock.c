modded class ShockMdfr
{
	override float GetRefillSpeed(PlayerBase player)
	{	
		float perkRecshockMod;
		if (player.GetTerjeSkills() && player.GetTerjeSkills().GetPerkValue("immunity", "recshock", perkRecshockMod))
		{
			perkRecshockMod = 1.0 + perkRecshockMod;
		}
		else
		{
			perkRecshockMod = 1.0;
		}
		
		return super.GetRefillSpeed(player) * perkRecshockMod;
	}
}