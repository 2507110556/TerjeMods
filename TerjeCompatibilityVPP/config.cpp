class CfgPatches
{
	class TerjeCompatibilityVPP
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={ "TerjeCore", "DZM_VPPAdminTools" };
	};
};

class CfgMods
{
	class TerjeCompatibilityVPP
	{
		dir = "TerjeCompatibilityVPP";
		picture = "TerjeCore/Textures/mod_icon.edds";
		action = "https://steamcommunity.com/id/terjebruoygard/myworkshopfiles/";
		hideName = 1;
		hidePicture = 1;
		name = "Terje Compatibility VPP";
		credits = "Terje Bruoygard";
		version = "1.0.0";
		author = "TerjeBruoygard";
		dependencies[] = {"Core","Game","World","Mission"};
		defines[] = { "TERJE_COMPATIBILITY_VPP_MOD" };
		extra = 0;
		type = "mod";
		
		class defs
		{
			class worldScriptModule {
				value = "";
				files[] = {"TerjeCompatibilityVPP/Scripts/4_World"};
			};

			class missionScriptModule {
				value = "";
				files[] = {"TerjeCompatibilityVPP/Scripts/5_Mission"};
			};
		};
	};
};