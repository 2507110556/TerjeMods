class CfgPatches
{
	class TerjeMedicine_Ampouls
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
	class TerjeAmpouleBase : Inventory_Base
	{
		descriptionShort="#STR_TERJEMED_AMPOULE_DESC";
		model="dz\gear\medical\injectionvial.p3d";
		hiddenSelections[]={"zbytek"};
		itemSize[]={1,2};
		weight=100;
		quantityBar=1;
		varQuantityInit=5;
		varQuantityMin=0;
		varQuantityMax=5;
		varQuantityDestroyOnMin=1;
		stackedUnit="percentage";
		soundImpactType="glass";
		absorbency=0;
		overdosedIncrement=0.25;
		medicalItem=1;
		medicalAmpoulsCategory=1;
		medSkillExpAddToSelf=50;
		medPainkillerMaxTimeSec=1800;
		medAntipoisonMaxTimeSec=1800;
		medAntibiohazardMaxTimeSec=1800;
		medAntibioticMaxTimeSec=1800;
		medRabiesAntibioticMaxTimeSec=1800;
		medZAntidotMaxTimeSec=1800;
		medAntisepsisMaxTimeSec=1800;
		medConcussionHealMaxTimeSec=1800;
		medBloodHemostaticMaxTimeSec=1800;
		medBloodRegenMaxTimeSec=1800;
		medHematomaHealMaxTimeSec=1800;
		medAdrenalinMaxTimeSec=1800;
		medAntidepresantMaxTimeSec=1800;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						{1.0,{"dz\gear\medical\data\injectionvial.rvmat"}},
						{0.7,{"dz\gear\medical\data\injectionvial.rvmat"}},
						{0.5,{"dz\gear\medical\data\injectionvial_damage.rvmat"}},
						{0.3,{"dz\gear\medical\data\injectionvial_damage.rvmat"}},
						{0.0,{"dz\gear\medical\data\injectionvial_destruct.rvmat"}}
					};
				};
			};
		};
	};
	
	// SIMPLE AMPOULS
	class TerjeAmpouleAlcohol : TerjeAmpouleBase
	{
		scope=2;
		displayName="#STR_TERJEMED_ALCOHOL";
		varQuantityInit=10;
		varQuantityMin=0;
		varQuantityMax=10;
		overdosedIncrement=4;
		medSkillExpAddToSelf=0;
		medicalAmpoulsCategory=0;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_co.paa"};
	};
	
	class TerjeAmpouleAmoxivan : TerjeAmpouleBase
	{
		scope=2;
		displayName="#STR_TERJEMED_AMOXIVAN";
		medAntibioticLevel=2;
		medAntibioticTimeSec=900;
		overdosedIncrement=0.3;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_pink_co.paa"};
	};
	
	class TerjeAmpouleNovacaine : TerjeAmpouleBase
	{
		scope=2;
		displayName="#STR_TERJEMED_NOVOCAINE";
		medPainkillerLevel=2;
		medPainkillerTimeSec=1200;
		overdosedIncrement=0.4;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_blue_co.paa"};
	};
	
	class TerjeAmpouleMetoclopramid : TerjeAmpouleBase
	{
		scope=2;
		displayName="#STR_TERJEMED_METOCLOPRAMID";
		medAntipoisonLevel=2;
		medAntipoisonTimeSec=1200;
		overdosedIncrement=0.4;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_green_co.paa"};
	};
	
	class TerjeAmpouleNeirox : TerjeAmpouleBase
	{
		scope=2;
		displayName="#STR_TERJEMED_NEIROX";
		medConcussionHealTimeSec=600;
		overdosedIncrement=0.6;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_purple_co.paa"};
	};
	
	class TerjeAmpouleErythropoetin : TerjeAmpouleBase
	{
		scope=2;
		displayName="#STR_TERJEMED_ERYTHROPOIETIN";
		medBloodRegenValue=1;
		medBloodRegenTimeSec=600;
		overdosedIncrement=0.4;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_red_co.paa"};
	};
	
	class TerjeAmpouleAdrenalin : TerjeAmpouleBase
	{
		scope=2;
		displayName="#STR_TERJEMED_ADRENALIN";
		medAdrenalinTimeSec=220;
		overdosedIncrement=0.3;
		medSkillExpAddToSelf=10;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_yellow_co.paa"};
	};
	
	class TerjeAmpoulePentacin : TerjeAmpouleBase
	{
		scope=2;
		displayName="#STR_TERJEMED_PENTACIN";
		medAntiradLevel=2;
		medAntiradTimeSec=400;
		overdosedIncrement=0.5;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_ultrayellow_co.paa"};
	};
	
	class TerjeAmpouleMetralindole : TerjeAmpouleBase
	{
		scope=2;
		displayName="#STR_TERJEMED_METRALINDOLE";
		medAntidepresantLevel=2;
		medAntidepresantTimeSec=300;
		overdosedIncrement=0.1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_gray_co.paa"};
	};
	
	class TerjeAmpouleVaxicam : TerjeAmpouleBase
	{
		scope=2;
		displayName="#STR_TERJEMED_VAXICAM";
		medInfluenzaVacineTimeSec=14400;
		overdosedIncrement=0.8;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_vacine_a_co.paa"};
	};
	
	class TerjeAmpouleZerivax : TerjeAmpouleBase
	{
		scope=2;
		displayName="#STR_TERJEMED_ZERIVAX";
		medZVirusVacineTimeSec=7200;
		overdosedIncrement=1.5;
		medSkillExpAddToSelf=100;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_vacine_b_co.paa"};
	};
	
	class TerjeAmpouleRabivax : TerjeAmpouleBase
	{
		scope=2;
		displayName="#STR_TERJEMED_RABIVAX";
		medRabiesVacineTimeSec=14400;
		overdosedIncrement=1.3;
		medSkillExpAddToSelf=100;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_vacine_c_co.paa"};
	};
	
	class TerjeAmpouleRabinoline : TerjeAmpouleBase
	{
		scope=2;
		displayName="#STR_TERJEMED_RABINOLINE";
		medRabiesAntibioticLevel=2;
		medRabiesAntibioticTimeSec=600;
		overdosedIncrement=0.8;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_violet_co.paa"};
	};
	
	class TerjeAmpouleNeirocetal : TerjeAmpouleBase
	{
		scope=2;
		displayName="#STR_TERJEMED_NEIROCETAL";
		medAntibiohazardLevel=2;
		medAntibiohazardTimeSec=500;
		overdosedIncrement=1.25;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_neirocet_co.paa"};
	};
	
	// ADVANCED AMPOULS
	class TerjeAmpouleKetarol : TerjeAmpouleBase
	{
		scope=2;
		displayName="#STR_TERJEMED_KETAROL";
		medAntibioticLevel=2;
		medAntibioticTimeSec=1200;
		medPainkillerLevel=1;
		medPainkillerTimeSec=1200;
		overdosedIncrement=0.5;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_neoblack_co.paa"};
	};
	
	class TerjeAmpouleFlemoclav : TerjeAmpouleBase
	{
		scope=2;
		displayName="#STR_TERJEMED_FLEMOCLAV";
		medAntibioticLevel=3;
		medAntibioticTimeSec=1200;
		medAntisepsisTimeSec=1200;
		overdosedIncrement=0.8;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_toxicgrey_co.paa"};
	};
	
	class TerjeAmpouleImipenem : TerjeAmpouleBase
	{
		scope=2;
		displayName="#STR_TERJEMED_IMIPENEM";
		medAntibioticLevel=3;
		medAntibioticTimeSec=900;
		medAntisepsisTimeSec=900;
		overdosedIncrement=0.7;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_toxicgreen_co.paa"};
	};
	
	class TerjeAmpouleMorphine : TerjeAmpouleBase
	{
		scope=2;
		displayName="#STR_TERJEMED_MORPHINE";
		medPainkillerLevel=3;
		medPainkillerTimeSec=850;
		overdosedIncrement=0.52;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_azulred_co.paa"};
	};
	
	class TerjeAmpouleGexobarbital : TerjeAmpouleBase
	{
		scope=2;
		displayName="#STR_TERJEMED_GEXOBARBITAL";
		medPainkillerLevel=3;
		medPainkillerTimeSec=900;
		overdosedIncrement=0.65;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_darkorange_co.paa"};
	};
	
	class TerjeAmpouleKetamin : TerjeAmpouleBase
	{
		scope=2;
		displayName="#STR_TERJEMED_KETAMIN";
		medPainkillerLevel=3;
		medPainkillerTimeSec=600;
		overdosedIncrement=0.45;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_darkblue_co.paa"};
	};
	
	class TerjeAmpouleHeptral : TerjeAmpouleBase
	{
		scope=2;
		displayName="#STR_TERJEMED_HEPTRAL";
		medAntipoisonLevel=3;
		medAntipoisonTimeSec=600;
		overdosedIncrement=0.6;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_darkgreen_co.paa"};
	};
	
	class TerjeAmpouleCarboxyme : TerjeAmpouleBase
	{
		scope=2;
		displayName="#STR_TERJEMED_CARBOXYME";
		medAntiradLevel=2;
		medAntiradTimeSec=600;
		overdosedIncrement=0.6;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_dirtyblue_co.paa"};
	};
	
	class TerjeAmpouleActaparoxetine : TerjeAmpouleBase
	{
		scope=2;
		displayName="#STR_TERJEMED_ACTAPAROXETINE";
		medAntidepresantLevel=2;
		medAntidepresantTimeSec=400;
		overdosedIncrement=0.4;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_dirtygreen_co.paa"};
	};
	
	class TerjeAmpouleAmitriptyline : TerjeAmpouleBase
	{
		scope=2;
		displayName="#STR_TERJEMED_AMITRIPTYLINE";
		medAntidepresantLevel=3;
		medAntidepresantTimeSec=600;
		overdosedIncrement=0.5;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_dirtyred_co.paa"};
	};
	
	class TerjeAmpouleRifampicyne : TerjeAmpouleBase
	{
		scope=2;
		displayName="#STR_TERJEMED_RIFAMBICYNE";
		medRabiesAntibioticLevel=3;
		medRabiesAntibioticTimeSec=300;
		overdosedIncrement=1.35;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_lightpink_co.paa"};
	};
	
	class TerjeAmpouleZivirol : TerjeAmpouleBase
	{
		scope=2;
		displayName="#STR_TERJEMED_ZIVIROL";
		medZAntidotTimeSec=1000;
		overdosedIncrement=2.35;
		terjeAddHealth=-25;
		terjeAddBlood=-15;
		terjeAddShock=-100;
		medSkillExpAddToSelf=200;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_zivirol_co.paa"};
	};
	
	class TerjeAmpoulePotassiumCyanide : TerjeAmpouleBase
	{
		scope=2;
		displayName="#STR_TERJEMED_CYANIDE";
		overdosedIncrement=5;
		terjeAddWater=-5000;
		terjeAddEnergy=-5000;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_cyanide_co.paa"};
	};
	
	class TerjeAmpouleArsenic : TerjeAmpouleBase
	{
		scope=2;
		displayName="#STR_TERJEMED_ARSENIC";
		overdosedIncrement=5;
		terjeAddHealth=-50;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_arsenic_co.paa"};
	};
	
	class TerjeAmpouleBeladonna : TerjeAmpouleBase
	{
		scope=2;
		displayName="#STR_TERJEMED_BELADONNA";
		overdosedIncrement=3.8;
		medPainSet=5;
		medContussionLight=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_beladonna_co.paa"};
	};
	
	class TerjeAmpouleStrychnine : TerjeAmpouleBase
	{
		scope=2;
		displayName="#STR_TERJEMED_STRYCHNINE";
		overdosedIncrement=3.2;
		terjeAddWater=-5000;
		terjeAddBlood=-1000;
		medContussionHeavy=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_strychnine_co.paa"};
	};
	
	class TerjeAmpouleKonyin : TerjeAmpouleBase
	{
		scope=2;
		displayName="#STR_TERJEMED_KONYIN";
		overdosedIncrement=3;
		medSleepDamageValue=100;
		medSleepDamageTimeSec=300;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_konyin_co.paa"};
	};

	class HouseNoDestruct;
	class StaticObj_TerjeAmpoule : HouseNoDestruct
	{
		model="dz\gear\medical\injectionvial.p3d";
		hiddenSelections[]={"zbytek"};
	};
	
	class StaticObj_TerjeAmpouleAlcohol : StaticObj_TerjeAmpoule
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_co.paa"};
	};
	
	class StaticObj_TerjeAmpouleAmoxivan : StaticObj_TerjeAmpoule
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_pink_co.paa"};
	};
	
	class StaticObj_TerjeAmpouleNovacaine : StaticObj_TerjeAmpoule
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_blue_co.paa"};
	};
	
	class StaticObj_TerjeAmpouleMetoclopramid : StaticObj_TerjeAmpoule
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_green_co.paa"};
	};
	
	class StaticObj_TerjeAmpouleNeirox : StaticObj_TerjeAmpoule
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_purple_co.paa"};
	};
	
	class StaticObj_TerjeAmpouleErythropoetin : StaticObj_TerjeAmpoule
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_red_co.paa"};
	};
	
	class StaticObj_TerjeAmpouleAdrenalin : StaticObj_TerjeAmpoule
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_yellow_co.paa"};
	};
	
	class StaticObj_TerjeAmpoulePentacin : StaticObj_TerjeAmpoule
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_ultrayellow_co.paa"};
	};
	
	class StaticObj_TerjeAmpouleMetralindole : StaticObj_TerjeAmpoule
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_gray_co.paa"};
	};
	
	class StaticObj_TerjeAmpouleVaxicam : StaticObj_TerjeAmpoule
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_vacine_a_co.paa"};
	};
	
	class StaticObj_TerjeAmpouleZerivax : StaticObj_TerjeAmpoule
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_vacine_b_co.paa"};
	};
	
	class StaticObj_TerjeAmpouleRabivax : StaticObj_TerjeAmpoule
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_vacine_c_co.paa"};
	};
	
	class StaticObj_TerjeAmpouleRabinoline : StaticObj_TerjeAmpoule
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_violet_co.paa"};
	};
	
	class StaticObj_TerjeAmpouleNeirocetal : StaticObj_TerjeAmpoule
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_neirocet_co.paa"};
	};

	class StaticObj_TerjeAmpouleKetarol : StaticObj_TerjeAmpoule
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_neoblack_co.paa"};
	};
	
	class StaticObj_TerjeAmpouleFlemoclav : StaticObj_TerjeAmpoule
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_toxicgrey_co.paa"};
	};
	
	class StaticObj_TerjeAmpouleImipenem : StaticObj_TerjeAmpoule
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_toxicgreen_co.paa"};
	};
	
	class StaticObj_TerjeAmpouleMorphine : StaticObj_TerjeAmpoule
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_azulred_co.paa"};
	};
	
	class StaticObj_TerjeAmpouleGexobarbital : StaticObj_TerjeAmpoule
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_darkorange_co.paa"};
	};
	
	class StaticObj_TerjeAmpouleKetamin : StaticObj_TerjeAmpoule
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_darkblue_co.paa"};
	};
	
	class StaticObj_TerjeAmpouleHeptral : StaticObj_TerjeAmpoule
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_darkgreen_co.paa"};
	};
	
	class StaticObj_TerjeAmpouleCarboxyme : StaticObj_TerjeAmpoule
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_dirtyblue_co.paa"};
	};
	
	class StaticObj_TerjeAmpouleActaparoxetine : StaticObj_TerjeAmpoule
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_dirtygreen_co.paa"};
	};
	
	class StaticObj_TerjeAmpouleAmitriptyline : StaticObj_TerjeAmpoule
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_dirtyred_co.paa"};
	};
	
	class StaticObj_TerjeAmpouleRifampicyne : StaticObj_TerjeAmpoule
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_lightpink_co.paa"};
	};
	
	class StaticObj_TerjeAmpouleZivirol : StaticObj_TerjeAmpoule
	{
		scope=1;
		hiddenSelectionsTextures[]={"TerjeMedicine\Ampouls\data\ampoule_zivirol_co.paa"};
	};
};
