class CfgPatches
{
	class TerjeRadiation_Injectors
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"TerjeRadiation"
		};
	};
};

class CfgVehicles
{
	class Inventory_Base;
	class TerjeAntiradInjector: Inventory_Base
	{
		scope=2;
		displayName="#STR_TERJERAD_RADIOPROTECTOR";
		model="dz\gear\medical\Epinephrine.p3d";
		debug_ItemCategory=7;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"TerjeRadiation\Injectors\radprotector_co.paa"
		};
		rotationFlags=17;
		itemSize[]={1,2};
		weight=60;
		soundImpactType="plastic";
		medAntiradLevel=3;
		medAntiradTimer=600;
		medAntiradMaxTimer=1800;
		overdosedIncrement = 0.75;
		medicalItem=1;
		medSkillExpAddToSelf=50;
		medicalInjectorsCategory=1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=50;
					healthLevels[]=
					{
						{1.0,{"DZ\gear\medical\data\epipen.rvmat"}},
						{0.7,{"DZ\gear\medical\data\epipen.rvmat"}},
						{0.5,{"DZ\gear\medical\data\epipen_damage.rvmat"}},
						{0.3,{"DZ\gear\medical\data\epipen_damage.rvmat"}},
						{0.0,{"DZ\gear\medical\data\epipen_destruct.rvmat"}}
					};
				};
			};
		};
	};
};
