modded class UnboxLambda
{
	override void CopyOldPropertiesToNew (notnull EntityAI old_item, EntityAI new_item)
	{
		super.CopyOldPropertiesToNew(old_item, new_item);
		
		ItemBase oldItemBase;
		ItemBase newItemBase;
		if (ItemBase.CastTo(oldItemBase, old_item) && ItemBase.CastTo(newItemBase, new_item) && oldItemBase.IsDisinfected())
		{
			newItemBase.SetCleanness(1);
		}
	}
}