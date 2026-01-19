class ActionTerjeGadgetUse: ActionSingleUseBase
{
	void ActionTerjeGadgetUse()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENITEM_ONCE;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_OPENITEM_ONCE;
		m_Text = "#open";
	}
	
	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}

	override bool HasTarget()
	{
		return false;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		TerjeGadgetBase gadgetEntity = TerjeGadgetBase.Cast(item);
		if (gadgetEntity && gadgetEntity.CanOpenGadgetMenu())
		{
			return true;
		}
		
		return false;
	}
	
	override void OnExecuteClient( ActionData action_data )
	{
		if ((GetGame()) && (GetGame().IsClient()) && (GetGame().GetUIManager().GetMenu() == null))
		{
			typename gadgetMenuType = String("TerjeGadgetMenu").ToType();
			TerjeGadgetBase gadgetEntity = TerjeGadgetBase.Cast(action_data.m_MainItem);
			if (gadgetMenuType && gadgetEntity && gadgetEntity.CanOpenGadgetMenu())
			{
				TerjeScriptedMenu gadgetMenu = TerjeUiManager.GetInstance().ShowScriptedMenu(gadgetMenuType);
				if (gadgetMenu != null)
				{
					Param1<TerjeGadgetBase> callParams = new Param1<TerjeGadgetBase>(gadgetEntity);
					GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallByName(gadgetMenu, "SetTerjeGadget", callParams);
				}
			}
		}
	}
}