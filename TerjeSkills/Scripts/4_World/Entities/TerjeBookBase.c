modded class TerjeBookBase
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTerjeReadSkillbook);
	}
	
	override bool DescriptionOverride(out string output)
	{
		if (ConfigIsExisting("terjeSkillId"))
		{
			ref TerjeSkillCfg skillCfg;
			string skillId = GetTerjeGameConfig().ConfigGetStringRaw("CfgVehicles " + GetType() + " terjeSkillId");
			int skillExpGain = GetTerjeGameConfig().ConfigGetInt("CfgVehicles " + GetType() + " terjeSkillExpGain");
			int skillMinLevel = GetTerjeGameConfig().ConfigGetInt("CfgVehicles " + GetType() + " terjeSkillMinLevel");
			int skillMaxLevel = GetTerjeGameConfig().ConfigGetInt("CfgVehicles " + GetType() + " terjeSkillMaxLevel");
			if (GetTerjeSkillsRegistry().FindSkill(skillId, skillCfg) && skillExpGain > 0 && skillMaxLevel > 0)
			{
				output = skillCfg.GetDisplayName() + ": <color rgba='97,215,124,255'>+" + skillExpGain + "</color> #STR_TERJESKILL_MISC2 (#STR_TERJESKILL_MISC1: <color rgba='0,148,255,255'>" + skillMinLevel + "-" + skillMaxLevel + "</color>)";
				return true;
			}
		}
		
		return super.DescriptionOverride(output);
	}
}