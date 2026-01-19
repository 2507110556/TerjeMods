class TerjeFirstAidKitIndividualBase : Container_Base
{
	override bool CanReceiveItemIntoCargo( EntityAI item )
	{
		if (!super.CanReceiveItemIntoCargo(item))
			return false;
		
		return item && GetTerjeGameConfig().ConfigGetBool("CfgVehicles " + item.GetType() + " medicalItem");
	}
	
	override bool CanLoadItemIntoCargo( EntityAI item )
	{
		if (!super.CanLoadItemIntoCargo(item))
			return false;
		
		return item && GetTerjeGameConfig().ConfigGetBool("CfgVehicles " + item.GetType() + " medicalItem");
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionSewTarget);
		AddAction(ActionSewSelf);
		AddAction(ActionBandageTarget);
		AddAction(ActionBandageSelf);
	}
	
	override float GetBandagingEffectivity()
	{
		return 3.0;
	}
	
	override bool CanBeDisinfected()
	{
		return true;
	}

	override float GetInfectionChance(int system = 0, Param param = null)
	{
		if(m_Cleanness == 1)
		{
			return 0;
		}
		else
		{
			return 0.2;
		}
	}
}
