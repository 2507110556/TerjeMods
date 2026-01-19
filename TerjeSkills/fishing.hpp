class Fishing
{
	id="fish";
	enabled=1;
	displayName="#STR_TERJESKILL_FISHING_NAME";
	description="#STR_TERJESKILL_FISHING_DESC";
	icon="set:TerjeSkills_icon image:ts_fushing";
	perkPointsPerLevel=1;
	expLoseOnDeath=-100;
	levels[]=
	{
		100, 200, 300, 400, 500, 700, 900, 1100, 1300, 1500, // 1-10
		1750, 2000, 2250, 2500, 2750, 3000, 3500, 4000, 4500, 5000, // 11-20
		6000, 6750, 7500, 8250, 9000, 10000, 11000, 12000, 13000, 14000, // 20-30
		16000, 18000, 20000, 22000, 24000, 26000, 28000, 30000, 32000, 34000, // 31-40
		37000, 40000, 43000, 46000, 50000, 55000, 60000, 70000, 80000, 100000 // 41-50
	};
	class Modifiers
	{
		class CatchFishModifier
		{
			id="catchmod";
			enabled=1;
			text="#STR_TERJESKILL_FISHING_MOD0";
			value=0.02;
		};
	};
	class Perks
	{
		class MasterFillet
		{
			id="masterf";
			enabled=1;
			displayName="#STR_TERJESKILL_FISH_MASTERFILLET";
			description="#STR_TERJESKILL_FISH_MASTERFILLET_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_mastfile";
			enabledIcon="set:TerjePerk_icon image:tp_mastfile";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,1,2};
			values[]={0.1,0.2,0.4,0.6,0.8,1.0};
		};
		class QuickClean
		{
			id="quickclean";
			enabled=1;
			displayName="#STR_TERJESKILL_FISH_QUICKCLEANING";
			description="#STR_TERJESKILL_FISH_QUICKCLEANING_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_quickclean";
			enabledIcon="set:TerjePerk_icon image:tp_quickclean";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,1,2};
			values[]={-0.1,-0.2,-0.3,-0.5,-0.75,-0.95};
		};
		class StraightArms
		{
			id="strgarms";
			enabled=1;
			displayName="#STR_TERJESKILL_FISH_STRAIGHTARMS";
			description="#STR_TERJESKILL_FISH_STRAIGHTARMS_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_straightarms";
			enabledIcon="set:TerjePerk_icon image:tp_straightarms";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,1,2};
			values[]={-0.1,-0.2,-0.4,-0.6,-0.8,-1.0};
		};
		class MasterTrap
		{
			id="mastrap";
			enabled=1;
			displayName="#STR_TERJESKILL_FISH_MASTERTRAPS";
			description="#STR_TERJESKILL_FISH_MASTERTRAPS_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_mastrtrap";
			enabledIcon="set:TerjePerk_icon image:tp_mastrtrap";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,1,2};
			values[]={0.1,0.2,0.4,0.6,0.8,1.0};
		};
		class SkilledFisherman
		{
			id="skfishman";
			enabled=1;
			displayName="#STR_TERJESKILL_FISH_SKILLEDFISHERMAN";
			description="#STR_TERJESKILL_FISH_SKILLEDFISHERMAN_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_skillfishman";
			enabledIcon="set:TerjePerk_icon image:tp_skillfishman";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,1,2};
			values[]={0.1,0.25,0.5,0.75,1.0,2.5};
		};
		class FishermanLuck
		{
			id="fishmluck";
			enabled=1;
			displayName="#STR_TERJESKILL_FISH_FISHERMANLUCK";
			description="#STR_TERJESKILL_FISH_FISHERMANLUCK_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_fishmanluck";
			enabledIcon="set:TerjePerk_icon image:tp_fishmanluck";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,1,2};
			values[]={0.1,0.2,0.4,0.6,0.8,1.0};
		};
		class ReliableGear
		{
			id="reliabgear";
			enabled=1;
			displayName="#STR_TERJESKILL_FISH_RELIABLEGEAR";
			description="#STR_TERJESKILL_FISH_RELIABLEGEAR_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_reliablegear";
			enabledIcon="set:TerjePerk_icon image:tp_reliablegear";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,1,2};
			values[]={-0.1,-0.2,-0.4,-0.6,-0.8,-1.0};
		};
		class WormHunter
		{
			id="wormhunt";
			enabled=1;
			displayName="#STR_TERJESKILL_FISH_WORMHUNTER";
			description="#STR_TERJESKILL_FISH_WORMHUNTER_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_wormhunter";
			enabledIcon="set:TerjePerk_icon image:tp_wormhunter";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,1,2};
			values[]={0.25,0.5,0.75,1.0,2.0,3.0};
		};
		class CraftsMan
		{
			id="craftsman";
			enabled=1;
			displayName="#STR_TERJESKILL_FISH_CRAFTSMAN";
			description="#STR_TERJESKILL_FISH_CRAFTSMAN_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_craftsman";
			enabledIcon="set:TerjePerk_icon image:tp_craftsman";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,1,2};
			values[]={0.35,0.45,0.55,0.65,0.75,1.0};
		};
		class RemoveRottenFish
		{
			id="remrotf";
			enabled=1;
			displayName="#STR_TERJESKILL_FISH_REMROT";
			description="#STR_TERJESKILL_FISH_REMROT_DES";
			stagesCount=1;
			disabledIcon="set:TerjePerkBlack_icon image:tp_cleanwizard";
			enabledIcon="set:TerjePerk_icon image:tp_cleanwizard";
			requiredSkillLevels[]={1};
			requiredPerkPoints[]={1};
			values[]={0.0};
		};
	};
};