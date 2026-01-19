class TerjeSurgicalKit extends Inventory_Base
{
	override void InitItemVariables()
	{
		super.InitItemVariables();
		can_this_be_combined = true;
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionSewTarget);
		AddAction(ActionSewSelf);
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
			return 0.4;
		}
	}
}

modded class SewingKit
{
	override float GetInfectionChance(int system = 0, Param param = null)
	{
		if(m_Cleanness == 1)
		{
			return 0;
		}
		else
		{
			return 0.8;
		}
	}
}