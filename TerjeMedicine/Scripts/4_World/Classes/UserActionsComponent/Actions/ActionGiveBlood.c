modded class ActionGiveBloodSelf
{
	override void OnFinishProgressServer( ActionData action_data )
	{
		super.OnFinishProgressServer(action_data);
		
		PlayerBase operator = PlayerBase.Cast(action_data.m_Player);
		if (operator && operator.GetTerjeSkills())
		{
			int skillIncrement = GetTerjeSettingInt(TerjeSettingsCollection.MEDICINE_MEDICINE_GIVE_BLOOD_EXP_GAIN);
			if (skillIncrement > 0)
			{
				operator.GetTerjeSkills().AddSkillExperience("med", (int)skillIncrement);
			}
		}
	}
}

modded class ActionGiveBloodTarget
{
	override void OnFinishProgressServer( ActionData action_data )
	{
		super.OnFinishProgressServer(action_data);
		
		PlayerBase operator = PlayerBase.Cast(action_data.m_Player);
		if (operator && operator.GetTerjeSkills())
		{
			int skillIncrement = GetTerjeSettingInt(TerjeSettingsCollection.MEDICINE_MEDICINE_GIVE_BLOOD_EXP_GAIN);
			if (skillIncrement > 0)
			{
				operator.GetTerjeSkills().AddSkillExperience("med", (int)skillIncrement);
			}
		}
	}
}