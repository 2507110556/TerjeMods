class CfgPatches
{
	class TerjeElectronics_Laptop
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"TerjeElectronics", "DZ_Data"};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class TerjeLaptop_ColorBase: Inventory_Base
	{
		scope = 2;
		displayName = "#STR_TerjeGadgets_LAPTOP_NAME";
		descriptionShort = "#STR_TerjeGadgets_LAPTOP_DESC";
		model = "\TerjeElectronics\Laptop\TerjeLaptop.p3d";
		rotationFlags = 17;
		itemSize[] = {5,4};
		weight = 300;
		hiddenSelections[] = {"zbytek","lcd_1","lcd_2"};
		hiddenSelectionsTextures[] = {"TerjeElectronics\Laptop\data\laptop_co.paa","TerjeElectronics\Laptop\data\laptop_co.paa",""};
		hiddenSelectionsMaterials[] = {"TerjeElectronics\Laptop\data\laptop_mat.rvmat","TerjeElectronics\Laptop\data\laptop_mat.rvmat",""};
		attachments[]=
		{
			"BatteryD"
		};
		class EnergyManager
		{
			hasIcon=1;
			autoSwitchOffWhenInCargo=1;
			energyUsagePerSecond=0.0099999998;
			plugType=1;
			attachmentAction=1;
			updateInterval=3;
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"TerjeElectronics\Laptop\data\laptop_mat.rvmat"}},{0.7,{"TerjeElectronics\Laptop\data\laptop_mat.rvmat"}},{0.5,{"TerjeElectronics\Laptop\data\laptop_damage.rvmat"}},{0.3,{"TerjeElectronics\Laptop\data\laptop_damage.rvmat"}},{0.0,{"TerjeElectronics\Laptop\data\laptop_destruct.rvmat"}}};
				};
			};
		};
		
		class AnimationSources
		{
			class lid
			{
				source="user";
				component = "lid";
				animPeriod = 0;
				initPhase = 1.5;
			};
		};
		soundImpactType = "glass";
		class AnimEvents
		{
			class SoundWeapon
			{
				class compass_open
				{
					soundSet = "compass_open_SoundSet";
					id = 204;
				};
				class compass_close
				{
					soundSet = "compass_close_SoundSet";
					id = 205;
				};
			};
		};
	};
	/*
	class TerjeLaptop_Duty: TerjeGadgetsLaptop_ColorBase
	{
		scope = 2;
		displayName = "#STR_TerjeGadgets_PDADUTY_NAME";
		hiddenSelectionsTextures[] = {"TerjeGadgets\Laptop\data\pda_duty_co.paa"};
	};
	class TerjeLaptop_Iskra: TerjeGadgetsLaptop_ColorBase
	{
		scope = 2;
		displayName = "#STR_TerjeGadgets_PDAISKRA_NAME";
		hiddenSelectionsTextures[] = {"TerjeGadgets\Laptop\data\pda_iskra_co.paa"};
	};
	class TerjeLaptop_SOP: TerjeGadgetsLaptop_ColorBase
	{
		scope = 2;
		displayName = "#STR_TerjeGadgets_PDASOP_NAME";
		hiddenSelectionsTextures[] = {"TerjeGadgets\Laptop\data\pda_sop_co.paa"};
	};
	class TerjeLaptop_Stalker: TerjeGadgetsLaptop_ColorBase
	{
		scope = 2;
		displayName = "#STR_TerjeGadgets_PDASTALKER_NAME";
		hiddenSelectionsTextures[] = {"TerjeGadgets\Laptop\data\pda_stalker_co.paa"};
	};
	class TerjeLaptop_Varta: TerjeGadgetsLaptop_ColorBase
	{
		scope = 2;
		displayName = "#STR_TerjeGadgets_PDAVARTA_NAME";
		hiddenSelectionsTextures[] = {"TerjeGadgets\Laptop\data\pda_varta_co.paa"};
	};
	class TerjeLaptop_Volya: TerjeGadgetsLaptop_ColorBase
	{
		scope = 2;
		displayName = "#STR_TerjeGadgets_PDAVOLYA_NAME";
		hiddenSelectionsTextures[] = {"TerjeGadgets\Laptop\data\pda_volya_co.paa"};
	};
	class TerjeLaptop_Naemniki: TerjeGadgetsLaptop_ColorBase
	{
		scope = 2;
		displayName = "#STR_TerjeGadgets_PDANAEMNIK_NAME";
		hiddenSelectionsTextures[] = {"TerjeGadgets\Laptop\data\pda_naemniki_co.paa"};
	};
	*/
};
