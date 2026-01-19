class TerjeAmpouleBase : Inventory_Base
{
	override void InitItemVariables()
	{
		super.InitItemVariables();
		can_this_be_combined = true;
	}
}

class TerjeAmpouleAlcohol : TerjeAmpouleBase
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionDisinfectTarget);
		AddAction(ActionDisinfectSelf);
		AddAction(ActionWashHandsItemContinuous);
	}
	
	override float GetDisinfectQuantity(int system = 0, Param param1 = null)
	{
		return 1;
	}
	
	override int GetLiquidType()
	{
		return LIQUID_DISINFECTANT;
	}
}