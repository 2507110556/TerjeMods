class TerjePda_ColorBase : TerjeGadgetBase
{
	override void OnDebugSpawn()
	{
		Battery9V.Cast(GetInventory().CreateInInventory("Battery9V"));
	}

	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTerjeGadgetWork);
	}
	
	override float GetAvailablePower()
	{
		EntityAI battery = GetInventory().FindAttachmentByName("BatteryD");
		if (battery)
		{
			return battery.GetQuantityNormalized();
		}
		
		return 0;
	}
}
