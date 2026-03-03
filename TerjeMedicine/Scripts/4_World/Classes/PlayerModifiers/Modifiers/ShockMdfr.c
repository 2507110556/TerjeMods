modded class ShockMdfr
{
	override float GetRefillSpeed(PlayerBase player)
	{	
		float perkRecshockMod = 1.0;
		if (player.GetTerjeSkills())
		{
			float perkRecshock;
			if (player.GetTerjeSkills().GetPerkValue("immunity", "recshock", perkRecshock))
			{
				perkRecshockMod += perkRecshock;
			}
		}
		
		return super.GetRefillSpeed(player) * perkRecshockMod;
	}
}
