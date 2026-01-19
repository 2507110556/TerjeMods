class CfgPatches
{
	class TerjeSkills_Fishing
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"TerjeSkills", "DZ_Gear_Tools"
		};
	};
};

class CfgVehicles
{
	class FishingRod_Base_New;
	
	class ImprovisedFishingRod: FishingRod_Base_New
	{
		terjeFishingExpModifier=0.5;
	};
	
	class FishingRod: FishingRod_Base_New
	{
		terjeFishingExpModifier=1.0;
	};
};