modded class TerjePlayerModifierBase
{
	override float GetPlayerImmunity(PlayerBase player)
	{
		if (player.GetTerjeSkills())
		{
			if (player.GetTerjeSkills().IsPerkRegistered("immunity", "resdiseasesmod"))
			{
				float immunityMod;
				if (player.GetTerjeSkills().GetSkillModifierValue("immunity", "resdiseasesmod", immunityMod))
				{
					return Math.Clamp(immunityMod, 0, 1);
				}
				
				return 0;
			}
		}
		
		return player.GetTerjeStats().GetInternalImmunity();
	}
}