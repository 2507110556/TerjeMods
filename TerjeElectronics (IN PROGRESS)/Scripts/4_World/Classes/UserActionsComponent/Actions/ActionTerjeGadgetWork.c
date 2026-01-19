class ActionTerjeGadgetWorkCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(40);
	}
};

class ActionTerjeGadgetWork: ActionContinuousBase
{

	void ActionTerjeGadgetWork()
	{
		m_CallbackClass = ActionTerjeGadgetWorkCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_TAKETEMPSELF;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_TAKETEMPSELF;	
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
		
	}
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTSelf;
	}
	
	override bool HasProneException()
	{
		return true;
	}
	
	override bool HasTarget()
	{
		return false;
	}
		
	override string GetText()
	{
		return "Пробное включение";
	}


	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		return true;
	}
};