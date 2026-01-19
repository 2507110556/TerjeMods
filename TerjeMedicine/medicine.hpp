class Medicine
{
	id="med";
	enabled=1;
	displayName="#STR_TERJESKILL_MED_NAME";
	description="#STR_TERJESKILL_MED_DESC";
	icon="set:TerjeSkills_icon image:ts_med";
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
		class SurgeryStabWound
		{
			id="surgsw";
			enabled=1;
			displayName="#STR_TERJEPERK_MED_SURGERYSTABWOUND";
			description="#STR_TERJEPERK_MED_SURGERYSTABWOUND_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_surgerystab";
			enabledIcon="set:TerjePerk_icon image:tp_surgerystab";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,1,2};
			values[]={0.1,0.2,0.3,0.5,0.75,1.0};
		};
		class SurgeryBulletWound
		{
			id="surgbw";
			enabled=1;
			displayName="#STR_TERJEPERK_MED_SURGERYBULLETWOUND";
			description="#STR_TERJEPERK_MED_SURGERYBULLETWOUND_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_surgerybullet";
			enabledIcon="set:TerjePerk_icon image:tp_surgerybullet";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,1,2};
			values[]={0.1,0.2,0.3,0.5,0.75,1.0};
		};
		class SurgeryInternalWound
		{
			id="surgint";
			enabled=1;
			displayName="#STR_TERJEPERK_MED_SURGERYINTERNAL";
			description="#STR_TERJEPERK_MED_SURGERYINTERNAL_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_surgeryinternal";
			enabledIcon="set:TerjePerk_icon image:tp_surgeryinternal";
			requiredSkillLevels[]={5,10,15,20,25,30};
			requiredPerkPoints[]={1,1,1,1,1,2};
			values[]={0.1,0.2,0.3,0.5,0.75,1.0};
		};
		class CleanlinessSterility
		{
			id="cleanstr";
			enabled=1;
			displayName="#STR_TERJEPERK_MED_CLEANLINESS";
			description="#STR_TERJEPERK_MED_CLEANLINESS_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_cleanliness";
			enabledIcon="set:TerjePerk_icon image:tp_cleanliness";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,1,1};
			values[]={-0.05,-0.10,-0.15,-0.25,-0.50,-0.75};
		};
		class Pharmacologist
		{
			id="pharmac";
			enabled=1;
			displayName="#STR_TERJEPERK_MED_PHARMACOLOGIST";
			description="#STR_TERJEPERK_MED_PHARMACOLOGIST_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_pharmacologist";
			enabledIcon="set:TerjePerk_icon image:tp_pharmacologist";
			requiredSkillLevels[]={5,10,15,20,25,30};
			requiredPerkPoints[]={1,1,1,1,1,2};
			values[]={0.05,0.10,0.25,0.5,0.75,1.0};
		};
		class MasterDressing
		{
			id="mastdress";
			enabled=1;
			displayName="#STR_TERJEPERK_MED_MASTERDRESSING";
			description="#STR_TERJEPERK_MED_MASTERDRESSING_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_masterdressing";
			enabledIcon="set:TerjePerk_icon image:tp_masterdressing";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,1,1};
			values[]={-0.1,-0.2,-0.3,-0.4,-0.5,-0.75};
		};
		class Surgeon
		{
			id="surgeon";
			enabled=1;
			displayName="#STR_TERJEPERK_MED_SURGEON";
			description="#STR_TERJEPERK_MED_SURGEON_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_surgeon";
			enabledIcon="set:TerjePerk_icon image:tp_surgeon";
			requiredSkillLevels[]={5,10,15,20,25,30};
			requiredPerkPoints[]={1,1,1,1,1,2};
			values[]={-0.05,-0.1,-0.2,-0.3,-0.5,-0.75};
		};
		class BringingLife
		{
			id="brnlife";
			enabled=1;
			displayName="#STR_TERJEPERK_MED_BRINGINGLIFE";
			description="#STR_TERJEPERK_MED_BRINGINGLIFE_DES";
			stagesCount=1;
			disabledIcon="set:TerjePerkBlack_icon image:tp_crushingsquall";
			enabledIcon="set:TerjePerk_icon image:tp_crushingsquall";
			requiredSkillLevels[]={1};
			requiredPerkPoints[]={1};
			values[]={0.0};
		};
		class PillRecognition
		{
			id="pillrecog";
			enabled=1;
			displayName="#STR_TERJEPERK_MED_PILLRECOGNITION";
			description="#STR_TERJEPERK_MED_PILLRECOGNITION_DES";
			stagesCount=1;
			disabledIcon="set:TerjePerkBlack_icon image:tp_pilrecognition";
			enabledIcon="set:TerjePerk_icon image:tp_pilrecognition";
			requiredSkillLevels[]={1};
			requiredPerkPoints[]={1};
			values[]={0.0};
		};
		class AmpouleRecognition
		{
			id="amplrecog";
			enabled=1;
			displayName="#STR_TERJEPERK_MED_AMPOULERECOGNITION";
			description="#STR_TERJEPERK_MED_AMPOULERECOGNITION_DES";
			stagesCount=1;
			disabledIcon="set:TerjePerkBlack_icon image:tp_ampoulerecognition";
			enabledIcon="set:TerjePerk_icon image:tp_ampoulerecognition";
			requiredSkillLevels[]={10};
			requiredPerkPoints[]={1};
			values[]={0.0};
		};
		class InjectorRecognition
		{
			id="injrecog";
			enabled=1;
			displayName="#STR_TERJEPERK_MED_INJECTORRECOGNITION";
			description="#STR_TERJEPERK_MED_INJECTORRECOGNITION_DES";
			stagesCount=1;
			disabledIcon="set:TerjePerkBlack_icon image:tp_injectorrecognition";
			enabledIcon="set:TerjePerk_icon image:tp_injectorrecognition";
			requiredSkillLevels[]={20};
			requiredPerkPoints[]={1};
			values[]={0.0};
		};
		class Stethoscope
		{
			id="stethscp";
			enabled=1;
			displayName="#STR_TERJEPERK_MED_STETHOSCOPE";
			description="#STR_TERJEPERK_MED_STETHOSCOPE_DES";
			stagesCount=3;
			disabledIcon="set:TerjePerkBlack_icon image:tp_stethoscope";
			enabledIcon="set:TerjePerk_icon image:tp_stethoscope";
			requiredSkillLevels[]={5,15,30};
			requiredPerkPoints[]={1,1,1};
			values[]={0.0,0.0,0.0};
			hints[]={"#STR_TERJEPERK_MED_STETHOSCOPE_HINT_1", "#STR_TERJEPERK_MED_STETHOSCOPE_HINT_2", "#STR_TERJEPERK_MED_STETHOSCOPE_HINT_3"};
		};
		class ExpertAntibiotics
		{
			id="expantib";
			enabled=1;
			displayName="#STR_TERJEPERK_MED_EXPERTANTIBIOTICS";
			description="#STR_TERJEPERK_MED_EXPERTANTIBIOTICS_DES";
			stagesCount=1;
			disabledIcon="set:TerjePerkBlack_icon image:tp_expertantibiotics";
			enabledIcon="set:TerjePerk_icon image:tp_expertantibiotics";
			requiredSkillLevels[]={40};
			requiredPerkPoints[]={2};
			values[]={0.0};
		};
		class Anesthesiolog
		{
			id="anestlog";
			enabled=1;
			displayName="#STR_TERJEPERK_MED_ANESTHESIOLOGIST";
			description="#STR_TERJEPERK_MED_ANESTHESIOLOGIST_DES";
			stagesCount=1;
			disabledIcon="set:TerjePerkBlack_icon image:tp_anesthesiolog";
			enabledIcon="set:TerjePerk_icon image:tp_anesthesiolog";
			requiredSkillLevels[]={40};
			requiredPerkPoints[]={3};
			values[]={0.0};
		};
	};
};
