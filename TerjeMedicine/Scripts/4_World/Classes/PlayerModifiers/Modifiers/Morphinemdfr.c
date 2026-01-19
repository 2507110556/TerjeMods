modded class MorphineMdfr: ModifierBase
{
	override protected bool ActivateCondition(PlayerBase player)
	{
		if (GetGame() && GetGame().IsDedicatedServer() && GetTerjeSettingBool(TerjeSettingsCollection.MEDICINE_PAIN_ENABLED) == false)
		{
			return super.ActivateCondition(player);
		}
		
		return false;
	}
	
	override protected bool DeactivateCondition(PlayerBase player)
	{
		if (GetGame() && GetGame().IsDedicatedServer() && GetTerjeSettingBool(TerjeSettingsCollection.MEDICINE_PAIN_ENABLED) == false)
		{
			return super.DeactivateCondition(player);
		}
		
		return false;
	}
	
	override protected void OnActivate(PlayerBase player)
	{
		if (GetGame() && GetGame().IsDedicatedServer() && GetTerjeSettingBool(TerjeSettingsCollection.MEDICINE_PAIN_ENABLED) == false)
		{
			super.OnActivate(player);
		}
	}

	override protected void OnDeactivate(PlayerBase player)
	{
		if (GetGame() && GetGame().IsDedicatedServer() && GetTerjeSettingBool(TerjeSettingsCollection.MEDICINE_PAIN_ENABLED) == false)
		{
			super.OnDeactivate(player);
		}
	}
}