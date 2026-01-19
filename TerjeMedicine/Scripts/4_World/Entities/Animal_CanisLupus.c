modded class Animal_CanisLupus
{
	private bool m_HasTerjeRabies;
	
	override bool HasTerjeRabies()
	{
		return m_HasTerjeRabies;
	}
	
	override void EEInit()
	{
		super.EEInit();
		
		if (GetGame().IsDedicatedServer())
		{
			float rabiesChance;
			if (GetTerjeSettingFloat(TerjeSettingsCollection.MEDICINE_RABIES_WOLF_INFECTED_CHANCE, rabiesChance))
			{
				m_HasTerjeRabies = (Math.RandomFloat01() < rabiesChance);
			}
		}
	}
}
