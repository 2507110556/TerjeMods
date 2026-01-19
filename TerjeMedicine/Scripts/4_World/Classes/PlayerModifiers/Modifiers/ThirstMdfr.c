modded class ThirstMdfr
{
	override protected float GetTerjeMetabolicSpeedModifier(PlayerBase player, float deltaT, float water)
	{
		float metabolicSpeedWaterModifier = 1;
		GetTerjeSettingFloat(TerjeSettingsCollection.MEDICINE_METABOLIC_SPEED_WATER_MODIFIER, metabolicSpeedWaterModifier);
		return super.GetTerjeMetabolicSpeedModifier(player, deltaT, water) * metabolicSpeedWaterModifier;
	}
	
	override protected float GetTerjeHealthDammageModifier(PlayerBase player, float deltaT, float water)
	{
		float waterLowDamageModifier = 1;
		GetTerjeSettingFloat(TerjeSettingsCollection.MEDICINE_WATER_LOW_DAMAGE_MODIFIER, waterLowDamageModifier);
		return super.GetTerjeHealthDammageModifier(player, deltaT, water) * waterLowDamageModifier;
	}
}
