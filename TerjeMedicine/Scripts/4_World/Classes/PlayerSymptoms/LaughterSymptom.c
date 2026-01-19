modded class LaughterSymptom
{
	override void OnGetActivatedServer(PlayerBase player)
	{
		bool mindUseLaughterSymptom = true;
		GetTerjeSettingBool(TerjeSettingsCollection.MEDICINE_MIND_USE_LAUGHTER_SYMPTOM, mindUseLaughterSymptom);
		if (mindUseLaughterSymptom)
		{
			super.OnGetActivatedServer(player);
		}
	}
}
