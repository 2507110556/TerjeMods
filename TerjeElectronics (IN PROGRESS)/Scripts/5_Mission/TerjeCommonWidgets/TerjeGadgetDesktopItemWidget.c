class TerjeGadgetDesktopItemWidget : TerjeGadgetComponentWidget
{
	protected TerjeProgramBase m_programData = null;
	
	void SetProgramData(TerjeProgramBase program)
	{
		m_programData = program;
	}
	
	TerjeProgramBase GetProgramData()
	{
		return m_programData;
	}
	
	override void OnSoftwareInit()
	{
		super.OnSoftwareInit();
		
		ImageWidget backgroundWidget = GetNativeBackgroundWidget();
		if (backgroundWidget != null)
		{
			backgroundWidget.SetColor(GetDefaultBackgroundColor());
		}
		
		ImageWidget iconWidget = GetNativeIconWidget();
		if (iconWidget != null)
		{
			iconWidget.LoadImageFile(0, GetIconImagePath());
			iconWidget.SetColor(GetDefaultIconColor());
		}
		
		TextWidget titleWidget = GetNativeTitleWidget();
		if (titleWidget != null)
		{
			titleWidget.SetText(GetTitleText());
			titleWidget.SetColor(GetDefaultTextColor());
		}
	}
	
	override bool OnMouseEnter(Widget w, int x, int y)
	{
		ImageWidget backgroundWidget = GetNativeBackgroundWidget();
		if (backgroundWidget != null)
		{
			backgroundWidget.SetColor(GetHoverBackgroundColor());
		}
		
		ImageWidget iconWidget = GetNativeIconWidget();
		if (iconWidget != null)
		{
			iconWidget.SetColor(GetHoverIconColor());
		}
		
		TextWidget titleWidget = GetNativeTitleWidget();
		if (titleWidget != null)
		{
			titleWidget.SetColor(GetHoverTextColor());
		}
		
		return super.OnMouseEnter(w, x, y);
	}
	
	override bool OnMouseLeave(Widget w, Widget enterW, int x, int y)
	{
		ImageWidget backgroundWidget = GetNativeBackgroundWidget();
		if (backgroundWidget != null)
		{
			backgroundWidget.SetColor(GetDefaultBackgroundColor());
		}
		
		ImageWidget iconWidget = GetNativeIconWidget();
		if (iconWidget != null)
		{
			iconWidget.SetColor(GetDefaultIconColor());
		}
		
		TextWidget titleWidget = GetNativeTitleWidget();
		if (titleWidget != null)
		{
			titleWidget.SetColor(GetDefaultTextColor());
		}
		
		return super.OnMouseLeave(w, enterW, x, y);
	}
	
	override bool OnClick(Widget w, int x, int y, int button)
	{
		if (button == 0)
		{
			PushCommand(new TerjeWidgetCommand_Clicked(button));
			return true;
		}
		
		return super.OnClick(w, x, y, button);
	}
	
	override void OnCommand(TerjeWidgetCommand command, float timeslice)
	{
		super.OnCommand(command, timeslice);
		
		if (command.IsInherited(TerjeWidgetCommand_Clicked))
		{
			OnCommandClicked();
		}
	}
	
	protected void OnCommandClicked()
	{
		TerjeProgramBase program = GetProgramData();
		TerjeSoftwareBase software = GetSoftwareData();
		if ((software != null) && (program != null))
		{
			software.OpenProgram(program.Type());
			software.PlaySoundClick();
		}
	}
	
	protected ImageWidget GetNativeBackgroundWidget()
	{
		return ImageWidget.Cast(GetNativeWidget().FindAnyWidget("IconBackground"));
	}
	
	protected ImageWidget GetNativeIconWidget()
	{
		return ImageWidget.Cast(GetNativeWidget().FindAnyWidget("IconForeground"));
	}
	
	protected TextWidget GetNativeTitleWidget()
	{
		return TextWidget.Cast(GetNativeWidget().FindAnyWidget("IconText"));
	}
	
	protected string GetIconImagePath()
	{
		TerjeProgramBase program = GetProgramData();
		if (program != null)
		{
			return program.GetIcon(0);
		}
		
		return string.Empty;
	}
	
	protected string GetTitleText()
	{
		TerjeProgramBase program = GetProgramData();
		if (program != null)
		{
			return program.GetName();
		}
		
		return string.Empty;
	}
	
	protected int GetDefaultBackgroundColor()
	{
		return ARGB(0, 255, 255, 255);
	}
	
	protected int GetHoverBackgroundColor()
	{
		return ARGB(0, 255, 255, 255);
	}
	
	protected int GetDefaultIconColor()
	{
		return ARGB(255, 255, 255, 255);
	}
	
	protected int GetHoverIconColor()
	{
		return ARGB(255, 255, 255, 255);
	}
	
	protected int GetDefaultTextColor()
	{
		return ARGB(255, 255, 255, 255);
	}
	
	protected int GetHoverTextColor()
	{
		return ARGB(255, 255, 255, 255);
	}
}