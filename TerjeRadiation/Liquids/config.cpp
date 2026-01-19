class CfgPatches
{
	class TerjeRadiation_Liquids
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"TerjeRadiation", "TerjeCore"
		};
	};
};

class CfgTerjeCustomLiquids
{
	class SoapyWater
	{
		displayName="#STR_TERJERAD_SOAPY_WATER";
		flammability=-10;
		liquidFreezeThreshold=0;
		liquidThawThreshold=0;
		liquidBoilingThreshold=150;
		terjeRadiationCleanupForce=10;
		class Nutrition
		{
			fullnessIndex=1;
			energy=-5;
			water=5;
			nutritionalIndex=75;
			toxicity=1;
			digestibility=2;
			agents=16;
		};
	};
	class RadDesactivator
	{
		displayName="#STR_TERJERAD_RAD_DISACTIVATOR";
		flammability=-10;
		liquidFreezeThreshold=0;
		liquidThawThreshold=0;
		liquidBoilingThreshold=150;
		terjeRadiationCleanupForce=50;
		terjeOverrideLiquidColor=-10267848; // Use https://argb-int-calculator.netlify.app/ to calculate int color value.
		class Nutrition
		{
			fullnessIndex=1;
			energy=-5;
			water=0;
			nutritionalIndex=75;
			toxicity=1;
			digestibility=2;
			agents=16;
		};
	};
};