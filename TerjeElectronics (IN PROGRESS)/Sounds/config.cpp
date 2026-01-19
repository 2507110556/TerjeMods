class CfgPatches
{
	class TerjeElectronics_Sounds
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"TerjeElectronics"
		};
	};
};

class CfgSoundShaders
{
	class TerjeGadgetButtonClick_SoundShader
	{
		samples[] = {
			{"\TerjeElectronics\Sounds\button_click_0", 1.0},
			{"\TerjeElectronics\Sounds\button_click_1", 1.0}
		};
		volume = 1.0;
		range = 2.5;
	};
	class TerjeGadgetTouchClick_SoundShader
	{
		samples[] = {
			{"\TerjeElectronics\Sounds\touch_click_0", 1.0}
		};
		volume = 1.0;
		range = 2.5;
	};
	class TerjeGadgetTabletBoot_SoundShader
	{
		samples[] = {
			{"\TerjeElectronics\Sounds\tablet_boot", 1.0}
		};
		volume = 1.0;
		range = 2.5;
	};
};
class CfgSoundSets
{
	class TerjeGadgetButtonClick_SoundSet
	{
		sound3DProcessingType = "infected3DProcessingType";
		volumeCurve = "infectedAttenuationCurve";
		spatial = 1;
		doppler = 0;
		loop = 0;
		soundShaders[] = {"TerjeGadgetButtonClick_SoundShader"};
	};
	class TerjeGadgetTouchClick_SoundSet
	{
		sound3DProcessingType = "infected3DProcessingType";
		volumeCurve = "infectedAttenuationCurve";
		spatial = 1;
		doppler = 0;
		loop = 0;
		soundShaders[] = {"TerjeGadgetTouchClick_SoundShader"};
	};
	class TerjeGadgetTabletBoot_SoundSet
	{
		sound3DProcessingType = "infected3DProcessingType";
		volumeCurve = "infectedAttenuationCurve";
		spatial = 1;
		doppler = 0;
		loop = 0;
		soundShaders[] = {"TerjeGadgetTabletBoot_SoundShader"};
	};
};
