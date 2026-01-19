class TerjeInjectorBase: Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionInjectTarget);
		AddAction(ActionInjectSelf);
	}
	
	override void OnApply(PlayerBase player)
	{
		if (!player)
			return;
		
		ApplyTerjeConsumableEffects(player, 1);
	}
}
