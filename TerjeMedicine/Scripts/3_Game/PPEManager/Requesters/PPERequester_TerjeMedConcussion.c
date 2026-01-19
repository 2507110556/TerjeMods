class PPERequester_TerjeMedConcussion : PPERequester_GameplayBase
{
	private float m_ConcussionValue = 0;
	private float m_ConcussionOffset = 0;
	private float m_ConcussionMod = 1;
	
	void SetConcussionEffect(float value, float mod)
	{
		m_ConcussionValue = value;
		m_ConcussionMod = mod;
	}
	
	override protected void OnStop(Param par = null)
	{
		super.OnStop();
		m_ConcussionValue = 0;
		m_ConcussionOffset = 0;
		SetTargetValueFloat(PostProcessEffectType.GaussFilter,PPEGaussFilter.PARAM_INTENSITY,false,0,PPEGaussFilter.L_CONCUSSION,PPOperators.HIGHEST);
	}
	
	override void OnUpdate(float delta)
	{
		super.OnUpdate(delta);
		
		float blurEffect = 0;
		if (m_ConcussionValue > 0)
		{
			m_ConcussionOffset = m_ConcussionOffset + (delta * 0.1);
			if (m_ConcussionOffset >= Math.PI2) m_ConcussionOffset = 0;
			float sinusVal = Math.Clamp( Math.Sin(m_ConcussionOffset) * 0.05, 0, 0.05) ;
			blurEffect = blurEffect + (m_ConcussionValue + sinusVal);
		}
		
		blurEffect = Math.Clamp(blurEffect * m_ConcussionMod, 0, 1);
		SetTargetValueFloat(PostProcessEffectType.GaussFilter,PPEGaussFilter.PARAM_INTENSITY,false,blurEffect,PPEGaussFilter.L_CONCUSSION,PPOperators.HIGHEST);
	}
}