class TerjeProgramWidgetCalculator : TerjeProgramWidgetBase
{
	protected TextWidget m_numberWidget = null;
	protected TextWidget m_expressionWidget = null;
	protected ScrollWidget m_historyScroll = null;
	protected Widget m_historyContent = null;
	protected string m_displayText = string.Empty;
	protected string m_memoryText = string.Empty;
	protected string m_operandText = string.Empty;
	
	override string GetNativeLayout()
	{
		return "TerjeElectronics/Layouts/Programs/Calculator/App.layout";
	}
	
	override void OnProgramInit()
	{
		m_memoryText = string.Empty;
		m_operandText = string.Empty;
		m_displayText = "0";
		m_historyContent = GetNativeWidget().FindAnyWidget("HistoryBody");
		m_historyScroll = ScrollWidget.Cast(GetNativeWidget().FindAnyWidget("HistoryScroll"));
		m_expressionWidget = TextWidget.Cast(GetNativeWidget().FindAnyWidget("DataExpression"));
		m_numberWidget = TextWidget.Cast(GetNativeWidget().FindAnyWidget("DataNumber"));
		m_numberWidget.SetText(m_displayText);
	}
	
	override void OnCommand(TerjeWidgetCommand command, float timeslice)
	{
		super.OnCommand(command, timeslice);
		
		if (command.IsInherited(TerjeWidgetCommand_CalculatorClick))
		{
			if (m_numberWidget != null)
			{
				OnButtonClickedCommand(TerjeWidgetCommand_CalculatorClick.Cast(command).m_name);
			}
		}
	}
	
	override bool OnClick(Widget w, int x, int y, int button)
	{
		if (button == MouseState.LEFT)
		{
			PushCommand(new TerjeWidgetCommand_CalculatorClick(w.GetName()));
		}
		
		return true;
	}
	
	protected void OnButtonClickedCommand(string name)
	{
		TerjeSoftwareBase software = GetSoftwareData();
		if (software != null)
		{
			software.PlaySoundClick();
		}
		
		if (name == "Copy")
		{
			OnButtonCopyCommand();
		}
		else if (name == "Paste")
		{
			OnButtonPasteCommand();
		}
		else if (name == "CE")
		{
			OnButtonClearCommand(true);
		}
		else if (name == "C")
		{
			OnButtonClearCommand(false);
		}
		else if (name == "Del")
		{
			OnButtonDelCommand();
		}
		else if (name == "Pow")
		{
			OnButtonPowCommand();
		}
		else if (name == "Sqrt")
		{
			OnButtonSqrtCommand();
		}
		else if (name == "Div")
		{
			OnButtonDivideCommand();
		}
		else if (name == "Mul")
		{
			OnButtonMultiplyCommand();
		}
		else if (name == "Plus")
		{
			OnButtonPlusCommand();
		}
		else if (name == "Minus")
		{
			OnButtonMinusCommand();
		}
		else if (name == "Sign")
		{
			OnButtonExchangeSignCommand();
		}
		else if (name == "Dot")
		{
			OnButtonDotCommand();
		}
		else if (name == "Equal")
		{
			OnButtonEqualCommand();
		}
		else if ((name.Length() == 4) && (name.IndexOf("Num") == 0))
		{
			int number = name.Substring(3, 1).ToInt();
			if ((number >= 0) && (number < 10))
			{
				OnButtonNumberCommand(number);
			}
		}
	}
	
	protected void OnButtonNumberCommand(int number)
	{
		if (m_displayText.Length() < 10)
		{
			if (m_displayText == "0")
			{
				m_displayText = number.ToString();
			}
			else
			{
				m_displayText = m_displayText + number.ToString();
			}
			
			m_numberWidget.SetText(m_displayText);
		}
	}
	
	protected void OnButtonCopyCommand()
	{
		if (GetGame())
		{
			GetGame().CopyToClipboard(TextToFloat(m_displayText).ToString(true));
		}
	}
	
	protected void OnButtonPasteCommand()
	{
		string clipboard = string.Empty;
		if (GetGame())
		{
			GetGame().CopyFromClipboard(clipboard);
			clipboard.Replace(",", ".");
			m_displayText = FloatToText(clipboard.ToFloat());
		}
		
		if (m_displayText == string.Empty)
		{
			m_displayText = "0";
		}
		
		m_numberWidget.SetText(m_displayText);
	}
	
	protected void OnButtonClearCommand(bool clearAll)
	{
		m_displayText = "0";
		m_numberWidget.SetText(m_displayText);
		
		if (clearAll)
		{
			m_memoryText = string.Empty;
			m_operandText = string.Empty;
			m_expressionWidget.SetText(string.Empty);
			DestroyAllChildren();
		}
	}
	
	protected void OnButtonDelCommand()
	{
		if (m_displayText.Length() > 1)
		{
			int index = 0;
			if (m_displayText.Get(0) == "-")
			{
				index = index + 1;
			}
			
			m_displayText = m_displayText.Substring(index, m_displayText.Length() - (index + 1));
			if (m_displayText == "-")
			{
				m_displayText = "0";
			}
		}
		else
		{
			m_displayText = "0";
		}
		
		m_numberWidget.SetText(m_displayText);
	}
	
	protected void OnButtonPowCommand()
	{
		ProcessOperand("^");
	}
	
