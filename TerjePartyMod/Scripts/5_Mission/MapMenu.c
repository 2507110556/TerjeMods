modded class MapMenu
{
	override void Update(float timeslice)
	{
		super.Update(timeslice);
		
		MissionGameplay missionGameplay = MissionGameplay.Cast(g_Game.GetMission());
		if (missionGameplay)
		{
			m_MapWidgetInstance.ClearUserMarks();
			missionGameplay.TerjePartyMapWidgetFill(m_MapWidgetInstance, true);
		}
	}
};