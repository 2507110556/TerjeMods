modded class ZombieBase
{
	override void EEKilled(Object killer)
	{
		super.EEKilled(killer);
				
		EntityAI entityKiller = EntityAI.Cast(killer);
		if (entityKiller)
		{
			PlayerBase killerPlayer = PlayerBase.Cast(entityKiller.GetHierarchyRootPlayer());
			if (killerPlayer && killerPlayer.GetTerjeStats())
			{
				float safeDist = GetTerjeSettingFloat(TerjeSettingsCollection.MEDICINE_ZOMBIE_KILLING_MIND_DEG_SAFEDIST);
				if (vector.Distance(killerPlayer.GetWorldPosition(), this.GetWorldPosition()) < safeDist)
				{
					float mindDegValue = GetTerjeSettingFloat(TerjeSettingsCollection.MEDICINE_ZOMBIE_KILLING_MIND_DEG_VALUE);
					float mindDegTime = GetTerjeSettingFloat(TerjeSettingsCollection.MEDICINE_ZOMBIE_KILLING_MIND_DEG_TIME);
					killerPlayer.GetTerjeStats().AddMindDegradation(mindDegValue, mindDegTime);
				}
			}
		}
	}
}