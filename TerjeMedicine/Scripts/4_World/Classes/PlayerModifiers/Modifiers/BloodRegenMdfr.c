modded class BloodRegenMdfr
{
	override float GetRegenModifierEnergy(float energy)
	{
		float result = super.GetRegenModifierEnergy(energy);
		
		float bloodRegenCommonModifier = 1;
		if (GetTerjeSettingFloat(TerjeSettingsCollection.MEDICINE_BLOOD_REGEN_COMMON_MODIFIER, bloodRegenCommonModifier))
		{
			result *= bloodRegenCommonModifier;
		}
		
		if (m_Player.GetTerjeSkills())
		{
			float perkBloodregMod;
			if (m_Player.GetTerjeSkills().GetPerkValue("immunity", "bloodreg", perkBloodregMod))
			{
				result *= 1.0 + perkBloodregMod;
			}
		}
		
		return result;
	}
}
