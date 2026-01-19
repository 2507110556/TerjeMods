class TerjeExpressTestVirusZ extends Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionTerjeExpressTestVirusZSelf);
		AddAction(ActionTerjeExpressTestVirusZTarget);
	}
}

class TerjeExpressTestSepsis extends Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionTerjeExpressTestSepsisSelf);
		AddAction(ActionTerjeExpressTestSepsisTarget);
	}
}

class TerjeExpressTestRabies extends Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionTerjeExpressTestRabiesSelf);
		AddAction(ActionTerjeExpressTestRabiesTarget);
	}
}