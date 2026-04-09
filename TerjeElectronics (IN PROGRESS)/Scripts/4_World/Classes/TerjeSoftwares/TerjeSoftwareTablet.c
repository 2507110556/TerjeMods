class TerjeSoftwareTablet : TerjeSoftwareBase
{
	protected EffectSound m_bootSound = null;
	
	override void OnUpdate(float deltaTime)
	{
		super.OnUpdate(deltaTime);
		
		if (g_Game && GetGadget())
		{
			if (g_Game.IsDedicatedServer())
			{
				SetBootTimer(GetBootTimer() + deltaTime);
				if (GetBootMode() == TerjeSoftwareBootMode.INIT)
				{
					if (GetBootTimer() >= GetBootInitTime())
					{
						SetBootTimer(0);
						SetBootMode(TerjeSoftwareBootMode.LOADING);
					}
				}
				else if (GetBootMode() == TerjeSoftwareBootMode.LOADING)
				{
					if (GetBootTimer() >= GetBootLoadingTime())
					{
						SetBootTimer(0);
						SetBootMode(TerjeSoftwareBootMode.WORKSPACE);
					}
				}
			}
		}
	}
	
	override void OnPowerModeChanged(TerjeHardwarePowerMode oldState, TerjeHardwarePowerMode newState)
	{
		super.OnPowerModeChanged(oldState, newState);
		
		if (g_Game && g_Game.IsDedicatedServer())
		{
			if (newState == TerjeHardwarePowerMode.DISABLED)
			{
				SetBootMode(TerjeSoftwareBootMode.DISABLED);
				CloseProgram();
			}
			else if (oldState == TerjeHardwarePowerMode.DISABLED)
			{
				if (newState == TerjeHardwarePowerMode.ENABLED)
				{
					SetBootMode(TerjeSoftwareBootMode.INIT);
				}
			}
			else if (oldState == TerjeHardwarePowerMode.HIBERNATED)
			{
				if (newState == TerjeHardwarePowerMode.ENABLED)
				{
					if (GetPasslock() != string.Empty)
					{
						SetBootMode(TerjeSoftwareBootMode.LOCKSCREEN);
					}
					else
					{
						SetBootMode(TerjeSoftwareBootMode.WORKSPACE);
					}
				}
			}
		}
	}
	
	override void OnBootModeChanged(TerjeSoftwareBootMode oldState, TerjeSoftwareBootMode newState)
	{
		super.OnBootModeChanged(oldState, newState);
		
		if (GetGadget() && g_Game)
		{
			if (g_Game.IsClient())
			{
				if (m_bootSound && m_bootSound.IsPlaying())
				{
					m_bootSound.Stop();
				}
				
				if (newState == TerjeSoftwareBootMode.INIT)
				{
					SetBootTimer(g_Game.GetTickTime());
					
					string bootInitSound = GetBootInitSoundSetName();
					if (bootInitSound != string.Empty)
					{
						GetGadget().PlaySoundSet(m_bootSound, bootInitSound, 1, 1, false);
					}
				}
				else if (newState == TerjeSoftwareBootMode.LOADING)
				{
					SetBootTimer(g_Game.GetTickTime());
				}
			}
			else if (g_Game.IsDedicatedServer())
			{
				if (newState == TerjeSoftwareBootMode.INIT)
				{
					SetBootTimer(0);
				}
			}
		}
	}
	
	override void PlaySoundClick()
	{
		PlaySound("TerjeGadgetTouchClick_SoundSet");
	}
	
	protected string GetBootInitSoundSetName()
	{
		return "TerjeGadgetTabletBoot_SoundSet";
	}
	
	protected float GetBootInitTime()
	{
		return 12;
	}
	
	protected float GetBootLoadingTime()
	{
		return 10;
	}
}