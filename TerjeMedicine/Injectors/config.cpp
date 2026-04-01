class CfgPatches
{
	class TerjeMedicine_Injectors
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
	class TerjeInjectorBase : Inventory_Base
	{
		descriptionShort="#STR_TERJEMED_INJECTOR_DESC";
		model="dz\gear\medical\morphine.p3d";
		hiddenSelections[]={"zbytek"};
		rotationFlags=17;
		itemSize[]={1,2};
		weight=60;
		overdosedIncrement=0.4;
		medicalItem=1;
		medSkillExpAddToSelf=100;
		medicalInjectorsCategory=1;
		medPainkillerMaxTimeSec=1800;
		medAntipoisonMaxTimeSec=1800;
		medAntibiohazardMaxTimeSec=1800;
		medAntibioticsMaxTimeSec=1800;
		medRabiesAntibioticMaxTimeSec=1800;
		medZAntidotMaxTimeSec=1800;
		medAntisepsisMaxTimeSec=1800;
		medConcussionHealMaxTimeSec=1800;
		medBloodHemostaticMaxTimeSec=1800;
		medBloodRegenMaxTimeSec=1800;
		medHematomaHealMaxTimeSec=1800;
		medAdrenalinMaxTimeSec=1800;
		medAntidepresantMaxTimer=1800;
		medHealthgainMaxTimeSec=1800;
		class AnimEvents
		{
			class SoundWeapon
			{
				class Morphine_spear
				{
					soundSet="Morphine_spear_SoundSet";
					id=201;
				};
				class Morphine_out
				{
					soundSet="Morphine_out_SoundSet";
					id=202;
				};
			};
		};
	};
	
	// Compatibility
	class TerjeAntiradInjector : Inventory_Base
	{
		descriptionShort="#STR_TERJEMED_INJECTOR_DESC";
	};
	
	// Basic
	class Epinephrine: Inventory_Base
	{
		descriptionShort="#STR_TERJEMED_INJECTOR_DESC";
		medAdrenalinTimeSec=720;
		overdosedIncrement=0.55;
		medicalItem=1;
		medSkillExpAddToSelf=50;
		medicalInjectorsCategory=1;
	};
	
	class Morphine: Inventory_Base
	{
		descriptionShort="#STR_TERJEMED_INJECTOR_DESC";
		medPainkillerLevel=3;
		medPainkillerTimeSec=300;
		overdosedIncrement=0.75;
		medicalItem=1;
		medicalInjectorsCategory=1;
	};
	
	class AntiChemInjector: Inventory_Base
	{
		descriptionShort="#STR_TERJEMED_INJECTOR_DESC";
		medAntibiohazardLevel=3;
		medAntibiohazardTimeSec=180;
		overdosedIncrement=1.1;
		medicalItem=1;
		medicalInjectorsCategory=1;
	};
	
	class TerjeInjectorZivirol : TerjeInjectorBase
	{
		scope=2;
		displayName="#STR_TERJEMED_ZIVIROL";
		medZAntidotTimeSec=1200;
		overdosedIncrement=2.5;
		terjeAddHealth=-20;
		terjeAddBlood=-10;
		terjeAddShock=-100;
		medSkillExpAddToSelf=250;
		hiddenSelectionsTextures[]={"TerjeMedicine\Injectors\data\injector_purple_co.paa"};
	};
	
	class TerjeInjectorAmoxiclav : TerjeInjectorBase
	{
		scope=2;
		displayName="#STR_TERJEMED_AMOXICLAV";
		medAntibioticLevel=3;
		medAntibioticsTimeSec=1800;
		medAntisepsisTimeSec=300;
		overdosedIncrement=0.6;
		hiddenSelectionsTextures[]={"TerjeMedicine\Injectors\data\injector_blue_co.paa"};
	};
	
	class TerjeInjectorNeirox : TerjeInjectorBase
	{
		scope=2;
		displayName="#STR_TERJEMED_NEIROX";
		medConcussionHealTimeSec=500;
		overdosedIncrement=0.3;
		hiddenSelectionsTextures[]={"TerjeMedicine\Injectors\data\injector_agua_co.paa"};
	};
	
	class TerjeInjectorErythropoietin : TerjeInjectorBase
	{
		scope=2;
		displayName="#STR_TERJEMED_ERYTHROPOIETIN";
		medBloodRegenValue=1;
		medBloodRegenTimeSec=900;
		overdosedIncrement=0.4;
		hiddenSelectionsTextures[]={"TerjeMedicine\Injectors\data\injector_darkred_co.paa"};
	};
	
	class TerjeInjectorNovichek : TerjeInjectorBase
	{
		scope=2;
		displayName="#STR_TERJEMED_NOVICHEK";
		overdosedIncrement=5;
		biohazardIncrement=5;
		terjeAddShock=-100;
		medSkillExpAddToSelf=10;
		hiddenSelectionsTextures[]={"TerjeMedicine\Injectors\data\injector_black_co.paa"};
	};
	
	// Advanced
	class TerjeInjectorPromidol: TerjeInjectorBase
	{
		scope=2;
		displayName="#STR_TERJEMED_PROMIDOL";
		medPainkillerLevel=3;
		medPainkillerTimeSec=600;
		overdosedIncrement=0.45;
		hiddenSelectionsTextures[]={"TerjeMedicine\Injectors\data\injector_viogreen_co.paa"};
	};
	
	class TerjeInjectorTopoizomeraza: TerjeInjectorBase
	{
		scope=2;
		displayName="#STR_TERJEMED_TOPOIZOMERAZA";
		medAntibioticLevel=3;
		medAntibioticsTimeSec=900;
		medAntisepsisTimeSec=600;
		overdosedIncrement=0.65;
		hiddenSelectionsTextures[]={"TerjeMedicine\Injectors\data\injector_pinkred_co.paa"};
	};
	
	class TerjeInjectorErytromixelin: TerjeInjectorBase
	{
		scope=2;
		displayName="#STR_TERJEMED_ERYTROMIXELIN";
		medBloodHemostaticValue=3;
		medBloodHemostaticTimeSec=300;
		medBloodRegenValue=2;
		medBloodRegenTimeSec=150;
		overdosedIncrement=0.32;
		hiddenSelectionsTextures[]={"TerjeMedicine\Injectors\data\injector_orangebrown_co.paa"};
	};
	
	class TerjeInjectorStomaproxidal: TerjeInjectorBase
	{
		scope=2;
		displayName="#STR_TERJEMED_STOMAPROXIDAL";
		medAntipoisonLevel=3;
		medAntipoisonTimeSec=900;
		overdosedIncrement=0.68;
		hiddenSelectionsTextures[]={"TerjeMedicine\Injectors\data\injector_dirtyviolete_co.paa"};
	};
	
	class TerjeInjectorRabinucoline: TerjeInjectorBase
	{
		scope=2;
		displayName="#STR_TERJEMED_RABINUCOLINE";
		medRabiesAntibioticLevel=3;
		medRabiesAntibioticTimeSec=900;
		overdosedIncrement=1.46;
		hiddenSelectionsTextures[]={"TerjeMedicine\Injectors\data\injector_celugreen_co.paa"};
	};
	
	class TerjeInjectorAmfitalicyne : TerjeInjectorBase
	{
		scope=2;
		displayName="#STR_TERJEMED_AMFITALICYNE";
		medAntidepresantLevel=3;
		medAntidepresantTimer=520;
		overdosedIncrement=0.6;
		hiddenSelectionsTextures[]={"TerjeMedicine\Injectors\data\injector_bluered_co.paa"};
	};
	
	class TerjeInjectorReanimatal : TerjeInjectorBase
	{
		scope=2;
		displayName="#STR_TERJEMED_REANIMATAL";
		medPainkillerLevel=3;
		medPainkillerTimeSec=240;
		medHealthgainTimeSec=180;
		terjeAddShock=-75;
		overdosedIncrement=1.5;
		hiddenSelectionsTextures[]={"TerjeMedicine\Injectors\data\injector_infistar_co.paa"};
	};
	
	class TerjeInjectorPropital : TerjeInjectorBase
	{
		scope=2;
		displayName="#STR_TERJEMED_PROPITAL";
		medPainkillerLevel=2;
		medPainkillerTimeSec=180;
		medHealthgainTimeSec=45;
		overdosedIncrement=0.75;
		hiddenSelectionsTextures[]={"TerjeMedicine\Injectors\data\injector_propital_co.paa"};
	};

	class HouseNoDestruct;
	class StaticObj_TerjeEpinephrine: HouseNoDestruct
	{
		scope=1;
		model="dz\gear\medical\Epinephrine.p3d";
	};
	class StaticObj_TerjeMorphine: HouseNoDestruct
	{
		scope=1;
		model="dz\gear\medical\morphine.p3d";
	};
	class StaticObj_AntiChemInjector: HouseNoDestruct
	{
		scope=1;
		model="dz\gear\medical\Epinephrine.p3d";
		hiddenSelections[]={"zbytek"};
		hiddenSelectionsTextures[]={"dz\gear\medical\data\antidote_co.paa"};
	};
	
	class StaticObj_TerjeInjector: HouseNoDestruct
	{
		model="dz\gear\medical\morphine.p3d";
		hiddenSelections[]={"zbytek"};
	};
	class StaticObj_TerjeInjectorZivirol : StaticObj_TerjeInjector
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Injectors\data\injector_purple_co.paa"};
	};
	class StaticObj_TerjeInjectorAmoxiclav : StaticObj_TerjeInjector
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Injectors\data\injector_blue_co.paa"};
	};
	class StaticObj_TerjeInjectorNeirox : StaticObj_TerjeInjector
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Injectors\data\injector_agua_co.paa"};
	};
	class StaticObj_TerjeInjectorErythropoietin : StaticObj_TerjeInjector
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Injectors\data\injector_darkred_co.paa"};
	};
	class StaticObj_TerjeInjectorNovichek : StaticObj_TerjeInjector
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Injectors\data\injector_black_co.paa"};
	};
	class StaticObj_TerjeInjectorPromidol: StaticObj_TerjeInjector
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Injectors\data\injector_viogreen_co.paa"};
	};
	class StaticObj_TerjeInjectorTopoizomeraza: StaticObj_TerjeInjector
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Injectors\data\injector_pinkred_co.paa"};
	};
	class StaticObj_TerjeInjectorErytromixelin: StaticObj_TerjeInjector
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Injectors\data\injector_orangebrown_co.paa"};
	};
	class StaticObj_TerjeInjectorStomaproxidal: StaticObj_TerjeInjector
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Injectors\data\injector_dirtyviolete_co.paa"};
	};
	class StaticObj_TerjeInjectorRabinucoline: StaticObj_TerjeInjector
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Injectors\data\injector_celugreen_co.paa"};
	};
	class StaticObj_TerjeInjectorAmfitalicyne : StaticObj_TerjeInjector
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Injectors\data\injector_bluered_co.paa"};
	};
	class StaticObj_TerjeInjectorReanimatal : StaticObj_TerjeInjector
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Injectors\data\injector_infistar_co.paa"};
	};
	class StaticObj_TerjeInjectorPropital : StaticObj_TerjeInjector
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Injectors\data\injector_propital_co.paa"};
	};
};
