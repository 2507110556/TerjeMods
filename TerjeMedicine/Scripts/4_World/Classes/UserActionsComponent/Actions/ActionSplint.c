modded class ActionSplintSelf	
{
	override void OnFinishProgressServer( ActionData action_data )
	{
		super.OnFinishProgressServer(action_data);
		
		PlayerBase operator = PlayerBase.Cast(action_data.m_Player);
		if (operator && operator.GetTerjeSkills())
		{
			int skillIncrement = GetTerjeSettingInt(TerjeSettingsCollection.MEDICINE_MEDICINE_SPLINT_EXP_GAIN);
			if (skillIncrement > 0)
			{
				operator.GetTerjeSkills().AddSkillExperience("med", (int)skillIncrement);
			}
		}
	}
}

modded class ActionSplintTarget
{
	override void OnFinishProgressServer( ActionData action_data )
	{
		super.OnFinishProgressServer(action_data);
		
		PlayerBase operator = PlayerBase.Cast(action_data.m_Player);
		if (operator && operator.GetTerjeSkills())
		{
			int skillIncrement = GetTerjeSettingInt(TerjeSettingsCollection.MEDICINE_MEDICINE_SPLINT_EXP_GAIN);
			if (skillIncrement > 0)
			{
				operator.GetTerjeSkills().AddSkillExperience("med", (int)skillIncrement);
			}
		}
	}
}