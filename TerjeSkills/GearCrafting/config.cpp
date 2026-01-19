class CfgPatches
{
	class TerjeSkills_GearCrafting
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"TerjeSkills",
			"DZ_Gear_Crafting"
		};
	};
};

class CfgVehicles
{
	class Inventory_Base;
	class HandDrillKit: Inventory_Base
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
				};
			};
		};
	};
};