modded class HungerMdfr
{
	override protected float GetTerjeMetabolicSpeedModifier(PlayerBase player, float deltaT, float energy)
	{
		float metabolicSpeedEnergyModifier = 1;
		GetTerjeSettingFloat(TerjeSettingsCollection.MEDICINE_METABOLIC_SPEED_ENERGY_MODIFIER, metabolicSpeedEnergyModifier);
		return super.GetTerjeMetabolicSpeedModifier(player, deltaT, energy) * metabolicSpeedEnergyModifier;
	}
	
	override protected float GetTerjeHealthDammageModifier(PlayerBase player, float deltaT, float energy)
	{
		float energyLowDamageModifier = 1;
		GetTerjeSettingFloat(TerjeSettingsCollection.MEDICINE_ENERGY_LOW_DAMAGE_MODIFIER, energyLowDamageModifier);
		return super.GetTerjeHealthDammageModifier(player, deltaT, energy) * energyLowDamageModifier;
	}
}
