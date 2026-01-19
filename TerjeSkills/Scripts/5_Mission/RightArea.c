modded class RightArea
{
	protected ref TerjeSkillsContainer m_terjeSkillsContainer = null;
	
	override void Refresh()
	{
		super.Refresh();
		
		if (m_terjeSkillsContainer != null)
		{
			m_terjeSkillsContainer.Refresh();
		}
	}
	
	override void UpdateInterval()
	{
		super.UpdateInterval();
		
		if (m_terjeSkillsContainer != null)
		{
			m_terjeSkillsContainer.UpdateInterval();
		}
		else if (m_terjeSkillsContainer == null && GetTerjeSkillsRegistry().IsReadyToDisplay())
		{
			PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
			if (player)
			{
				m_terjeSkillsContainer = new TerjeSkillsContainer(this);
				m_terjeSkillsContainer.InitializeSkills(player);
				m_Body.Insert( m_terjeSkillsContainer );
				RecomputeOpenedContainers();
			}
		}
	}
}