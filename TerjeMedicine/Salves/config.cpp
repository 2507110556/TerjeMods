class CfgPatches
{
	class TerjeMedicine_Salves
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"TerjeMedicine"
		};
	};
};

class CfgVehicles
{
	class Inventory_Base;
	
	class TerjeSalveBase : Inventory_Base
	{
		descriptionShort="#STR_TERJEMED_SALVE_DESC";
		model="\TerjeMedicine\Salves\cosmetic_tube.p3d";
		rotationFlags=17;
		itemSize[]={1,2};
		weight=120;
		quantityBar=1;
		varQuantityInit=5;
		varQuantityMin=0;
		varQuantityMax=5;
		varQuantityDestroyOnMin=1;
		absorbency=0;
		overdosedIncrement=0.01;
		medicalItem=1;
		hiddenSelections[] = {"zbytek"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1,{"TerjeMedicine\Salves\data\cosmetic_tube_mat.rvmat"}},{0.7,{"TerjeMedicine\Salves\data\cosmetic_tube_mat.rvmat"}},{0.5,{"TerjeMedicine\Salves\data\cosmetic_tube_mat_damage.rvmat"}},{0.3,{"TerjeMedicine\Salves\data\cosmetic_tube_mat_damage.rvmat"}},{0,{"TerjeMedicine\Salves\data\cosmetic_tube_mat_destruct.rvmat"}}};
				};
			};
		};
	};

	class TerjeSalveFinalgon : TerjeSalveBase
	{
		scope=2;
		displayName="#STR_TERJEMED_FINALGON";
		medHematomaHeal=1;
		medHematomaHealTimeSec=300;
		hiddenSelectionsTextures[] = {"TerjeMedicine\Salves\data\finalgon_co.paa"};
	};

	class TerjeSalveCapsicum : TerjeSalveBase
	{
		scope=2;
		displayName="#STR_TERJEMED_CAPSICUM";
		medHematomaHeal=1;
		medHematomaHealTimeSec=400;
		hiddenSelectionsTextures[] = {"TerjeMedicine\Salves\data\capsicum_co.paa"};
	};

	class TerjeSalveViprosal : TerjeSalveBase
	{
		scope=2;
		displayName="#STR_TERJEMED_VIPROSAL";
		medHematomaHeal=1;
		medHematomaHealTimeSec=600;
		hiddenSelectionsTextures[] = {"TerjeMedicine\Salves\data\viprosal_co.paa"};
	};

	class HouseNoDestruct;
	class StaticObj_TerjeSalveFinalgon : HouseNoDestruct
	{
		scope=1;
		model="\TerjeMedicine\Salves\cosmetic_tube.p3d";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"TerjeMedicine\Salves\data\finalgon_co.paa"};
	};

	class StaticObj_TerjeSalveCapsicum : HouseNoDestruct
	{
		scope=1;
		model="\TerjeMedicine\Salves\cosmetic_tube.p3d";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"TerjeMedicine\Salves\data\capsicum_co.paa"};
	};

	class StaticObj_TerjeSalveViprosal : HouseNoDestruct
	{
		scope=1;
		model="\TerjeMedicine\Salves\cosmetic_tube.p3d";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"TerjeMedicine\Salves\data\viprosal_co.paa"};
	};
};