class CfgPatches
{
	class TerjeElectronics
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"TerjeCore", "DZ_Data"
		};
	};
};

class CfgMods
{
	class TerjeElectronics
	{
		dir = "TerjeElectronics";
		picture = "TerjeElectronics/Textures/mod_icon.edds";
		action = "https://steamcommunity.com/id/terjebruoygard/myworkshopfiles/";
		hideName = 0;
		hidePicture = 0;
		name = "Terje Electronics";
		credits = "Terje Bruoygard";
		version = "1.0.0";
		author = "TerjeBruoygard";
		dependencies[] = {"Core","Game","World","Mission"};
		defines[] = { "TERJE_ELECTRONICS_MOD" };
		extra = 0;
		type = "mod"; 
		
		class defs
		{
			class imageSets
			{
				files[] = {
					"TerjeElectronics/Textures/system_icons.imageset",
					"TerjeElectronics/Textures/program_icons.imageset",
					"TerjeElectronics/Textures/stalker_os.imageset"
				};
			};
			class gameScriptModule {
				value = "";
				files[] = {"TerjeElectronics/Scripts/3_Game"};
			};
			
			class worldScriptModule {
				value = "";
				files[] = {"TerjeElectronics/Scripts/4_World"};
			};

			class missionScriptModule {
				value = "";
				files[] = {"TerjeElectronics/Scripts/5_Mission"};
			};
		};
	};
};

class CfgVehicles
{
	class Inventory_Base;
	class TerjeGadgetBase : Inventory_Base
	{
	};
};