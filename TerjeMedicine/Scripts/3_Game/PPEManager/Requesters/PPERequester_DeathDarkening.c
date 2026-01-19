modded class PPERequester_DeathDarkening
{
	override protected void OnStart(Param par = null)
	{
		super.OnStart(par);
		SetTargetValueFloat(PPEExceptions.EXPOSURE,PPEExposureNative.PARAM_INTENSITY,false,-1000,PPEExposureNative.L_0_DEATH,PPOperators.SET);
	}
}