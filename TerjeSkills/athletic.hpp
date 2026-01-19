class Athletic
{
	id="athlc";
	enabled=1;
	displayName="#STR_TERJESKILL_ATHLETIC_NAME";
	description="#STR_TERJESKILL_ATHLETIC_DESC";
	icon="set:TerjeSkills_icon image:ts_athletic";
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
		class MaxStaminaModifier
		{
			id="maxstaminamod";
			enabled=1;
			text="#STR_TERJESKILL_ATHLETIC_MOD0";
			value=0.02;
		};
	};
	class Perks
	{
		class QuickFeet
		{
			id="quickf";
			enabled=1;
			displayName="#STR_TERJEPERK_ATH_QUICKFEET";
			description="#STR_TERJEPERK_ATH_QUICKFEET_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_quickfeet";
			enabledIcon="set:TerjePerk_icon image:tp_quickfeet";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,1,1};
			values[]={-0.05,-0.1,-0.2,-0.3,-0.4,-0.8};
		};
		class Marathoner
		{
			id="marathon";
			enabled=1;
			displayName="#STR_TERJEPERK_ATH_MARATHONER";
			description="#STR_TERJEPERK_ATH_MARATHONER_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_marathoner";
			enabledIcon="set:TerjePerk_icon image:tp_marathoner";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,1,2};
			values[]={0.05,0.1,0.2,0.3,0.5,1.0};
		};
		class ProperBreathing
		{
			id="pbreath";
			enabled=1;
			displayName="#STR_TERJEPERK_ATH_PROPERBREATHING";
			description="#STR_TERJEPERK_ATH_PROPERBREATHING_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_properbreathing";
			enabledIcon="set:TerjePerk_icon image:tp_properbreathing";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,1,2};
			values[]={0.1,0.2,0.3,0.4,0.5,1.0};
		};
		class Swimmer
		{
			id="swimmer";
			enabled=1;
			displayName="#STR_TERJEPERK_ATH_SWIMMER";
			description="#STR_TERJEPERK_ATH_SWIMMER_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_swimmer";
			enabledIcon="set:TerjePerk_icon image:tp_swimmer";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,1,1};
			values[]={0.05,0.1,0.2,0.3,0.4,0.5};
		};
		class StairMaster
		{
			id="ladder";
			enabled=1;
			displayName="#STR_TERJEPERK_ATH_STAIRMASTER";
			description="#STR_TERJEPERK_ATH_STAIRMASTER_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_stairmaster";
			enabledIcon="set:TerjePerk_icon image:tp_stairmaster";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,1,1};
			values[]={0.1,0.2,0.3,0.4,0.5,0.75};
		};
		
		class NoPanting
		{
			id="npant";
			enabled=1;
			displayName="#STR_TERJEPERK_ATH_NOPANTING";
			description="#STR_TERJEPERK_ATH_NOPANTING_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_nopanting";
			enabledIcon="set:TerjePerk_icon image:tp_nopanting";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,1,2};
			values[]={-0.1,-0.2,-0.4,-0.6,-0.8,-1.0};
		};
		class Enduring
		{
			id="enduring";
			enabled=1;
			displayName="#STR_TERJEPERK_ATH_ENDURING";
			description="#STR_TERJEPERK_ATH_ENDURING_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_enduring";
			enabledIcon="set:TerjePerk_icon image:tp_enduring";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,1,2};
			values[]={0.1,0.2,0.4,0.6,0.8,1.0};
		};
		class Stuntman
		{
			id="stuntman";
			enabled=1;
			displayName="#STR_TERJEPERK_ATH_STUNTMAN";
			description="#STR_TERJEPERK_ATH_STUNTMAN_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_stuntman";
			enabledIcon="set:TerjePerk_icon image:tp_stuntman";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,1,1};
			values[]={-0.05,-0.1,-0.2,-0.3,-0.5,-0.75};
		};
		class StrongBones
		{
			id="strbones";
			enabled=1;
			displayName="#STR_TERJEPERK_ATH_STRONGBONES";
			description="#STR_TERJEPERK_ATH_STRONGBONES_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_bonecrusher";
			enabledIcon="set:TerjePerk_icon image:tp_bonecrusher";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,1,1};
			values[]={-0.05,-0.1,-0.2,-0.3,-0.5,-0.75};
		};
	};
};
