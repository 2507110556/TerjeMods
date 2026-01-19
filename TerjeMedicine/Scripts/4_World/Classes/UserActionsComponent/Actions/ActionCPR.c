modded class ActionCPR
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if (!super.ActionCondition(player, target, item))
		{
			return false;
		}
		
		if (player && player.GetTerjeSkills() && player.GetTerjeSkills().IsPerkRegistered("med", "brnlife"))
		{
			return player.GetTerjeSkills().GetPerkLevel("med", "brnlife") > 0;
		}
		
		return true;
	}
	
	override void OnFinishProgressServer(ActionData action_data)
	{
		if (GetTerjeSettingBool(TerjeSettingsCollection.MEDICINE_KNOCKOUT_REVIVE_BY_CPR))
		{
			PlayerBase operator = action_data.m_Player;
			PlayerBase victim = PlayerBase.Cast(action_data.m_Target.GetObject());
			if (!TerjeDefibrilateKnockoutServer(victim, operator))
			{
				return;
			}
		}
		else if (victim.GetTerjeStats() && victim.GetTerjeStats().IsInKnockout())
		{
			return;
		}
		
		super.OnFinishProgressServer(action_data);
	}
	
	bool TerjeDefibrilateKnockoutServer(PlayerBase victim, PlayerBase operator)
	{
		if (victim && victim.GetTerjeHealth() && victim.GetTerjeStats() && victim.GetTerjeStats().IsInKnockout())
		{
			bool isStable = true;
			if (victim.GetTerjeHealth().GetHealth() < PlayerConstants.SL_HEALTH_LOW)
			{
				victim.GetTerjeHealth().AddHealth(1);
				isStable = false;
			}
			
			if (victim.GetTerjeHealth().GetBlood() < PlayerConstants.SL_BLOOD_LOW)
			{
				victim.GetTerjeHealth().AddBlood(10);
				isStable = false;
			}
			
			return isStable;
		}
		
		return true;
	}
}