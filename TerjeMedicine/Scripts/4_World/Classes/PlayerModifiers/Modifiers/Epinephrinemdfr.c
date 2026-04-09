modded class EpinephrineMdfr: ModifierBase
{
	override protected bool ActivateCondition(PlayerBase player)
	{
		if (g_Game && g_Game.IsDedicatedServer() && GetTerjeSettingBool(TerjeSettingsCollection.MEDICINE_ADRENALIN_ENABLED) == false)
		{
			return super.ActivateCondition(player);
		}
		
		return false;
	}
	
	override protected bool DeactivateCondition(PlayerBase player)
	{
		if (g_Game && g_Game.IsDedicatedServer() && GetTerjeSettingBool(TerjeSettingsCollection.MEDICINE_ADRENALIN_ENABLED) == false)
		{
			return super.DeactivateCondition(player);
		}
		
		return false;
	}
	
	override protected void OnActivate(PlayerBase player)
	{
		if (g_Game && g_Game.IsDedicatedServer() && GetTerjeSettingBool(TerjeSettingsCollection.MEDICINE_ADRENALIN_ENABLED) == false)
		{
			super.OnActivate(player);
		}
	}

	override protected void OnDeactivate(PlayerBase player)
	{
		if (g_Game && g_Game.IsDedicatedServer() && GetTerjeSettingBool(TerjeSettingsCollection.MEDICINE_ADRENALIN_ENABLED) == false)
		{
			super.OnDeactivate(player);
		}
	}
}
