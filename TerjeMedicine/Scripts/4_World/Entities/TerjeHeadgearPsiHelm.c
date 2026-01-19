class TerjeHeadgearPsiHelm : Clothing
{
	override float GetTerjeProtectionLevel(string protectionType)
	{
		if (GetCompEM().IsWorking())
		{
			return super.GetTerjeProtectionLevel(protectionType);
		}
		
		return 0;
	}
	
	override float GetTerjeProtectionAdvanced(string protectionType, float power)
	{
		if (GetCompEM().IsWorking())
		{
			return super.GetTerjeProtectionAdvanced(protectionType, power);
		}
		
		return 0;
	}
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTurnOnWhileInHands);
		AddAction(ActionTurnOffWhileInHands);
	}
}