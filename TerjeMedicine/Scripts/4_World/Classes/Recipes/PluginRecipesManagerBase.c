modded class PluginRecipesManagerBase
{
	override void RegisterRecipies()
	{
		super.RegisterRecipies();
		RegisterRecipe(new TerjeSyringeFill);
		RegisterRecipe(new TerjeRefillSurgicalKit);
		RegisterRecipe(new TerjeCraftSyringeFromInjector);
	}
}