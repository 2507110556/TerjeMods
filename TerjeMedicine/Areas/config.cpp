class CfgPatches
{
	class TerjeMedicine_Areas
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"TerjeMedicine", "TerjeCore"
		};
	};
};

class CfgVehicles
{
	class TerjeScriptableArea;
	class TerjePsionicScriptableArea: TerjeScriptableArea
	{
		scope=2;
		terjeInnerRadius = 50.0; // Players inside this radius will receive full damage
		terjeOuterRadius = 150.0; // Players inside this radius will receive proportional damage depends on distance between two radiuses
		terjeHeightMin = -100.0; // Lower range of the area cylinder
		terjeHeightMax = 100.0; // Upper range of the area cylinder
		terjePower = 2.0; // Area power modifier
	};
};