class TerjePillsBase extends Edible_Base
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionForceConsumeSingle);
		AddAction(ActionEatTabletFromWrapper);
	}
}