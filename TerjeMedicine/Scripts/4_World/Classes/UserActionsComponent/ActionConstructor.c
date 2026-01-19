modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);
		
		actions.Insert(ActionUseSalveTarget);
		actions.Insert(ActionUseSalveSelf);
		
		actions.Insert(ActionInjectSyringeTarget);
		actions.Insert(ActionInjectSyringeSelf);
		actions.Insert(ActionEmptySyringe);
		
		actions.Insert(ActionRebandageSelf);
		actions.Insert(ActionRebandageTarget);
		
		actions.Insert(ActionSurgeryVisceraSelf);
		actions.Insert(ActionSurgeryVisceraTarget);
		
		actions.Insert(ActionSurgeryBulletSelf);
		actions.Insert(ActionSurgeryBulletTarget);
		
		actions.Insert(ActionSurgeryStubSelf);
		actions.Insert(ActionSurgeryStubTarget);
		
		actions.Insert(ActionDisinfectSutureSelf);
		actions.Insert(ActionDisinfectSutureTarget);
		
		actions.Insert(ActionDisinfectBandagedWoundSelf);
		actions.Insert(ActionDisinfectBandagedWoundTarget);
		
		actions.Insert(ActionStethoscopeInspect);
		actions.Insert(ActionUseTerjeSleepingBag);
		actions.Insert(ActionPackTerjeSleepingBag);
		actions.Insert(ActionTerjeExpressTestAgents);
		
		actions.Insert(ActionTerjeExpressTestVirusZSelf);
		actions.Insert(ActionTerjeExpressTestSepsisSelf);
		actions.Insert(ActionTerjeExpressTestRabiesSelf);
		actions.Insert(ActionTerjeExpressTestVirusZTarget);
		actions.Insert(ActionTerjeExpressTestSepsisTarget);
		actions.Insert(ActionTerjeExpressTestRabiesTarget);
		
		actions.Insert(ActionTerjeBodyDrag);
	}
}