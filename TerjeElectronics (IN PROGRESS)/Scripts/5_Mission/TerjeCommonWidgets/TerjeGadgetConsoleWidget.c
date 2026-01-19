class TerjeGadgetConsoleWidget : TerjeGadgetComponentWidget
{
	protected const int CHAR_WIDTH = 10;
	protected const int CHAR_HEIGHT = 18;
	protected const int CURSOR_OFFSET = -1;
	
	protected ScrollWidget m_nativeScrollWidget;
	protected EditBoxWidget m_nativeInputWidget;
	protected Widget m_nativeCursorWidget;
	protected ref array<ref array<TextWidget>> m_nativeCharMatrix;
	protected float m_nativeScrollWidth;
	protected int m_maxRowSize;
	protected int m_actualRow;
	protected int m_actualColumn;
	protected int m_inputColor;
	protected float m_cursorBlink;
	
	override string GetNativeLayout()
	{
		return "TerjeElectronics/Layouts/Widgets/SoftwareConsoleWidget.layout";
	}
	
	override void OnInit()
	{
		GetNativeWidget().Update();
		m_nativeCharMatrix = new array<ref array<TextWidget>>;
		m_nativeInputWidget = EditBoxWidget.Cast( GetNativeWidget().FindAnyWidget("SoftwareConsoleInput") );
		m_nativeScrollWidget = ScrollWidget.Cast( GetNativeWidget().FindAnyWidget("SoftwareConsoleScroll") );
		m_nativeCursorWidget = GetNativeWidget().FindAnyWidget("SoftwareConsoleCursor");
		m_nativeScrollWidth = m_nativeScrollWidget.GetContentWidth() - m_nativeScrollWidget.GetScrollbarWidth();
		m_maxRowSize = (int)(m_nativeScrollWidth / CHAR_WIDTH);
		m_actualRow = 0;
		m_actualColumn = 0;
		m_inputColor = 0;
		m_cursorBlink = 0;
	}
	
	override void OnCommand(TerjeWidgetCommand command, float timeslice)
	{
		super.OnCommand(command, timeslice);
		
		if (command.IsInherited(TerjeWidgetCommand_SoftwareConsolePrint))
		{
			HandleConsolePrint(TerjeWidgetCommand_SoftwareConsolePrint.Cast(command));
		}
		else if (command.IsInherited(TerjeWidgetCommand_SoftwareConsoleInputMode))
		{
			HandleConsoleInputMode(TerjeWidgetCommand_SoftwareConsoleInputMode.Cast(command));
		}
		else if (command.IsInherited(TerjeWidgetCommand_SoftwareConsoleInputMove))
		{
			HandleConsoleInputMove(TerjeWidgetCommand_SoftwareConsoleInputMove.Cast(command));
		}
		else if (command.IsInherited(TerjeWidgetCommand_SoftwareConsoleInputExec))
		{
			HandleConsoleInputExec();
		}
	}
	
	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);
		
		if (m_nativeScrollWidget != null)
		{
			m_nativeScrollWidget.VScrollToPos01(1.0);
		}
		
		if ((m_nativeCursorWidget != null) && (m_nativeCursorWidget.IsVisible()))
		{
			m_nativeCursorWidget.SetColor(m_inputColor);
			
			m_cursorBlink = m_cursorBlink + timeslice;
			if (m_cursorBlink < 0.5)
			{
				m_nativeCursorWidget.SetAlpha(1.0);
			}
			else if (m_cursorBlink > 1.0)
			{
				m_cursorBlink = 0;
			}
			else
			{
				m_nativeCursorWidget.SetAlpha(0);
			}
		}
	}
	
	override bool OnChange(Widget w, int x, int y, bool finished)
	{
		if ((w == m_nativeInputWidget) && (m_nativeInputWidget.IsVisible()))
		{
			return HandleConsoleInput();
		}
		
		return super.OnChange(w, x, y, finished);
	}
	
	override bool OnKeyPress(Widget w, int x, int y, int key)
	{
		if ((m_nativeInputWidget != null) && (m_nativeInputWidget.IsVisible()))
		{
			if (key == KeyCode.KC_RETURN)
			{
				PushCommand(new TerjeWidgetCommand_SoftwareConsoleInputExec());
				return true;
			}
			else if (key == KeyCode.KC_LEFT)
			{
				PushCommand(new TerjeWidgetCommand_SoftwareConsoleInputMove(-1, 0));
				return true;
			}
			else if (key == KeyCode.KC_RIGHT)
			{
				PushCommand(new TerjeWidgetCommand_SoftwareConsoleInputMove(1, 0));
				return true;
			}
			else if (key == KeyCode.KC_UP)
			{
				PushCommand(new TerjeWidgetCommand_SoftwareConsoleInputMove(0, -1));
				return true;
			}
			else if (key == KeyCode.KC_DOWN)
			{
				PushCommand(new TerjeWidgetCommand_SoftwareConsoleInputMove(0, 1));
				return true;
			}
		}
		
		return super.OnKeyPress(w, x, y, key);
	}
	
	void Print(string value, int color, bool moveCursor = true)
	{
		PushCommand(new TerjeWidgetCommand_SoftwareConsolePrint(value, color, moveCursor));
	}
	
	void Println(string value, int color, bool moveCursor = true)
	{
		PushCommand(new TerjeWidgetCommand_SoftwareConsolePrint(value + "\n", color, moveCursor));
	}
	
	void EnableInputMode(int color)
	{
		m_inputColor = color;
		PushCommand(new TerjeWidgetCommand_SoftwareConsoleInputMode(true));
	}
	
	void DisableInputMode()
	{
		PushCommand(new TerjeWidgetCommand_SoftwareConsoleInputMode(false));
	}
	
	protected void HandleConsolePrint(TerjeWidgetCommand_SoftwareConsolePrint cmd)
	{
		int color = cmd.m_color;
		int lng = cmd.m_value.LengthUtf8();
		for (int i = 0; i < lng; i++)
		{
			string char = cmd.m_value.SubstringUtf8(i, 1);
			if (char == "\r")
			{
				m_actualColumn = 0;
			}
			else if (char == "\n")
			{
				m_actualColumn = 0;
				m_actualRow = m_actualRow + 1;
			}
			else if (char == "\t")
			{
				HandleConsolePrint(new TerjeWidgetCommand_SoftwareConsolePrint("    ", cmd.m_color, cmd.m_moveCursor));
			}
			else
			{
				HandleConsolePrintChar(char, color, cmd.m_moveCursor);
			}
		}
	}
	
	protected void HandleConsolePrintChar(string char, int color, bool moveCursor)
	{
		if (m_nativeScrollWidget != null)
		{
			TextWidget newCharWidget = null;
			
			if (char != " ")
			{
				newCharWidget = TextWidget.Cast(GetGame().GetWorkspace().CreateWidgets(GetNativeCharLayout(), m_nativeScrollWidget));
			}
			
			TextWidget oldCharWidget = GetCharFromMatrix(m_actualColumn, m_actualRow);
			if (oldCharWidget != null)
			{
				oldCharWidget.Unlink();
			}
			
			SetCharToMatrix(m_actualColumn, m_actualRow, newCharWidget);
			
			if (newCharWidget != null)
			{
				newCharWidget.SetColor(color);
				newCharWidget.SetText(char, false);
				newCharWidget.SetPos(CHAR_WIDTH * m_actualColumn, CHAR_HEIGHT * m_actualRow, false);
				newCharWidget.Update();
			}
			
			if (moveCursor)
			{
				if (m_actualColumn >= m_maxRowSize)
				{
					m_actualColumn = 0;
					m_actualRow = m_actualRow + 1;
				}
				else
				{
					m_actualColumn = m_actualColumn + 1;
				}
			}
		}
	}
	
	protected void HandleConsoleInputMode(TerjeWidgetCommand_SoftwareConsoleInputMode cmd)
	{
		if (cmd.m_state)
		{
			HandleConsoleUpdateCursor();
			m_nativeInputWidget.Show(true);
			m_nativeInputWidget.SetText("~");
			SetFocus(m_nativeInputWidget);
		}
		else
		{
			m_nativeInputWidget.Show(false);
			m_nativeCursorWidget.Show(false);
		}
	}
	
	protected void HandleConsoleUpdateCursor()
	{
		m_nativeCursorWidget.Show(true, false);
		m_nativeCursorWidget.SetPos((CHAR_WIDTH * m_actualColumn) + CURSOR_OFFSET, CHAR_HEIGHT * m_actualRow, false);
		m_nativeCursorWidget.Update();
	}
	
	protected void HandleConsoleInputMove(TerjeWidgetCommand_SoftwareConsoleInputMove cmd)
	{
		m_actualColumn = m_actualColumn + TerjeMathHelper.ClampInt(cmd.m_deltaX, -1, 1);
		m_actualRow = m_actualRow + TerjeMathHelper.ClampInt(cmd.m_deltaY, -1, 1);
		
		if (m_actualColumn >= m_maxRowSize)
		{
			m_actualColumn = m_maxRowSize - 1;
		}
		else if (m_actualColumn < 0)
		{
			m_actualColumn = 0;
		}
		
		if (m_actualRow >= GetMatrixRowsCount())
		{
			m_actualRow = GetMatrixRowsCount() - 1;
		}
		else if (m_actualRow < 0)
		{
			m_actualRow = 0;
		}
		
		HandleConsoleUpdateCursor();
	}
	
	protected void HandleConsoleInputExec()
	{
		HandleConsolePrint(new TerjeWidgetCommand_SoftwareConsolePrint("\n", m_inputColor, true));
	}
	
	protected bool HandleConsoleInput()
	{
		string text = m_nativeInputWidget.GetText();
		int lng = text.LengthUtf8();
		if (lng == 0)
		{
			PushCommand(new TerjeWidgetCommand_SoftwareConsoleInputMove(-1, 0));
			Print(" ", m_inputColor, false);
		}
		else if ((lng > 1) && (text.SubstringUtf8(0, 1) == "~"))
		{
			Print(text.SubstringUtf8(1, 1), m_inputColor);
			HandleConsoleUpdateCursor();
		}
		
		m_nativeInputWidget.SetText("~");
		return true;
	}
	
	protected string GetNativeCharLayout()
	{
		return "TerjeElectronics/Layouts/Widgets/SoftwareConsoleChar.layout";
	}
	
	protected array<TextWidget> GetRowFromMatrix(int row)
	{
		if ((row >= 0) && (row < m_nativeCharMatrix.Count()))
		{
			return m_nativeCharMatrix.Get(row);
		}
		
		return null;
	}
	
	protected int GetMatrixRowsCount()
	{
		return m_nativeCharMatrix.Count();
	}
	
	protected TextWidget GetCharFromMatrix(int col, int row)
	{
		array<TextWidget> rowMatrix = GetRowFromMatrix(row);
		if ((rowMatrix != null) && (col >= 0) && (col < rowMatrix.Count()))
		{
			return rowMatrix.Get(col);
		}
		
		return null;
	}
	
	protected void SetCharToMatrix(int col, int row, TextWidget charWidget)
	{
		array<TextWidget> rowMatrix = null;
		if ((row >= 0) && (row < m_nativeCharMatrix.Count()))
		{
			rowMatrix = m_nativeCharMatrix.Get(row);
		}
		else
		{
			while (row >= m_nativeCharMatrix.Count())
			{
				rowMatrix = new array<TextWidget>;
				m_nativeCharMatrix.Insert(rowMatrix);
			}
		}
		
		if (rowMatrix != null)
		{
			if ((col >= 0) && (col < rowMatrix.Count()))
			{
				rowMatrix.Set(col, charWidget);
			}
			else
			{
				while (col >= rowMatrix.Count())
				{
					if (col == rowMatrix.Count())
					{
						rowMatrix.Insert(charWidget);
					}
					else
					{
						rowMatrix.Insert(null);
					}
				}
			}
		}
	}
}

class TerjeWidgetCommand_SoftwareConsolePrint : TerjeWidgetCommand
{
	string m_value;
	int m_color;
	bool m_moveCursor;
	
	void TerjeWidgetCommand_SoftwareConsolePrint(string value, int color, bool moveCursor)
	{
		m_value = value;
		m_color = color;
		m_moveCursor = moveCursor;
	}
}

class TerjeWidgetCommand_SoftwareConsoleInputMode : TerjeWidgetCommand
{
	bool m_state;
	
	void TerjeWidgetCommand_SoftwareConsoleInputMode(bool state)
	{
		m_state = state;
	}
}

class TerjeWidgetCommand_SoftwareConsoleInputMove : TerjeWidgetCommand
{
	int m_deltaX;
	int m_deltaY;
	
	void TerjeWidgetCommand_SoftwareConsoleInputMove(int deltaX, int deltaY)
	{
		m_deltaX = deltaX;
		m_deltaY = deltaY;
	}
}

class TerjeWidgetCommand_SoftwareConsoleInputExec : TerjeWidgetCommand
{

}