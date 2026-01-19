class Metabolism
{
	id="mtblsm";
	enabled=1;
	displayName="#STR_TERJESKILL_METABLSM_NAME";
	description="#STR_TERJESKILL_METABLSM_DESC";
	icon="set:TerjeSkills_icon image:ts_metablsm";
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
		class EnergyConsumptionModifier
		{
			id="energconsmod";
			enabled=1;
			text="#STR_TERJESKILL_METABLSM_MOD0";
			value=-0.01;
		};
	};
	class Perks
	{
		class IncreasedCalorie
		{
			id="incalorie";
			enabled=1;
			displayName="#STR_TERJEPERK_METABLSM_INCREASEDCALORIE";
			description="#STR_TERJEPERK_METABLSM_INCREASEDCALORIE_DES";
			stagesCount=5;
			disabledIcon="set:TerjePerkBlack_icon image:tp_incrcalorie";
			enabledIcon="set:TerjePerk_icon image:tp_incrcalorie";
			requiredSkillLevels[]={1,5,10,15,25};
			requiredPerkPoints[]={1,1,1,1,2};
			values[]={0.1,0.25,0.5,0.75,1.0};
		};
		class IncreasedHydration
		{
			id="incrhydr";
			enabled=1;
			displayName="#STR_TERJEPERK_METABLSM_INCREASEDHYDRAT";
			description="#STR_TERJEPERK_METABLSM_INCREASEDHYDRAT_DES";
			stagesCount=5;
			disabledIcon="set:TerjePerkBlack_icon image:tp_incrhydration";
			enabledIcon="set:TerjePerk_icon image:tp_incrhydration";
			requiredSkillLevels[]={1,5,10,15,25};
			requiredPerkPoints[]={1,1,1,1,2};
			values[]={0.1,0.25,0.5,0.75,1.0};
		};
		class EnergySaving
		{
			id="enrgsave";
			enabled=1;
			displayName="#STR_TERJEPERK_METABLSM_ENREGYSAVE";
			description="#STR_TERJEPERK_METABLSM_ENREGYSAVE_DES";
			stagesCount=5;
			disabledIcon="set:TerjePerkBlack_icon image:tp_energysaving";
			enabledIcon="set:TerjePerk_icon image:tp_energysaving";
			requiredSkillLevels[]={1,5,10,15,25};
			requiredPerkPoints[]={1,1,1,1,2};
			values[]={-0.05,-0.15,-0.25,-0.5,-0.75};
		};
		class WaterSaving
		{
			id="watrsave";
			enabled=1;
			displayName="#STR_TERJEPERK_METABLSM_WATERSAVE";
			description="#STR_TERJEPERK_METABLSM_WATERSAVE_DES";
			stagesCount=5;
			disabledIcon="set:TerjePerkBlack_icon image:tp_watersaving";
			enabledIcon="set:TerjePerk_icon image:tp_watersaving";
			requiredSkillLevels[]={1,5,10,15,25};
			requiredPerkPoints[]={1,1,1,1,2};
			values[]={-0.05,-0.15,-0.25,-0.5,-0.75};
		};
		class EnergyControl
		{
			id="enrgcontr";
			enabled=1;
			displayName="#STR_TERJEPERK_METABLSM_ENERGYCONTROL";
			description="#STR_TERJEPERK_METABLSM_ENERGYCONTROL_DES";
			stagesCount=5;
			disabledIcon="set:TerjePerkBlack_icon image:tp_energycontrol";
			enabledIcon="set:TerjePerk_icon image:tp_energycontrol";
			requiredSkillLevels[]={1,5,10,15,25};
			requiredPerkPoints[]={1,1,1,1,2};
			values[]={-0.05,-0.1,-0.15,-0.25,-0.5};
		};
		class HydrationControl
		{
			id="hydrcontr";
			enabled=1;
			displayName="#STR_TERJEPERK_METABLSM_HYDRATIONCONTROL";
			description="#STR_TERJEPERK_METABLSM_HYDRATIONCONTROL_DES";
			stagesCount=5;
			disabledIcon="set:TerjePerkBlack_icon image:tp_hydrationcontrol";
			enabledIcon="set:TerjePerk_icon image:tp_hydrationcontrol";
			requiredSkillLevels[]={1,5,10,15,25};
			requiredPerkPoints[]={1,1,1,1,2};
			values[]={-0.05,-0.1,-0.15,-0.25,-0.5};
		};
		class EnregyContainment
		{
			id="enrgconta";
			enabled=1;
			displayName="#STR_TERJEPERK_METABLSM_ENERGYCONTAIN";
			description="#STR_TERJEPERK_METABLSM_ENERGYCONTAIN_DES";
			stagesCount=5;
			disabledIcon="set:TerjePerkBlack_icon image:tp_enregycontain";
			enabledIcon="set:TerjePerk_icon image:tp_enregycontain";
			requiredSkillLevels[]={1,5,10,15,25};
			requiredPerkPoints[]={1,1,1,1,1};
			values[]={-0.05,-0.15,-0.25,-0.5,-0.75};
		};
		class WaterContainment
		{
			id="watrconta";
			enabled=1;
			displayName="#STR_TERJEPERK_METABLSM_WATERCONTAIN";
			description="#STR_TERJEPERK_METABLSM_WATERCONTAIN_DES";
			stagesCount=5;
			disabledIcon="set:TerjePerkBlack_icon image:tp_watercontain";
			enabledIcon="set:TerjePerk_icon image:tp_watercontain";
			requiredSkillLevels[]={1,5,10,15,25};
			requiredPerkPoints[]={1,1,1,1,1};
			values[]={-0.05,-0.15,-0.25,-0.5,-0.75};
		};
		class ResistWater
		{
			id="reswater";
			enabled=1;
			displayName="#STR_TERJEPERK_METABLSM_RESISTWATER";
			description="#STR_TERJEPERK_METABLSM_RESISTWATER_DES";
			stagesCount=5;
			disabledIcon="set:TerjePerkBlack_icon image:tp_resistwater";
			enabledIcon="set:TerjePerk_icon image:tp_resistwater";
			requiredSkillLevels[]={1,5,10,15,25};
			requiredPerkPoints[]={1,1,1,1,2};
			values[]={-0.05,-0.15,-0.25,-0.5,-0.75};
		};
		class ResistHunger
		{
			id="reshunger";
			enabled=1;
			displayName="#STR_TERJEPERK_METABLSM_RESISTHUNGER";
			description="#STR_TERJEPERK_METABLSM_RESISTHUNGER_DES";
			stagesCount=5;
			disabledIcon="set:TerjePerkBlack_icon image:tp_resisthunger";
			enabledIcon="set:TerjePerk_icon image:tp_resisthunger";
			requiredSkillLevels[]={1,5,10,15,25};
			requiredPerkPoints[]={1,1,1,1,2};
			values[]={-0.05,-0.15,-0.25,-0.5,-0.75};
		};
		class WildMeatLover
		{
			id="wmlover";
			enabled=1;
			displayName="#STR_TERJEPERK_METABLSM_WMLOVER";
			description="#STR_TERJEPERK_METABLSM_WMLOVER_DES";
			stagesCount=1;
			disabledIcon="set:TerjePerkBlack_icon image:tp_wmlover";
			enabledIcon="set:TerjePerk_icon image:tp_wmlover";
			requiredSkillLevels[]={35};
			requiredPerkPoints[]={2};
			values[]={0.0};
		};
	};
};
