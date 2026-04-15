class ActionSendInviteCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(3);
	}
};

class ActionSendInvite: ActionContinuousBase
{
	void ActionSendInvite()
	{
		m_CallbackClass = ActionSendInviteCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_VIEWNOTE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ALL;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
		m_Text = "#terjeparty_sendinvite";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		PlayerBase ntarget = PlayerBase.Cast( target.GetObject() );
		if ( ntarget && ntarget.IsAlive() && ntarget.GetIdentity() && !ntarget.IsUnconscious() && !ntarget.IsRestrained() )
		{
			if (g_Game.IsServer())
			{
				return true;
			}
			
			PluginTerjeParty partyModule = GetTerjeParty();
			if (partyModule)
			{
				return partyModule.IsReadyToSendInvite(ntarget.GetIdentity().GetId());
			}
		}
		
		return false;
	}
	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTMan(UAMaxDistances.DEFAULT);
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		if (action_data.m_Target && action_data.m_Target.GetObject())
		{
			PlayerBase targetPlayer = PlayerBase.Cast(action_data.m_Target.GetObject());
			if (targetPlayer && targetPlayer.IsAlive() && targetPlayer.GetIdentity())
			{
				GetRPCManager().SendRPC("TerjePartyMod", "OnSendInvite", new Param1<string>(action_data.m_Player.GetIdentity().GetId()), true, targetPlayer.GetIdentity()); 
			}
		}
	}
};
