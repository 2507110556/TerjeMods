modded class ActionSkinning
{
	override void HandlePlayerBody(ActionData action_data)
	{
		super.HandlePlayerBody(action_data);
		
		PlayerBase body;
		if (Class.CastTo(body, action_data.m_Target.GetObject()))
		{
			if (action_data.m_Player && action_data.m_Player.GetTerjeStats())
			{
				float mindDegValue = GetTerjeSettingFloat(TerjeSettingsCollection.MEDICINE_PLAYER_SKINNING_MIND_DEG_VALUE);
				float mindDegTime = GetTerjeSettingFloat(TerjeSettingsCollection.MEDICINE_PLAYER_SKINNING_MIND_DEG_TIME);
				action_data.m_Player.GetTerjeStats().AddMindDegradation(mindDegValue, mindDegTime);
			}
		}
	}
}