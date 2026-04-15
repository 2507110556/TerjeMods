class TerjeSoundEmitter extends House
{
	SoundOnVehicle m_soundEffect;
	
	void TerjeSoundEmitter()
	{
		if ( g_Game.IsDedicatedServer() )
		{
			g_Game.GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater(AutoDeleteIntenalCall, GetLifeTime(), false);
		}
		
		if ( !g_Game.IsDedicatedServer() )
		{
			PlaySoundInternal();
		}
	}
	
	void ~TerjeSoundEmitter() 
	{
		if ( !g_Game.IsDedicatedServer() )
		{
			if ( m_soundEffect )
			{
				g_Game.ObjectDelete( m_soundEffect );
				m_soundEffect = null;
			}
		}
	}
	
	private void AutoDeleteIntenalCall()
	{
		if ( g_Game.IsDedicatedServer() )
		{
			g_Game.ObjectDelete( this );
		}
	}
	
	private void PlaySoundInternal()
	{
		if ( !g_Game.IsDedicatedServer() )
		{
			m_soundEffect = PlaySound(GetSound(), GetRange(), true);	
		}
	}
	
	protected int GetLifeTime()
	{
		float sec = GetTerjeGameConfig().ConfigGetFloat("CfgVehicles " + GetType() + " emitterLifetime");
		return (int)(sec * 1000);
	}
	
	protected float GetRange()
	{
		return GetTerjeGameConfig().ConfigGetFloat("CfgVehicles " + GetType() + " emitterRange");
	}
	
	protected string GetSound()
	{
		return GetTerjeGameConfig().ConfigGetTextOut("CfgVehicles " + GetType() + " emitterSound");
	}
}