	protected void OnButtonSqrtCommand()
	{
		float value = TextToFloat(m_displayText);
		string result = FloatToText(Math.Sqrt(value));
		
		AddHistoryEntry("Sqrt( " + m_displayText + " )", result);
		m_displayText = result;
		m_operandText = string.Empty;
		m_memoryText = string.Empty;
		m_expressionWidget.SetText(string.Empty);
		m_numberWidget.SetText(m_displayText);
	}
	
	protected void OnButtonDivideCommand()
	{
		ProcessOperand("/");
	}
	
	protected void OnButtonMultiplyCommand()
	{
		ProcessOperand("*");
	}
	
	protected void OnButtonPlusCommand()
	{
		ProcessOperand("+");
	}
	
	protected void OnButtonMinusCommand()
	{
		ProcessOperand("-");
	}
	
	protected void OnButtonExchangeSignCommand()
	{
		if ((m_displayText.Length() > 0) && (m_displayText != "0"))
		{
			if (m_displayText.Get(0) == "-")
			{
				m_displayText = m_displayText.Substring(1, m_displayText.Length() - 1);
			}
			else
			{
				m_displayText = "-" + m_displayText;
			}
			
			m_numberWidget.SetText(m_displayText);
		}
	}
	
	protected void OnButtonDotCommand()
	{
		if (m_displayText.IndexOf(",") == -1)
		{
			m_displayText = m_displayText + ",";
			m_numberWidget.SetText(m_displayText);
		}
	}
	
	protected void OnButtonEqualCommand()
	{
		ProcessResult();
	}
	
	protected void ProcessOperand(string operand)
	{
		if (m_memoryText == string.Empty)
		{
			m_memoryText = m_displayText;
			m_operandText = operand;
			m_displayText = "0";
		}
		else if ((m_displayText == "0") && (m_operandText != string.Empty))
		{
			m_operandText = operand;
		}
		else
		{
			ProcessResult();
			m_memoryText = m_displayText;
			m_operandText = operand;
			m_displayText = "0";
		}
		
		m_expressionWidget.SetText(m_memoryText + " " + m_operandText);
		m_numberWidget.SetText(m_displayText);
	}
	
	protected void ProcessResult()
	{
		float result = 0;
		float mem = TextToFloat(m_memoryText);
		float num = TextToFloat(m_displayText);
		if (m_operandText == "+")
		{
			result = mem + num;
		}
		else if (m_operandText == "-")
		{
			result = mem - num;
		}
		else if (m_operandText == "*")
		{
			result = mem * num;
		}
		else if (m_operandText == "/")
		{
			result = mem / num;
		}
		else if (m_operandText == "^")
		{
			result = Math.Pow(mem, num);
		}
		else
		{
			return;
		}
		
		string resultText = FloatToText(result);
		AddHistoryEntry(m_memoryText + " " + m_operandText + " " + m_displayText + " =", resultText);
		
		m_displayText = resultText;
		m_operandText = string.Empty;
		m_memoryText = string.Empty;
		m_expressionWidget.SetText(string.Empty);
		m_numberWidget.SetText(m_displayText);
	}
	
	protected void AddHistoryEntry(string expression, string result)
	{
		TerjeProgramWidgetCalculator_HistoryEntry itemHistory;
		itemHistory = TerjeProgramWidgetCalculator_HistoryEntry.Cast(CreateTerjeWidgetEx(TerjeProgramWidgetCalculator_HistoryEntry, m_historyContent));
		itemHistory.SetHistoryEntryData(expression, result);
		m_historyContent.Update();
		m_historyScroll.Update();
		m_historyScroll.VScrollToPos01(1.0);
	}
	
	protected float TextToFloat(string text)
	{
		if ((text == "inf") || (text == "-inf") || (text == "error"))
		{
			return 0;
		}
		
		text.Replace(",", ".");
		if (text.Length() > 0)
		{
			if (text.Get(0) == ".")
			{
				text = "0" + text;
			}
			else if ((text.Length() > 1) && (text.Get(0) == "-") && (text.Get(1) == "."))
			{
				text.Insert(1, "0");
			}
			
			if (text.Get(text.Length() - 1) == ".")
			{
				text = text + ".0";
			}
			
			return text.ToFloat();
		}
		
		return 0;
	}
	
	protected string FloatToText(float value)
	{
		string str = value.ToString(true);
		str.Replace(".", ",");
		
		if ((str == "inf") || (str == "-inf"))
		{
			str = "error";
		}
		
		return str;
	}
}

class TerjeWidgetCommand_CalculatorClick : TerjeWidgetCommand
{
	string m_name;
	
	void TerjeWidgetCommand_CalculatorClick(string name)
	{
		m_name = name;
	}
}

class TerjeProgramWidgetCalculator_HistoryEntry : TerjeWidgetBase
{
	override string GetNativeLayout()
	{
		return "TerjeElectronics/Layouts/Programs/Calculator/HistoryEntry.layout";
	}
	
	void SetHistoryEntryData(string expression, string result)
	{
		TextWidget.Cast( GetNativeWidget().FindAnyWidget("HistoryEntryExpression") ).SetText( expression );
		TextWidget.Cast( GetNativeWidget().FindAnyWidget("HistoryEntryResult") ).SetText( result );
	}
}
