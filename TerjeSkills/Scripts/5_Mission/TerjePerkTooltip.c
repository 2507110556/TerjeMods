class TerjePerkTooltip
{
	private static ref Widget m_perkTooltipInstance = null;
	static ref Widget GetPerkTooltipWidget(TerjePerkCfg perkCfg, int perkLevel, int perkActiveLevel, bool canBeUpgraded)
	{
		if (m_perkTooltipInstance)
		{
			m_perkTooltipInstance.Unlink();
		}
		
		m_perkTooltipInstance = GetGame().GetWorkspace().CreateWidgets("TerjeSkills/Layouts/TerjePerkTooltip.layout", ItemManager.GetInstance().GetTerjeSkillsRoot() );
		m_perkTooltipInstance.Show(false);
		
		string info = perkCfg.GetDescription() + "<br/>";	
		if (perkActiveLevel > 0 && perkActiveLevel <= perkCfg.GetStagesCount())
		{
			float curValueRaw = perkCfg.GetValue(perkActiveLevel - 1);
			if (curValueRaw != 0)
			{
				string curValuePercentage = TerjeMathHelper.ToDisplayPercent(curValueRaw);
				info = info + "<br/>#STR_TERJESKILL_MISC4 <color rgba='97,215,124,255'>" + curValuePercentage + perkCfg.GetMetricSymbol() + "</color>";
			}
		}
		
		if (perkLevel >= 0 && perkLevel < perkCfg.GetStagesCount())
		{
			float nextValueRaw = perkCfg.GetValue(perkLevel);
			int nextSkillLevel = perkCfg.GetRequiredSkillLevel(perkLevel);
			int nextPerkPoints = perkCfg.GetRequiredPerkPoints(perkLevel);
			info = info + "<br/>#STR_TERJESKILL_MISC5 <color rgba='0,148,255,255'>" + nextPerkPoints + "</color> #STR_TERJESKILL_MISC6 <color rgba='0,148,255,255'>" + nextSkillLevel + "</color>";
						
			if (nextValueRaw != 0)
			{
				string nextValuePercentage = TerjeMathHelper.ToDisplayPercent(nextValueRaw);
				info = info + " #STR_TERJESKILL_MISC7 <color rgba='0,148,255,255'>" + nextValuePercentage + perkCfg.GetMetricSymbol() + "</color>";
			}
		}
		
		if (perkCfg.GetStagesCount() > 1)
		{
			info = info + "<br/><br/>#STR_TERJESKILL_MISC16 ";
			for (int i = 0; i < perkCfg.GetStagesCount(); i++)
			{
				if (i > 0)
				{
					info = info + ", ";
				}
				
				if (perkCfg.HasHints())
				{
					info = info + "<color rgba='0,148,255,255'>" + perkCfg.GetHint(i) + "</color>";
				}
				else
				{
					string infoValuePercentage = TerjeMathHelper.ToDisplayPercent(perkCfg.GetValue(i));
					info = info + "<color rgba='0,148,255,255'>" + infoValuePercentage + perkCfg.GetMetricSymbol() + "</color>";
				}
			}
		}
		
		if (perkLevel == 0)
		{
			info = info + "<br/><br/><color rgba='160,160,160,255'><b>#STR_TERJESKILL_MISC17</b></color>";
		}
		else if (perkActiveLevel == perkLevel && perkLevel > 0)
		{
			info = info + "<br/><br/><color rgba='97,215,124,255'><b>#STR_TERJESKILL_MISC8</b></color>";
		}
		else if (perkActiveLevel < perkLevel && perkLevel > 0)
		{
			if (perkActiveLevel > 0)
			{
				int deactRequiredLevel = 0;
				if (perkLevel > 0 && perkLevel <= perkCfg.GetStagesCount())
				{
					deactRequiredLevel = perkCfg.GetRequiredSkillLevel(perkLevel - 1);
				}
				
				info = info + "<br/><br/><color rgba='198,59,64,255'><b>#STR_TERJESKILL_MISC10 (</b></color><color rgba='160,160,160,255'>" + deactRequiredLevel + "</color><color rgba='198,59,64,255'><b>)</b></color>";
			}
			else
			{
				info = info + "<br/><br/><color rgba='198,59,64,255'><b>#STR_TERJESKILL_MISC9</b></color>";
			}
		}
		
		if (canBeUpgraded)
		{
			info = info + "<br/><br/><color rgba='255,215,0,255'><b>#STR_TERJESKILL_MISC11</b></color>";
		}
		
		ImageWidget.Cast(m_perkTooltipInstance.FindAnyWidget("terje_perk_tooltip_icon")).LoadImageFile(0, perkCfg.GetEnabledIcon());
		TextWidget.Cast(m_perkTooltipInstance.FindAnyWidget("terje_perk_tooltip_name")).SetText(perkCfg.GetDisplayName());
		TextWidget.Cast(m_perkTooltipInstance.FindAnyWidget("terje_perk_tooltip_info")).SetText(info);
		TextWidget.Cast(m_perkTooltipInstance.FindAnyWidget("terje_perk_tooltip_level")).SetText("#STR_TERJESKILL_MISC12: " + perkLevel.ToString() + "/" + perkCfg.GetStagesCount().ToString());
		
		m_perkTooltipInstance.FindAnyWidget("terje_perk_tooltip_content_spacer").Update();
		m_perkTooltipInstance.FindAnyWidget("terje_perk_tooltip_content").Update();
		
		return m_perkTooltipInstance;
	}
}