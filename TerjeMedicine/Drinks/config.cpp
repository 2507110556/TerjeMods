class CfgPatches
{
	class TerjeMedicine_Drinks
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"TerjeMedicine", "DZ_Gear_Drinks"
		};
	};
};

class CfgVehicles
{
	class SodaCan_ColorBase;
	class TerjeEnergyDrink : SodaCan_ColorBase
	{ 
		scope=0;
		class AnimEvents
		{
			class SoundWeapon
			{
				class SodaCan_in_B
				{
					soundSet="SodaCan_in_B_SoundSet";
					id=202;
				};
				class WellPond_loop
				{
					soundSet="WellPond_loop_SoundSet";
					id=209;
				};
				class WellBottle_loop
				{
					soundSet="WellBottle_loop_SoundSet";
					id=210;
				};
				class pickup
				{
					soundSet="SodaCan_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="SodaCan_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class TerjeDrinkMadBull: TerjeEnergyDrink
	{
		scope=2;
		medSleepingIncrementValue = 8;
		medSleepingIncrementTimeSec = 1.0; // Time per 1ml
		displayName="#STR_TERJEDRINK_MADBULL_NAME";
		descriptionShort="#STR_TERJEDRINK_MADBULL_DESC";
		hiddenSelectionsTextures[]=
		{
			"TerjeMedicine\Drinks\madbull.paa"
		};
	};
	class TerjeDrinkGang: TerjeEnergyDrink
	{
		scope=2;
		medSleepingIncrementValue = 6;
		medSleepingIncrementTimeSec = 1.0; // Time per 1ml
		displayName="#STR_TERJEDRINK_GANG_NAME";
		descriptionShort="#STR_TERJEDRINK_GANG_DESC";
		hiddenSelectionsTextures[]=
		{
			"TerjeMedicine\Drinks\gang.paa"
		};
	};
	class TerjeDrinkYaguar: TerjeEnergyDrink
	{
		scope=2;
		medSleepingIncrementValue = 10;
		medSleepingIncrementTimeSec = 1.0; // Time per 1ml
		displayName="#STR_TERJEDRINK_YAGUAR_NAME";
		descriptionShort="#STR_TERJEDRINK_YAGUAR_DESC";
		hiddenSelectionsTextures[]=
		{
			"TerjeMedicine\Drinks\yaguar.paa"
		};
	};
	class TerjeDrinkPrayboy: TerjeEnergyDrink
	{
		scope=2;
		medSleepingIncrementValue = 4;
		medSleepingIncrementTimeSec = 1.0; // Time per 1ml
		displayName="#STR_TERJEDRINK_PRAYBOY_NAME";
		descriptionShort="#STR_TERJEDRINK_PRAYBOY_DESC";
		hiddenSelectionsTextures[]=
		{
			"TerjeMedicine\Drinks\prayboy.paa"
		};
	};
	class TerjeDrink6Energy: TerjeEnergyDrink
	{
		scope=2;
		medSleepingIncrementValue = 8;
		medSleepingIncrementTimeSec = 0.8; // Time per 1ml
		displayName="#STR_TERJEDRINK_6ENERGY_NAME";
		descriptionShort="#STR_TERJEDRINK_6ENERGY_DESC";
		hiddenSelectionsTextures[]=
		{
			"TerjeMedicine\Drinks\6energy.paa"
		};
	};

	class HouseNoDestruct;

	class StaticObj_TerjeDrinkMadBull: HouseNoDestruct
	{
		scope=1;
		model="\dz\gear\drinks\SodaCan.p3d";
		hiddenSelections[]=	{"camoGround"};
		hiddenSelectionsTextures[]=
		{
			"TerjeMedicine\Drinks\madbull.paa"
		};
	};
	class StaticObj_TerjeDrinkGang: HouseNoDestruct
	{
		scope=1;
		model="\dz\gear\drinks\SodaCan.p3d";
		hiddenSelections[]=	{"camoGround"};
		hiddenSelectionsTextures[]=
		{
			"TerjeMedicine\Drinks\gang.paa"
		};
	};
	class StaticObj_TerjeDrinkYaguar: HouseNoDestruct
	{
		scope=1;
		model="\dz\gear\drinks\SodaCan.p3d";
		hiddenSelections[]=	{"camoGround"};
		hiddenSelectionsTextures[]=
		{
			"TerjeMedicine\Drinks\yaguar.paa"
		};
	};
	class StaticObj_TerjeDrinkPrayboy: HouseNoDestruct
	{
		scope=1;
		model="\dz\gear\drinks\SodaCan.p3d";
		hiddenSelections[]=	{"camoGround"};
		hiddenSelectionsTextures[]=
		{
			"TerjeMedicine\Drinks\prayboy.paa"
		};
	};
	class StaticObj_TerjeDrink6Energy: HouseNoDestruct
	{
		scope=1;
		model="\dz\gear\drinks\SodaCan.p3d";
		hiddenSelections[]=	{"camoGround"};
		hiddenSelectionsTextures[]=
		{
			"TerjeMedicine\Drinks\6energy.paa"
		};
	};
};