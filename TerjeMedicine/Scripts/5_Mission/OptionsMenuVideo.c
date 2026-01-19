modded class OptionsMenuVideo
{
	override void OnPPQualityChanged( int value )
	{
		if (value == 0)
		{
			// Forces post-processing quality from low to medium so that the pain effect cannot be disabled in the game settings.
			value = 1;
		}
		
		super.OnPPQualityChanged(value);
	}
}