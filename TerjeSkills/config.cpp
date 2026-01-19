class CfgPatches
{
	class TerjeSkills
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"TerjeCore"
		};
	};
};

class CfgMods
{
	class TerjeSkills
	{
		dir = "TerjeSkills";
		picture = "TerjeSkills/Textures/mod_icon.edds";
		action = "https://steamcommunity.com/id/terjebruoygard/myworkshopfiles/";
		hideName = 0;
		hidePicture = 0;
		name = "Terje Skills";
		credits = "Terje Bruoygard";
		version = "1.0.0";
		author = "TerjeBruoygard";
		dependencies[] = {"Core","Game","World","Mission"};
		defines[] = { "TERJE_SKILLS_MOD" };
		extra = 0;
		type = "mod"; 
		
		class defs
		{
			class imageSets
			{
				files[] = {
					"TerjeSkills/Textures/Icons/TerjeSkills.imageset", 
					"TerjeSkills/Textures/Icons/PerkBorders.imageset", 
					"TerjeSkills/Textures/Icons/PerkLevels.imageset", 
					"TerjeSkills/Textures/Icons/TerjePerk.imageset",
					"TerjeSkills/Textures/Icons/TerjePerkBlack.imageset"};
			};
			class gameScriptModule {
				value = "";
				files[] = {"TerjeSkills/Scripts/3_Game"};
			};
			
			class worldScriptModule {
				value = "";
				files[] = {"TerjeSkills/Scripts/4_World"};
			};

			class missionScriptModule {
				value = "";
				files[] = {"TerjeSkills/Scripts/5_Mission"};
			};
		};
	};
};

class CfgTerjeSkills
{
	#include "athletic.hpp"
	#include "strength.hpp"
	#include "metabolism.hpp"
	#include "stealth.hpp"
	#include "survival.hpp"
	#include "hunting.hpp"
	#include "fishing.hpp"
};