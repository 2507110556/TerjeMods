class CAContinuousRepeatStethoscopeInspect : CAContinuousRepeat
{
	const float TERJE_NOTIFICATION_HIDE_TIME = 2;
	int m_terjeCurrentIndex;
	float m_terjeNotificationTime;
	
	void CAContinuousRepeatStethoscopeInspect( float time_to_complete_action )
	{
		m_terjeCurrentIndex = -1;
		m_terjeNotificationTime = Math.Max(1, time_to_complete_action - TERJE_NOTIFICATION_HIDE_TIME);
		m_DefaultTimeToComplete = time_to_complete_action;
	}
	
	override int Execute( ActionData action_data )
	{
		if (!action_data.m_Player)
		{
			return UA_ERROR;
		}
		
		TerjeStethoscopeActionData terjeActionData;
		if (!Class.CastTo(terjeActionData, action_data))
		{
			return UA_ERROR;
		}
		
		PlayerBase targetPlayer = PlayerBase.Cast( action_data.m_Target.GetObject() );
		if (!targetPlayer || !targetPlayer.IsAlive())
		{
			return UA_ERROR;
		}
		
		TerjeStethoscope itemStatoschope = TerjeStethoscope.Cast(action_data.m_Player.GetItemOnSlot("Eyewear"));
		if (!itemStatoschope || itemStatoschope.IsRuined())
		{
			return UA_ERROR;
		}
		
		if (m_TimeElpased < m_TimeToComplete)
		{
			m_TimeElpased += action_data.m_Player.GetDeltaT();
			m_TotalTimeElpased += action_data.m_Player.GetDeltaT();
		}
		else
		{
			m_terjeCurrentIndex++;
			m_TimeElpased = m_TimeToComplete - m_TimeElpased;
			OnCompletePogress(action_data);
			
			if (GetGame().IsDedicatedServer())
			{
				string notificationTitle;
				string notificationIcon;
				string notificationDesc;
				bool notificationReady = false;
				bool notificationLast = false;
				if (terjeActionData.m_terjeInspectableStats != null)
				{
					if (terjeActionData.m_terjeInspectableStats.GetCount() == 0 && m_terjeCurrentIndex == 0)
					{
						notificationTitle = "#STR_TERJEMED_PIS_FINE";
						notificationIcon = "set:dayz_gui image:iconHealth0";
						notificationDesc = "#STR_TERJEMED_PIS_FINE_DESC";
						notificationReady = true;
						notificationLast = true;
					}
					else if (terjeActionData.m_terjeInspectableStats.GetStat(m_terjeCurrentIndex, notificationTitle, notificationIcon, notificationDesc))
					{
						notificationReady = true;
						if (m_terjeCurrentIndex == terjeActionData.m_terjeInspectableStats.GetCount() - 1)
						{
							notificationLast = true;
						}
					}
				}
				else
				{
					notificationTitle = "#STR_TERJEMED_PIS_NOSKILL";
					notificationIcon = "set:TerjePerk_icon image:tp_stethoscope";
					notificationDesc = "#STR_TERJEMED_PIS_NOSKILL_DESC";
					notificationReady = true;
					notificationLast = true;
				}
				
				if (notificationReady)
				{
					NotificationSystem.SendNotificationToPlayerExtended(action_data.m_Player, m_terjeNotificationTime, notificationTitle, notificationDesc, notificationIcon);
					if (notificationLast)
					{
						return UA_ERROR;
					}
				}
				else
				{
					return UA_ERROR;
				}
			}
		}
		
		return UA_PROCESSING;
	}
}

class ActionStethoscopeInspectCB : ActionContinuousBaseCB
{
	const float TERJE_STETHOSCOPE_LOOP_TIME = 5;
	
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousRepeatStethoscopeInspect(TERJE_STETHOSCOPE_LOOP_TIME);
	}
}

class TerjeStethoscopeActionData : ActionData
{
	ref TerjePlayerInspectableStats m_terjeInspectableStats = null;
	
	void FillTerjeInspectableStats(PlayerBase player, int level)
	{
		m_terjeInspectableStats = new TerjePlayerInspectableStats(player, level);
	}
}

class ActionStethoscopeInspect: ActionContinuousBase
{
	void ActionStethoscopeInspect()
	{
		m_CallbackClass 	= ActionStethoscopeInspectCB;
		m_CommandUID 		= DayZPlayerConstants.CMD_ACTIONFB_SALINEBLOODBAGTARGET;
		m_FullBody 			= true;
		m_StanceMask 		= DayZPlayerConstants.STANCEMASK_ERECT;

		m_Text = "#STR_TERJEMED_STETHOSCOPE_USE";
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
	
	override ActionData CreateActionData()
	{
		return new TerjeStethoscopeActionData;
	}
	
	override bool SetupAction(PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = null)
	{
		if (super.SetupAction(player, target, item, action_data, extra_data))
		{
			TerjeStethoscopeActionData terjeActionData;
			if (Class.CastTo(terjeActionData, action_data))
			{
				PlayerBase targetPlayer = PlayerBase.Cast( action_data.m_Target.GetObject() );
				if (targetPlayer)
				{
					if (GetGame().IsDedicatedServer() && player && player.GetTerjeSkills())
					{
						if (player.GetTerjeSkills().IsPerkRegistered("med", "stethscp"))
						{
							int perkLevel = player.GetTerjeSkills().GetPerkLevel("med", "stethscp");
							if (perkLevel > 0)
							{
								terjeActionData.FillTerjeInspectableStats(targetPlayer, perkLevel);
							}
						}
						else
						{
							terjeActionData.FillTerjeInspectableStats(targetPlayer, 3);
						}
					}
					
					return true;
				}
			}
		}
		
		return false;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if (player.GetItemInHands())
		{
			return false;
		}

		TerjeStethoscope itemStatoschope = TerjeStethoscope.Cast(player.GetItemOnSlot("Eyewear"));
		if (!itemStatoschope || itemStatoschope.IsRuined())
		{
			return false;
		}

		PlayerBase targetPlayer = PlayerBase.Cast( target.GetObject() );
		if (!targetPlayer)
		{
			return false;
		}
		
		if (!targetPlayer.IsAlive())
		{
			return false;
		}
		
		return true;
	}
}