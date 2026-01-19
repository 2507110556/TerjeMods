class TerjeSyringeEmpty extends Inventory_Base
{
	override bool CanBeDisinfected()
	{
		return true;
	}
	
	string GetTerjeSyringeClassnameFull()
	{
		return "TerjeSyringeFull";
	}
}

class TerjeImprovisedSyringeEmpty : TerjeSyringeEmpty
{
	override string GetTerjeSyringeClassnameFull()
	{
		return "TerjeImprovisedSyringeFull";
	}
}