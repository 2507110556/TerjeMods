class CfgPatches
{
	class TerjeCompatibilityCOT
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={ "TerjeCore", "JM_COT_Scripts" };
	};
};

class CfgMods
{
	class TerjeCompatibilityCOT
	{
		dir = "TerjeCompatibilityCOT";
		picture = "TerjeCore/Textures/mod_icon.edds";
		action = "https://steamcommunity.com/id/terjebruoygard/myworkshopfiles/";
		hideName = 1;
		hidePicture = 1;
		name = "Terje Compatibility COT";
		credits = "Terje Bruoygard";
		version = "1.0.0";
		author = "TerjeBruoygard";
		dependencies[] = {"Core","Game","World","Mission"};
		defines[] = { "TERJE_COMPATIBILITY_COT_MOD" };
		extra = 0;
		type = "mod";
		
		class defs
		{
			class worldScriptModule {
				value = "";
				files[] = {"TerjeCompatibilityCOT/Scripts/4_World"};
			};

			class missionScriptModule {
				value = "";
				files[] = {"TerjeCompatibilityCOT/Scripts/5_Mission"};
			};
		};
	};
};