modded class IngameHud
{
	private ref Widget m_PartyHUD3D;
	private ref map<int, ref Widget> m_PartyPins3D;
	private bool m_isConfigRequested = false;
	
	override void Update( float timeslice )
	{
		super.Update(timeslice);

		if (!m_isConfigRequested)
		{
			m_isConfigRequested = true;
			GetRPCManager().SendRPC("TerjePartyMod", "RequestConfig", new Param1<int>(0), true);
		}
		
		if (m_PartyHUD3D)
		{
			PlayerBase myLocalPlayer = PlayerBase.Cast(g_Game.GetPlayer());
			if (myLocalPlayer && myLocalPlayer.IsAlive())
			{				
				array<int> idsToDetele();
				foreach (int localId1, ref Widget pinWidget1 : m_PartyPins3D) 
				{
					if (!PlayerBase.m_terjepartyPartyInfo.Contains(localId1) && pinWidget1)
					{
						m_PartyHUD3D.RemoveChild(pinWidget1);
						idsToDetele.Insert(localId1);
					}
				}
				
				foreach (int removeId : idsToDetele)
				{
					m_PartyPins3D.Remove(removeId);
				}
				
				PluginTerjeParty partyModule = GetTerjeParty();
				if (partyModule && partyModule.IsShowOnHUD())
				{
					float maxVisiblePos = 1000;
					vector myLocalPos = myLocalPlayer.GetWorldPosition();
					foreach (int localId2, PlayerBase localPlayer : PlayerBase.m_terjepartyPartyInfo)
					{
						ref Widget pinWidget2;
						if (!m_PartyPins3D.Find(localId2, pinWidget2))
						{
							pinWidget2 = g_Game.GetWorkspace().CreateWidgets("TerjePartyMod/Layout/party_pin_3d.layout", m_PartyHUD3D);
							pinWidget2.Show(false);
							m_PartyPins3D.Insert(localId2, pinWidget2);
						}
						
						if (pinWidget2 && localPlayer)
						{		
							if (myLocalPlayer != localPlayer)
							{
								if (localPlayer.GetIdentity() && partyModule.ContainsPlayerInParty(localPlayer.GetIdentity().GetId()))
								{
									vector worldPos;
									MiscGameplayFunctions.GetHeadBonePos(localPlayer, worldPos);
									worldPos[1] = worldPos[1] + 0.25;
									
									vector screenPos = g_Game.GetScreenPos(worldPos);
									vector localPos = localPlayer.GetWorldPosition();
									if ((screenPos[0] > 0) && (screenPos[1] > 0) && (screenPos[2] > 0.5) && vector.Distance(localPos, myLocalPos) < maxVisiblePos)
									{
										pinWidget2.SetScreenPos(screenPos[0], screenPos[1]);
										pinWidget2.FindAnyWidget("PinImage").SetColor(localPlayer.GetTerjePartyPinColor());
										pinWidget2.Show(true);
									}
									else
									{
										pinWidget2.Show(false);
									}
								}
								else
								{
									pinWidget2.Show(false);
								}
							}
							else
							{
								pinWidget2.Show(false);
							}
						}
					}
				}
			}
			else
			{
				foreach (int localId3, ref Widget pinWidget3 : m_PartyPins3D) 
				{
					if (pinWidget3)
					{
						m_PartyHUD3D.RemoveChild(pinWidget3);
					}
				}
				
				m_PartyPins3D.Clear();
			}
		}
		else
		{
			m_PartyPins3D = new map<int, ref Widget>();
			m_PartyHUD3D = g_Game.GetWorkspace().CreateWidgets("TerjePartyMod/Layout/party_hood_3d.layout", m_HudPanelWidget);
		}
	}
	
	override void RefreshHudVisibility()
	{
		super.RefreshHudVisibility();
			
		if (m_PartyHUD3D)
		{
			m_PartyHUD3D.Show(m_IsHudVisible);
		}
	}
};