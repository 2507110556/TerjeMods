modded class BloodRegenMdfr
{
	override float GetRegenModifierEnergy(float energy)
	{
		float result = super.GetRegenModifierEnergy(energy);
		
		float bloodRegenCommonModifier = 1;
		if (GetTerjeSettingFloat(TerjeSettingsCollection.MEDICINE_BLOOD_REGEN_COMMON_MODIFIER, bloodRegenCommonModifier))
		{
			result = result * bloodRegenCommonModifier;
		}
		
		float perkBloodregMod;
		if (m_Player.GetTerjeSkills() && m_Player.GetTerjeSkills().GetPerkValue("immunity", "bloodreg", perkBloodregMod))
		{
			result = result * (1.0 + perkBloodregMod);
		}
		
		return result;
	}
}
