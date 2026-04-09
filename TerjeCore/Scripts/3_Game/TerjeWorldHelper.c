class TerjeWorldHelper
{
	static bool IsOutOfMap(EntityAI entity)
	{
		if (entity && g_Game && g_Game.GetWorld())
		{
			vector worldPos = entity.GetWorldPosition();
			int worldSize = g_Game.GetWorld().GetWorldSize();

			if ((worldPos[0] < 0) || (worldPos[0] > worldSize) || (worldPos[2] < 0) || (worldPos[2] > worldSize))
			{
				return true;
			}
		}
		
		return false;
	}
}