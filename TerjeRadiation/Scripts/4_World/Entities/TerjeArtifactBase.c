class TerjeArtifactBase extends ItemBase
{
	protected PointLightBase m_terjeArtIdleLight = null;
	protected Particle m_terjeArtEffectIdle = null;
	
	override void EEInit()
	{
		super.EEInit();
		
		if (g_Game && g_Game.IsClient())
		{
			InventoryLocation location = new InventoryLocation;
			GetInventory().GetCurrentInventoryLocation(location);
			if(location.GetType() == InventoryLocationType.GROUND || location.GetType() == InventoryLocationType.HANDS)
			{
				StartEffects();
			}
		}
	}
	
	override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);
		
		if(g_Game && g_Game.IsClient())
		{
			StopEffects();
		}
	}
	
	
	override void EEItemLocationChanged(notnull InventoryLocation oldLoc, notnull InventoryLocation newLoc)
	{
		super.EEItemLocationChanged(oldLoc, newLoc);
		
		if(g_Game && g_Game.IsClient())
		{
			if(newLoc.GetType() == InventoryLocationType.GROUND || newLoc.GetType() == InventoryLocationType.HANDS)
			{
				StartEffects();
			}
			else
			{
				StopEffects();
			}
		}
	}
	
	protected void StartEffects()
	{
		
	}
	
	protected void StopEffects()
	{
		if (m_terjeArtIdleLight != null)
		{
			m_terjeArtIdleLight.FadeOut();
			m_terjeArtIdleLight = null;
		}
		
		if (m_terjeArtEffectIdle != null)
		{
			m_terjeArtEffectIdle.StopParticle();
			m_terjeArtEffectIdle = null;
		}
	}
};