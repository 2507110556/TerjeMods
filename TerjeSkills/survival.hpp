class Survival
{
	id="surv";
	enabled=1;
	displayName="#STR_TERJESKILL_SURVIVAL_NAME";
	description="#STR_TERJESKILL_SURVIVAL_DESC";
	icon="set:TerjeSkills_icon image:ts_survival";
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
		class ReducedTempModifier
		{
			id="survtempmod";
			enabled=1;
			text="#STR_TERJESKILL_SURVIVAL_MOD0";
			value=-0.01;
		};
		class ReducedZombDmgModifier
		{
			id="survzmbmod";
			enabled=1;
			text="#STR_TERJESKILL_SURVIVAL_MOD1";
			value=-0.01;
		};
		class ReducedFireStartModifier
		{
			id="survfiremod";
			enabled=1;
			text="#STR_TERJESKILL_SURVIVAL_MOD2";
			value=-0.02;
		};
	};
	class Perks
	{
		class StartingFire
		{
			id="startfire";
			enabled=1;
			displayName="#STR_TERJESKILL_SURV_STARTFIRE";
			description="#STR_TERJESKILL_SURV_STARTFIRE_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_startingfire";
			enabledIcon="set:TerjePerk_icon image:tp_startingfire";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,1,2};
			values[]={0.1,0.2,0.4,0.6,0.8,1.0};
		};
		class ColdResistance
		{
			id="coldres";
			enabled=1;
			displayName="#STR_TERJESKILL_SURV_COLDRESISTANCE";
			description="#STR_TERJESKILL_SURV_COLDRESISTANCE_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_freezeresist";
			enabledIcon="set:TerjePerk_icon image:tp_freezeresist";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,1,2};
			values[]={0.05,0.1,0.2,0.3,0.4,0.5};
		};
		class RoughFeet
		{
			id="rghfeet";
			enabled=1;
			displayName="#STR_TERJESKILL_SURV_ROUGHFEET";
			description="#STR_TERJESKILL_SURV_ROUGHFEET_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_roughfeet";
			enabledIcon="set:TerjePerk_icon image:tp_roughfeet";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,1,2};
			values[]={-0.1,-0.2,-0.4,-0.6,-0.8,-1.0};
		};
		class RoughHands
		{
			id="rghhands";
			enabled=1;
			displayName="#STR_TERJESKILL_SURV_ROUGHHANDS";
			description="#STR_TERJESKILL_SURV_ROUGHHANDS_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_roughhands";
			enabledIcon="set:TerjePerk_icon image:tp_roughhands";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,1,2};
			values[]={-0.1,-0.2,-0.4,-0.6,-0.8,-1.0};
		};
		class AncestralTechnologies
		{
			id="anctech";
			enabled=1;
			displayName="#STR_TERJESKILL_SURV_ANCESTRALTECHNOLOGIE";
			description="#STR_TERJESKILL_SURV_ANCESTRALTECHNOLOGIE_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_ancestechno";
			enabledIcon="set:TerjePerk_icon image:tp_ancestechno";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,1,2};
			values[]={0.35,0.45,0.55,0.65,0.75,1.0};
		};
		class MaintainingFire
		{
			id="maintngfire";
			enabled=1;
			displayName="#STR_TERJESKILL_SURV_MAINTAININGFIRE";
			description="#STR_TERJESKILL_SURV_MAINTAININGFIRE_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_maintainingfire";
			enabledIcon="set:TerjePerk_icon image:tp_maintainingfire";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,1,2};
			values[]={0.25,0.5,1.0,1.5,2.0,3.0};
		};
		class DurableEquipment
		{
			id="durequip";
			enabled=1;
			displayName="#STR_TERJESKILL_SURV_DURABLEEQUIPMENT";
			description="#STR_TERJESKILL_SURV_DURABLEEQUIPMENT_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_durableequip";
			enabledIcon="set:TerjePerk_icon image:tp_durableequip";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,1,2};
			values[]={-0.1,-0.2,-0.4,-0.6,-0.7,-0.85};
		};
		class Bushcraft
		{
			id="bushcraft";
			enabled=1;
			displayName="#STR_TERJESKILL_SURV_CRAFTS";
			description="#STR_TERJESKILL_SURV_CRAFTS_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_survcrafts";
			enabledIcon="set:TerjePerk_icon image:tp_survcrafts";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,1,2};
			values[]={0.35,0.45,0.55,0.65,0.75,1.0};
		};
		class Expert
		{
			id="expert";
			enabled=1;
			displayName="#STR_TERJESKILL_SURV_EXPERT";
			description="#STR_TERJESKILL_SURV_EXPERT_DES";
			stagesCount=1;
			disabledIcon="set:TerjePerkBlack_icon image:tp_expert";
			enabledIcon="set:TerjePerk_icon image:tp_expert";
			requiredSkillLevels[]={15};
			requiredPerkPoints[]={1};
			values[]={0.0};
		};
		class Stashes
		{
			id="stashes";
			enabled=1;
			displayName="#STR_TERJESKILL_SURV_STASHES";
			description="#STR_TERJESKILL_SURV_STASHES_DES";
			stagesCount=1;
			disabledIcon="set:TerjePerkBlack_icon image:tp_caches";
			enabledIcon="set:TerjePerk_icon image:tp_caches";
			requiredSkillLevels[]={15};
			requiredPerkPoints[]={2};
			values[]={0.0};
		};
		class SurvivalInstinct
		{
			id="survinst";
			enabled=1;
			displayName="#STR_TERJESKILL_SURV_SURVIVALINSTINCT";
			description="#STR_TERJESKILL_SURV_SURVIVALINSTINCT_DES";
			stagesCount=1;
			disabledIcon="set:TerjePerkBlack_icon image:tp_survinstinct";
			enabledIcon="set:TerjePerk_icon image:tp_survinstinct";
			requiredSkillLevels[]={15};
			requiredPerkPoints[]={2};
			values[]={0.0};
		};
		class MushroomPremonition
		{
			id="mushprem";
			enabled=1;
			displayName="#STR_TERJESKILL_SURV_MUSHROOMPREMONITION";
			description="#STR_TERJESKILL_SURV_MUSHROOMPREMONITION_DES";
			stagesCount=1;
			disabledIcon="set:TerjePerkBlack_icon image:tp_mushpremonition";
			enabledIcon="set:TerjePerk_icon image:tp_mushpremonition";
			requiredSkillLevels[]={35};
			requiredPerkPoints[]={2};
			values[]={0.0};
		};
	};
};