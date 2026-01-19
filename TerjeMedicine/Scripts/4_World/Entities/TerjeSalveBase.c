class TerjeSalveBase : Inventory_Base
{
	override void InitItemVariables()
	{
		super.InitItemVariables();
		can_this_be_combined = true;
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionUseSalveTarget);
		AddAction(ActionUseSalveSelf);
	}
}