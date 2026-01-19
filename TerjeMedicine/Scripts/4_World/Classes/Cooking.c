modded class Cooking
{
	override void ProcessItemToCook(notnull ItemBase pItem, ItemBase cookingEquip, Param2<CookingMethodType, float> pCookingMethod, out Param2<bool, bool> pStateFlags)
	{
		super.ProcessItemToCook(pItem, cookingEquip, pCookingMethod, pStateFlags);
		
		if (GetGame().IsDedicatedServer() && GetTerjeSettingBool(TerjeSettingsCollection.MEDICINE_ENABLE_MEDICAL_BOILING))
		{
			Bottle_Base bottleBase = Bottle_Base.Cast(cookingEquip);
			if (bottleBase && pItem && pItem.CanBeDisinfected())
			{
				float cookingEquipmentTemp = bottleBase.GetTemperature();
				int liquidType = bottleBase.GetLiquidType();
				if (liquidType != LIQUID_NONE && cookingEquipmentTemp >= Liquid.GetBoilThreshold(liquidType))
				{
					pItem.SetCleanness(1);
				}
			}
		}
	}
}