modded class Environment
{
	override protected float GetPlayerHeat()
	{
		float result = super.GetPlayerHeat();
		
		if (m_Player && m_Player.IsAlive() && m_Player.GetTerjeStats())
		{
			int influenzaLevel = m_Player.GetTerjeStats().GetInfluenzaLevel();
			if (influenzaLevel > 0)
			{
				float influenzaBodyTemperatureModifier = 0;
				if (GetTerjeSettingFloat(TerjeSettingsCollection.MEDICINE_INFLUENZA_BODY_TEMPERATURE_MODIFIER, influenzaBodyTemperatureModifier))
				{
					result = result + (influenzaLevel * influenzaBodyTemperatureModifier);
				}
			}
			
			int rabiesLevel = m_Player.GetTerjeStats().GetRabiesLevel();
			if (rabiesLevel > 0)
			{
				float rabiesBodyTemperatureModifier = 0;
				if (GetTerjeSettingFloat(TerjeSettingsCollection.MEDICINE_RABIES_BODY_TEMPERATURE_MODIFIER, rabiesBodyTemperatureModifier))
				{
					result = result + (rabiesLevel * rabiesBodyTemperatureModifier);
				}
			}
		}
		
		return result;
	}
}
