modded class Defibrillator
{
	override void DischargeServer(PlayerBase victim)
	{
		if (GetTerjeSettingBool(TerjeSettingsCollection.MEDICINE_KNOCKOUT_REVIVE_BY_DEF))
		{
			PlayerBase operator = PlayerBase.Cast(this.GetHierarchyRootPlayer());
			if (TerjeDefibrilateKnockoutServer(victim, operator))
			{
				return;
			}
		}
		
		super.DischargeServer(victim);
	}
	
	bool TerjeDefibrilateKnockoutServer(PlayerBase victim, PlayerBase operator)
	{
		if (victim && victim.GetTerjeHealth() && victim.GetTerjeStats() && victim.GetTerjeStats().IsInKnockout())
		{
			if (victim.GetTerjeHealth().GetHealth() < PlayerConstants.SL_HEALTH_LOW)
			{
				victim.GetTerjeHealth().SetHealth(PlayerConstants.SL_HEALTH_LOW, TerjeDamageSource.COMA);
			}
			
			if (victim.GetTerjeHealth().GetBlood() < PlayerConstants.SL_BLOOD_LOW)
			{
				victim.GetTerjeHealth().SetBlood(PlayerConstants.SL_BLOOD_LOW, TerjeDamageSource.COMA);
			}
			
			victim.GiveShock(100);
			return true;
		}
		
		return false;
	}
}