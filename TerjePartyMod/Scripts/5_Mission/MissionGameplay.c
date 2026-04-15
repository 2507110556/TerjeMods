modded class MissionGameplay
{
	private ref UIScriptedMenu m_lastScriptedMenu = null;
	private ref set<ref MapWidget> m_mapsCache = new set<ref MapWidget>;
		
	override void OnUpdate(float timeslice)
	{	
		super.OnUpdate(timeslice);
		
		PluginTerjeParty partyModule = GetTerjeParty();
		if (partyModule && partyModule.IsShowOnMap())
		{
			UIScriptedMenu currentMenu = UIScriptedMenu.Cast(g_Game.GetUIManager().GetMenu());
			if (currentMenu)
			{
				if (currentMenu != m_lastScriptedMenu)
				{
					m_lastScriptedMenu = currentMenu;
					if (!currentMenu.IsInherited(MapMenu))
					{
						TerjePartyFindAndModifyMapWidget(currentMenu.GetLayoutRoot());
					}
				}
			}
			else
			{
				TerjePartyClearMapsCache();
				m_lastScriptedMenu = null;
			}
		}
	}
	
	private void TerjePartyClearMapsCache()
	{
		if (m_mapsCache.Count() > 0)
		{
			foreach (ref MapWidget mwid : m_mapsCache)
			{
				if (mwid)
				{
					mwid.ClearUserMarks();
				}
			}
			
			m_mapsCache.Clear();
		}
	}
	
	private void TerjePartyFindAndModifyMapWidget(Widget wid)
	{
		if (wid)
		{
			if (wid.IsInherited(MapWidget))
			{
				TerjePartyMapWidgetFill(MapWidget.Cast(wid), false);
				return;
			}
			
			Widget child = wid.GetChildren();
			while (child)
			{
				TerjePartyFindAndModifyMapWidget(child);
				child = child.GetSibling();
			}
		}
	}
	
	void TerjePartyMapWidgetFill(MapWidget mwid, bool ignoreMapsCache)
	{
		if (!ignoreMapsCache)
		{
			if (m_mapsCache.Find(mwid) != -1)
			{
				return;
			}
			
			m_mapsCache.Insert(mwid);
		}
		
		PlayerBase myLocalPlayer = PlayerBase.Cast(g_Game.GetPlayer());
		if (myLocalPlayer && myLocalPlayer.IsAlive())
		{	
			PluginTerjeParty partyModule = GetTerjeParty();
			if (partyModule && partyModule.IsShowOnMap())
			{
				foreach (int localId2, PlayerBase localPlayer : PlayerBase.m_terjepartyPartyInfo)
				{
					if (localPlayer && localPlayer.GetIdentity() && myLocalPlayer != localPlayer)
					{
						vector worldPos = localPlayer.GetWorldPosition();
						if (partyModule.ContainsPlayerInParty(localPlayer.GetIdentity().GetId()))
						{
							mwid.AddUserMark(worldPos, localPlayer.GetIdentity().GetName(), localPlayer.GetTerjePartyPinColor(), "TerjePartyMod\\Data\\MapPin.paa");
						}
					}
				}
			}
		}
	}
};