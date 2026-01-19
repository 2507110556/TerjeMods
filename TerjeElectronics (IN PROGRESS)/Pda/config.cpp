class CfgPatches
{
	class TerjeElectronics_PDA
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"TerjeElectronics"};
	};
};
class CfgVehicles
{
	class TerjeGadgetBase;
	class TerjePda_ColorBase: TerjeGadgetBase
	{
		scope = 2;
		displayName = "#STR_TERJEPDA_PDA_NAME";
		descriptionShort = "#STR_TERJEPDA_DESC";
		model = "\TerjeElectronics\Pda\TerjePDA.p3d";
		rotationFlags = 17;
		itemSize[] = {2,2};
		weight = 300;
		hiddenSelections[] = {"zbytek","lcd_1","lcd_2"};
		hiddenSelectionsTextures[] = {"TerjeElectronics\Pda\data\pda_co.paa","TerjeElectronics\Pda\data\lcd_co.paa",""};
		hiddenSelectionsMaterials[] = {"TerjeElectronics\Pda\data\pda_mat.rvmat","TerjeElectronics\Pda\data\lcd_mat.rvmat",""};
		soundImpactType="plastic";
		hardwareClass="TerjeHardwarePDA";
		softwareClass="TerjeSoftwareStalker";
		programsClassList[]={
			"TerjeProgramCalculator",
			"TerjeProgramBrowser",
			"TerjeProgramClock",
			"TerjeProgramGallery",
			"TerjeProgramMail",
			"TerjeProgramMaps",
			"TerjeProgramMessenger",
			"TerjeProgramMusic",
			"TerjeProgramNotes",
			"TerjeProgramRadio",
			"TerjeProgramTetris",
			"TerjeProgramSettings",
		};
		repairableWithKits[]={7};
		repairCosts[]={50};
		attachments[]=
		{
			"BatteryD"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"TerjeElectronics\Pda\data\pda_mat.rvmat"}},{0.7,{"TerjeElectronics\Pda\data\pda_mat.rvmat"}},{0.5,{"TerjeElectronics\Pda\data\pda_damage.rvmat"}},{0.3,{"TerjeElectronics\Pda\data\pda_damage.rvmat"}},{0.0,{"TerjeElectronics\Pda\data\pda_destruct.rvmat"}}};
				};
			};
		};
	};
	/*
	class TerjePda_Duty: TerjePda_ColorBase
	{
		scope = 2;
		displayName = "#STR_TERJEPDA_PDADUTY_NAME";
		hiddenSelectionsTextures[] = {"TerjeElectronics\Pda\data\pda_duty_co.paa"};
	};
	class TerjePda_Iskra: TerjePda_ColorBase
	{
		scope = 2;
		displayName = "#STR_TERJEPDA_PDAISKRA_NAME";
		hiddenSelectionsTextures[] = {"TerjeElectronics\Pda\data\pda_iskra_co.paa"};
	};
	class TerjePda_SOP: TerjePda_ColorBase
	{
		scope = 2;
		displayName = "#STR_TERJEPDA_PDASOP_NAME";
		hiddenSelectionsTextures[] = {"TerjeElectronics\Pda\data\pda_sop_co.paa"};
	};
	class TerjePda_Stalker: TerjePda_ColorBase
	{
		scope = 2;
		displayName = "#STR_TERJEPDA_PDASTALKER_NAME";
		hiddenSelectionsTextures[] = {"TerjeElectronics\Pda\data\pda_stalker_co.paa"};
	};
	class TerjePda_Varta: TerjePda_ColorBase
	{
		scope = 2;
		displayName = "#STR_TERJEPDA_PDAVARTA_NAME";
		hiddenSelectionsTextures[] = {"TerjeElectronics\Pda\data\pda_varta_co.paa"};
	};
	class TerjePda_Volya: TerjePda_ColorBase
	{
		scope = 2;
		displayName = "#STR_TERJEPDA_PDAVOLYA_NAME";
		hiddenSelectionsTextures[] = {"TerjeElectronics\Pda\data\pda_volya_co.paa"};
	};
	class TerjePda_Naemniki: TerjePda_ColorBase
	{
		scope = 2;
		displayName = "#STR_TERJEPDA_PDANAEMNIK_NAME";
		hiddenSelectionsTextures[] = {"TerjeElectronics\Pda\data\pda_naemniki_co.paa"};
	};
	*/
};
