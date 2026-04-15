modded class PlayerBase
{
	private int m_terjepartyLocalId = 0;
	static int m_terjepartyNextLocalID = 0;
	static ref map<int, PlayerBase> m_terjepartyPartyInfo = new map<int, PlayerBase>();
	
	override void EEInit()
	{
		super.EEInit();
		
		if (g_Game.IsClient())
		{
			m_terjepartyLocalId = m_terjepartyNextLocalID;
			m_terjepartyNextLocalID = m_terjepartyNextLocalID + 1;
			m_terjepartyPartyInfo.Insert(m_terjepartyLocalId, this);
		}
	}
	
	override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);
		
		if (g_Game.IsClient())
		{
			m_terjepartyPartyInfo.Remove(m_terjepartyLocalId);
		}
	}
	
	override void EEKilled(Object killer)
	{
		super.EEKilled(killer);
		
		if (g_Game.IsServer())
		{
			EntityAI killerAI;
			if (EntityAI.CastTo(killerAI, killer))
			{
				PlayerBase otherPlayer = PlayerBase.Cast(killerAI.GetHierarchyRootPlayer());
				if (this.GetIdentity() && otherPlayer && this != otherPlayer && otherPlayer.GetIdentity())
				{
					GetRPCManager().SendRPC("TerjePartyMod", "OnRemoveFromParty", new Param1<string>(this.GetIdentity().GetId()), true, otherPlayer.GetIdentity());
					GetRPCManager().SendRPC("TerjePartyMod", "OnRemoveFromParty", new Param1<string>(otherPlayer.GetIdentity().GetId()), true, this.GetIdentity()); 
				}
			}
		}
	}
	
	override void SetActionsRemoteTarget(out TInputActionMap InputActionMap)
	{
		super.SetActionsRemoteTarget(InputActionMap);
		
		AddAction(ActionSendInvite, InputActionMap);
		AddAction(ActionAcceptInvite, InputActionMap);
		AddAction(ActionRemoveFromFriends, InputActionMap);
	}
	
	int GetTerjePartyPinColor()
	{
		if (IsAlive())
		{
			if (m_HealthLevel == eInjuryHandlerLevels.PRISTINE)
			{
				return 0xFF009938;
			}
			if (m_HealthLevel == eInjuryHandlerLevels.WORN)
			{
				return 0xFF719938;
			}
			if (m_HealthLevel == eInjuryHandlerLevels.DAMAGED)
			{
				return 0xFFE19938;
			}
			if (m_HealthLevel == eInjuryHandlerLevels.BADLY_DAMAGED)
			{
				return 0xFFC64B3D;
			}
			if (m_HealthLevel == eInjuryHandlerLevels.RUINED)
			{
				return 0xFF720B00;
			}
		}
		
		return 0xFF212121;
	}
}