class TerjeSoftwareWidgetStalker : TerjeSoftwareWidgetTablet
{
	override typename GetBootConsoleWidgetType()
	{
		return TerjeGadgetConsoleWidgetStalker;
	}
	
	override typename GetLoadscreenWidgetType()
	{
		return TerjeGadgetLoadscreenWidgetStalker;
	}
	
	override typename GetWorkspaceWidgetType()
	{
		return TerjeGadgetWorkspaceWidgetStalker;
	}
}

class TerjeGadgetConsoleWidgetStalker : TerjeGadgetConsoleWidget
{
	protected int m_bootConsoleExecutedSteps = 0;
	
	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);
		
		if (GetSoftwareData() != null)
		{
			float elapsedTime = Math.Max(0, GetGame().GetTickTime() - GetSoftwareData().GetBootTimer());
			int color = ARGB(255, 255, 255, 255);
			if ((elapsedTime > 1.0) && (m_bootConsoleExecutedSteps == 0))
			{
				string serial = "NULL";
				if (GetGadgetEntity() && (GetGadgetEntity().GetHardware() != null))
				{
					serial = GetGadgetEntity().GetHardware().GetSerialNumberInt().ToString();
				}
				
				Println("Hardware modular BIOS v1.21, An Terje Star Alloy.", color);
				Println("Copyright (C) 1984-97, Terje Bruoygard Inc.", color);
				Println(" ", color);
				Println("(" + serial + ") Intek i430VX PCIset(TM)", color);
				Print("MemoryTest: 0 NONE", color);
				m_bootConsoleExecutedSteps++;
			}
			
			if ((elapsedTime > 1.25) && (m_bootConsoleExecutedSteps > 0))
			{
				for (int memstepi = m_bootConsoleExecutedSteps; memstepi < 16; memstepi++)
				{
					float memstepf = (float)memstepi;
					if (elapsedTime > (1.25 + (memstepf * 0.2)))
					{
						Print("\rMemoryTest: " + ((int)Math.Pow(memstepi + 1, 4)).ToString() + " OK    ", color);
						m_bootConsoleExecutedSteps++;
					}
				}
			}
			
			if ((elapsedTime > 5.0) && (m_bootConsoleExecutedSteps == 16))
			{
				Println(" ", color);
				Println(" ", color);
				Println("Hardhash Plug and Play BIOS Extension v1.0A", color);
				Println("Copyright (C) 1997, Terje Software Inc.", color);
				m_bootConsoleExecutedSteps++;
			}
			
			if ((elapsedTime > 6.0) && (m_bootConsoleExecutedSteps == 17))
			{
				Println("\tDetecting IDE Primary Master   ... PCemHD", color);
				m_bootConsoleExecutedSteps++;
			}
			
			if ((elapsedTime > 6.2) && (m_bootConsoleExecutedSteps == 18))
			{
				Println("\tDetecting IDE Primary Slave    ... PCemSD", color);
				m_bootConsoleExecutedSteps++;
			}
			
			if ((elapsedTime > 6.4) && (m_bootConsoleExecutedSteps == 19))
			{
				Print("\tDetecting IDE Secondary Master ... Detecting", color);
				m_bootConsoleExecutedSteps++;
			}
			
			if ((elapsedTime > 6.8) && (m_bootConsoleExecutedSteps == 20))
			{
				Println("\r\tDetecting IDE Secondary Master ... NONE\t\t", color);
				Println("\tDetecting IDE Secondary Slave  ... NONE\t\t", color);
				m_bootConsoleExecutedSteps++;
			}
			
			if ((elapsedTime > 8.0) && (m_bootConsoleExecutedSteps == 21))
			{
				Println(" ", color);
				Println(" ", color);
				Println("PCI Device listing...", color);
				Println("Bus No. Device No. Func No. Vendor ID    Device Id   IRQ", color);
				Println("--------------------------------------------------------", color);
				Println("   0        7         1       6068         1049       14", color);
				Println("   0       15         0       1974         1372       11", color);
				Println(" ", color);
				Println("Verifying DMI Pool Data ...", color);
				m_bootConsoleExecutedSteps++;
			}
			
			if ((elapsedTime > 8.5) && (m_bootConsoleExecutedSteps == 22))
			{
				Println("Starting Stalker OS ...", color);
				m_bootConsoleExecutedSteps++;
			}
		}
	}
}

class TerjeGadgetLoadscreenWidgetStalker : TerjeGadgetLoadscreenWidget
{
	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);
		
		if ((GetSoftwareData() != null) && (GetNativeWidget() != null))
		{
			float elapsedTime = Math.Max(0, GetGame().GetTickTime() - GetSoftwareData().GetBootTimer());
			GetNativeWidget().SetAlpha(Math.Clamp(elapsedTime * 0.5, 0, 1));
			
			int step = (int)(elapsedTime * 15);
			step = step % 13;
			
			for (int i = 0; i < 12; i++)
			{
				Widget w = GetNativeWidget().FindAnyWidget("LoadingBarDot" + (i - 4));
				if (w != null)
				{
					if (i == step)
					{
						w.SetAlpha(1.0);
					}
					else if (i == (step - 1))
					{
						w.SetAlpha(0.75);
					}
					else if (i == (step - 2))
					{
						w.SetAlpha(0.50);
					}
					else if (i == (step - 3))
					{
						w.SetAlpha(0.25);
					}
					else
					{
						w.SetAlpha(0.0);
					}
				}
			}
		}
	}
	
	override string GetNativeLayout()
	{
		return "TerjeElectronics/Layouts/Software/Stalker/Loadscreen.layout";
	}
}

class TerjeGadgetWorkspaceWidgetStalker : TerjeGadgetWorkspaceWidget
{
	override void OnSoftwareInit()
	{
		super.OnSoftwareInit();
		CreateStatusBarWidget(TerjeGadgetBarTimeWidget);
		CreateStatusBarWidget(TerjeGadgetBarBatteryWidget);
		CreateStatusBarWidget(TerjeGadgetBarSignalWidget);
	}
	
	override typename GetDesktopWidgetType()
	{
		return TerjeGadgetDesktopWidgetStalker;
	}
	
	override typename GetWindowWidgetType()
	{
		return TerjeGadgetWindowWidgetStalker;
	}
	
	override string GetNativeLayout()
	{
		return "TerjeElectronics/Layouts/Software/Stalker/Workspace.layout";
	}
}

class TerjeGadgetDesktopWidgetStalker : TerjeGadgetDesktopWidget
{
	override typename GetItemWidgetType()
	{
		return TerjeGadgetDesktopItemWidgetStalker;
	}
	
	override string GetNativeLayout()
	{
		return "TerjeElectronics/Layouts/Software/Stalker/Desktop.layout";
	}
}

class TerjeGadgetDesktopItemWidgetStalker : TerjeGadgetDesktopItemWidget
{
	override string GetNativeLayout()
	{
		return "TerjeElectronics/Layouts/Software/Stalker/DesktopItem.layout";
	}
	
	override string GetIconImagePath()
	{
		TerjeProgramBase program = GetProgramData();
		if (program != null)
		{
			return program.GetIcon(1);
		}
		
		return super.GetIconImagePath();
	}
	
	override int GetDefaultIconColor()
	{
		return ARGB(255, 220, 220, 220);
	}
	
	protected int GetDefaultTextColor()
	{
		return ARGB(255, 220, 220, 220);
	}
}

class TerjeGadgetWindowWidgetStalker : TerjeGadgetWindowWidget
{
	override string GetNativeLayout()
	{
		return "TerjeElectronics/Layouts/Software/Stalker/Window.layout";
	}
}