modded class ActionDigWorms
{
	override void OnFinishProgressServer(ActionData action_data)
	{	
		super.OnFinishProgressServer(action_data);
		
		ItemBase worms;
		float perkValue;
		int count = action_data.m_MainItem.GetOnDigWormsAmount();
		if (action_data.m_Player && action_data.m_Player.GetTerjeSkills() && action_data.m_Player.GetTerjeSkills().GetPerkValue("fish", "wormhunt", perkValue))
		{
			count = (int)Math.Round((float)count * perkValue);
			for (int i = 0; i < count; i++)
			{
				Class.CastTo(worms,  GetGame().CreateObjectEx("Worm", action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
			}
		}
	}
}