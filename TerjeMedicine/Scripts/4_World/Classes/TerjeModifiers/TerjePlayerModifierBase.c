modded class TerjePlayerModifierBase
{
	override float GetPlayerImmunity(PlayerBase player)
	{
		if (player.GetTerjeSkills() && player.GetTerjeSkills().IsPerkRegistered("immunity", "resdiseasesmod"))
		{
			float immunityMod;
			if (player.GetTerjeSkills().GetSkillModifierValue("immunity", "resdiseasesmod", immunityMod))
			{
				return Math.Clamp(immunityMod, 0.0, 1.0);
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return player.GetTerjeStats().GetInternalImmunity();
		}
	}
}