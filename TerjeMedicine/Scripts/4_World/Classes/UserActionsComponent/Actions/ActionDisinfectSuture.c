class ActionDisinfectSutureSelf: ActionDisinfectBase
{
	void ActionDisinfectSutureSelf()
	{
		m_CallbackClass = ActionDisinfectSelfCB;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_STITCHUPSELF;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_Text = "#STR_TERJEMED_DISINFECTSUTURE_SELF";
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTSelf;
	}

	override bool HasTarget()
	{
		return false;
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		return player.HasTerjeSuturesDirtySelf();
	}
	

	override void OnFinishProgressServer( ActionData action_data )
	{
		PlayerBase target = PlayerBase.Cast(action_data.m_Player);
		if (action_data.m_MainItem && target)
		{
			if (target.GetTerjeStats().GetSuturesDirty() > 0)
			{
				target.GetTerjeStats().SetSuturesDirty(target.GetTerjeStats().GetSuturesDirty() - 1);
				target.GetTerjeStats().SetSuturesClean(target.GetTerjeStats().GetSuturesClean() + 1);
			}
		}
		
		Apply(action_data);
	}
}

class ActionDisinfectSutureTarget: ActionDisinfectBase
{	
	void ActionDisinfectSutureTarget()
	{
		m_CallbackClass = ActionDisinfectSelfCB;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_Text = "#STR_TERJEMED_DISINFECTSUTURE_TARGET";
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTMan(UAMaxDistances.DEFAULT);
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if (target)
		{
			PlayerBase target_player = PlayerBase.Cast(target.GetObject());
			if (target_player)
			{
				return target_player.HasTerjeSuturesDirty();
			}
			
		}
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{	
		PlayerBase target = PlayerBase.Cast(action_data.m_Target.GetObject());
		
		if ( target )
		{
			if (CanReceiveAction(action_data.m_Target))
			{
				if (target.GetTerjeStats().GetSuturesDirty() > 0)
				{
					target.GetTerjeStats().SetSuturesDirty(target.GetTerjeStats().GetSuturesDirty() - 1);
					target.GetTerjeStats().SetSuturesClean(target.GetTerjeStats().GetSuturesClean() + 1);
				}
				
				Apply(action_data);
			}
		}
	}
}