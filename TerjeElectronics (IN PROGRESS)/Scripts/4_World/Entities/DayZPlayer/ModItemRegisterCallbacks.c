modded class ModItemRegisterCallbacks
{
	override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
	{
		super.RegisterOneHanded(pType, pBehavior);
		
		pType.AddItemInHandsProfileIK("TerjePda_ColorBase", "TerjeElectronics/Anm/workspaces/pda_instance.asi", pBehavior, "TerjeElectronics/Anm/pda_1ik.anm");
		
		// NOT WORKING
		//pType.AddItemInHandsProfileIK("TerjeLaptop_ColorBase", "TerjeElectronics/Anm/workspaces/laptop_instance.asi", pBehavior, "TerjeElectronics/Anm/laptop_1ik.anm");
		
		// WORKING FINE
		pType.AddItemInHandsProfileIK("TerjeLaptop_ColorBase", "TerjeElectronics/Anm/workspaces/pda_instance.asi", pBehavior, "TerjeElectronics/Anm/pda_1ik.anm");
	}
	/*
	override void RegisterTwoHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
	{
		super.RegisterTwoHanded(pType, pBehavior);
		pType.AddItemInHandsProfileIK("TerjeLaptop_ColorBase", "TerjeElectronics/Anm/workspaces/laptop_instance.asi", pBehavior, "TerjeElectronics/Anm/laptop_1ik.anm");
	};
	*/
}
