class Stealth
{
	id="stlth";
	enabled=1;
	displayName="#STR_TERJESKILL_STEALCH_NAME";
	description="#STR_TERJESKILL_STEALCH_DESC";
	icon="set:TerjeSkills_icon image:ts_stealth";
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
	class Perks
	{
		class QuietStep
		{
			id="qtstep";
			enabled=1;
			displayName="#STR_TERJEPERK_STLTH_QUIETSTEP";
			description="#STR_TERJEPERK_STLTH_QUIETSTEP_DES";
			stagesCount=5;
			disabledIcon="set:TerjePerkBlack_icon image:tp_quiestep";
			enabledIcon="set:TerjePerk_icon image:tp_quiestep";
			requiredSkillLevels[]={1,5,10,15,25};
			requiredPerkPoints[]={1,1,1,1,2};
			values[]={-0.05,-0.10,-0.25,-0.5,-0.75};
		};
		class ColdBlooded
		{
			id="coldbldd";
			enabled=1;
			displayName="#STR_TERJEPERK_STLTH_COLDBLOODED";
			description="#STR_TERJEPERK_STLTH_COLDBLOODED_DES";
			stagesCount=5;
			disabledIcon="set:TerjePerkBlack_icon image:tp_coldblooded";
			enabledIcon="set:TerjePerk_icon image:tp_coldblooded";
			requiredSkillLevels[]={1,5,10,15,25};
			requiredPerkPoints[]={1,1,1,1,2};
			values[]={-0.1,-0.25,-0.5,-0.75,-1.0};
		};
		class QuietShooter
		{
			id="qshooter";
			enabled=1;
			displayName="#STR_TERJEPERK_STLTH_QUIETSHOOTER";
			description="#STR_TERJEPERK_STLTH_QUIETSHOOTER_DES";
			stagesCount=5;
			disabledIcon="set:TerjePerkBlack_icon image:tp_quietshooter";
			enabledIcon="set:TerjePerk_icon image:tp_quietshooter";
			requiredSkillLevels[]={1,5,10,15,25};
			requiredPerkPoints[]={1,1,1,1,2};
			values[]={-0.05,-0.10,-0.25,-0.5,-0.75};
		};
		class FittingEquipment
		{
			id="fitequip";
			enabled=1;
			displayName="#STR_TERJEPERK_STLTH_FITTINGEQUIP";
			description="#STR_TERJEPERK_STLTH_FITTINGEQUIP_DES";
			stagesCount=5;
			disabledIcon="set:TerjePerkBlack_icon image:tp_fittingequipment";
			enabledIcon="set:TerjePerk_icon image:tp_fittingequipment";
			requiredSkillLevels[]={1,5,10,15,25};
			requiredPerkPoints[]={1,1,1,1,2};
			values[]={-0.1,-0.2,-0.4,-0.6,-0.8};
		};
		class InvisibleMan
		{
			id="invisman";
			enabled=1;
			displayName="#STR_TERJEPERK_STLTH_INVISIBLEMAN";
			description="#STR_TERJEPERK_STLTH_INVISIBLEMAN_DES";
			stagesCount=5;
			disabledIcon="set:TerjePerkBlack_icon image:tp_invisibleman";
			enabledIcon="set:TerjePerk_icon image:tp_invisibleman";
			requiredSkillLevels[]={1,5,10,15,25};
			requiredPerkPoints[]={1,1,1,1,2};
			values[]={-0.05,-0.10,-0.25,-0.5,-0.75};
		};
		class CatVision
		{
			id="catvis";
			enabled=1;
			displayName="#STR_TERJEPERK_STLTH_CATVISION";
			description="#STR_TERJEPERK_STLTH_CATVISION_DES";
			stagesCount=5;
			disabledIcon="set:TerjePerkBlack_icon image:tp_catvision";
			enabledIcon="set:TerjePerk_icon image:tp_catvision";
			requiredSkillLevels[]={1,5,10,15,25};
			requiredPerkPoints[]={1,1,1,1,2};
			values[]={0.25,0.5,0.75,1.0,1.5};
		};
		class WolfInstinct
		{
			id="wolfinst";
			enabled=1;
			displayName="#STR_TERJEPERK_STLTH_WOLFINSTINCT";
			description="#STR_TERJEPERK_STLTH_WOLFINSTINCT_DES";
			stagesCount=5;
			disabledIcon="set:TerjePerkBlack_icon image:tp_wolfinstinct";
			enabledIcon="set:TerjePerk_icon image:tp_wolfinstinct";
			requiredSkillLevels[]={1,5,10,15,25};
			requiredPerkPoints[]={1,1,1,1,2};
			values[]={-0.1,-0.2,-0.3,-0.6,-0.9};
		};
		class BearsFriend
		{
			id="bearfrnd";
			enabled=1;
			displayName="#STR_TERJEPERK_STLTH_FRIENDBEAR";
			description="#STR_TERJEPERK_STLTH_FRIENDBEAR_DES";
			stagesCount=5;
			disabledIcon="set:TerjePerkBlack_icon image:tp_friendbear";
			enabledIcon="set:TerjePerk_icon image:tp_friendbear";
			requiredSkillLevels[]={1,5,10,15,25};
			requiredPerkPoints[]={1,1,1,1,2};
			values[]={-0.1,-0.2,-0.3,-0.6,-0.9};
		};
		class SilentKiller
		{
			id="silentkilr";
			enabled=1;
			displayName="#STR_TERJEPERK_STLTH_SILENTKILLER";
			description="#STR_TERJEPERK_STLTH_SILENTKILLER_DES";
			stagesCount=1;
			disabledIcon="set:TerjePerkBlack_icon image:tp_silentkiller";
			enabledIcon="set:TerjePerk_icon image:tp_silentkiller";
			requiredSkillLevels[]={1};
			requiredPerkPoints[]={2};
			values[]={0.0};
		};
		class Ninja
		{
			id="ninja";
			enabled=1;
			displayName="#STR_TERJEPERK_STLTH_NINJA";
			description="#STR_TERJEPERK_STLTH_NINJA_DES";
			stagesCount=1;
			disabledIcon="set:TerjePerkBlack_icon image:tp_ninja";
			enabledIcon="set:TerjePerk_icon image:tp_ninja";
			requiredSkillLevels[]={30};
			requiredPerkPoints[]={3};
			values[]={-0.5};
		};
		class ShadowTracker
		{
			id="shadowtrc";
			enabled=1;
			displayName="#STR_TERJEPERK_STLTH_SHADOWTRACKER";
			description="#STR_TERJEPERK_STLTH_SHADOWTRACKER_DES";
			stagesCount=1;
			disabledIcon="set:TerjePerkBlack_icon image:tp_shadowtrack";
			enabledIcon="set:TerjePerk_icon image:tp_shadowtrack";
			requiredSkillLevels[]={40};
			requiredPerkPoints[]={3};
			values[]={0.0};
		};
	};
};