const string DeathMatch_ModPreffix = "[DM] ";
const bool DeathMatch_TestingMode = false;

void DM_Log(string message)
{
	Print(DeathMatch_ModPreffix + message);
}

bool DM_HasBatterySlot(string classname)
{
	array<string> slots = new array<string>;
	string preffix = FindItemPreffix(classname);
	g_Game.ConfigGetTextArray( preffix + " " + classname + " attachments", slots);
	return slots && slots.Find("BatteryD") != -1;
}

string FindItemPreffix(string itemClassname)
{
	if (g_Game.ConfigIsExisting("CfgVehicles " + itemClassname)) return "CfgVehicles";
	if (g_Game.ConfigIsExisting("CfgMagazines " + itemClassname)) return "CfgMagazines";
	if (g_Game.ConfigIsExisting("CfgAmmo " + itemClassname)) return "CfgAmmo";
	if (g_Game.ConfigIsExisting("CfgWeapons " + itemClassname)) return "CfgWeapons";
	if (g_Game.ConfigIsExisting("CfgNonAIVehicles " + itemClassname)) return "CfgNonAIVehicles";
	return "";
}