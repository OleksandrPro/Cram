#pragma once
#include "Board.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

ref class GameController
{
private:
	bool isMainMenu;
	bool isNewGameMenu;
	bool isBoardSizeChooseMenu;
	bool isGameWindow;
	bool isGameOver;
	Board^ gameBoard;
	PictureBox^ pb;
	TextBox^ tb_State;
	TextBox^ tb_Control;
	TextBox^ tb_Side;

	Button^ buttonStart;
	Button^ buttonDecreaseX;
	Button^ buttonIncreaseX;
	Button^ buttonDecreaseY;
	Button^ buttonIncreaseY;
public:
	GameController(PictureBox^ pb1, TextBox^ tb1, TextBox^ tb2, TextBox^ tb3, Button^ btnStart, Button^ btnDecreaseX, Button^ btnIncreaseX, Button^ btnDecreaseY, Button^ btnIncreaseY)
	{
		isMainMenu = true;
		isNewGameMenu = false;
		isBoardSizeChooseMenu = false;
		isGameWindow = false;
		isGameOver = false;

		pb = pb1;
		tb_State = tb1;
		tb_Control = tb2;
		tb_Side = tb3;
		buttonStart = btnStart;

		buttonDecreaseX = btnDecreaseX;
		buttonIncreaseX = btnIncreaseX;
		buttonDecreaseY = btnDecreaseY;
		buttonIncreaseY = btnIncreaseY;

		display();
	}
	bool getIsMainMenu()
	{
		return isMainMenu;
	}
	bool getIsNewGameMenu()
	{
		return isNewGameMenu;
	}
	bool getIsBoardSizeChooseMenu()
	{
		return isBoardSizeChooseMenu;
	}
	bool getIsGameWindow()
	{
		return isGameWindow;
	}
	void gotoMainMenu()
	{
		isMainMenu = true;
		isNewGameMenu = false;
		isBoardSizeChooseMenu = false;
		isGameWindow = false;
		display();
	}
	void gotoNewGameMenu()
	{
		isMainMenu = false;
		isNewGameMenu = true;
		isBoardSizeChooseMenu = false;
		isGameWindow = false;
		display();
	}
	void gotoBoardSizeChooseMenu()
	{
		isMainMenu = false;
		isNewGameMenu = false;
		isBoardSizeChooseMenu = true;
		isGameWindow = false;
		display();
	}
	void startGame(int boardSizeI, int boardSizeJ)
	{
		isMainMenu = false;
		isNewGameMenu = false;
		isBoardSizeChooseMenu = false;
		isGameWindow = true;
		gameBoard = gcnew Board(pb, tb_State, tb_Control, boardSizeI, boardSizeJ);
		display();
	}
	void gotoGameWindow()
	{
		isMainMenu = false;
		isNewGameMenu = false;
		isBoardSizeChooseMenu = false;
		isGameWindow = true;
		gameBoard = gcnew Board(pb, tb_State, tb_Control, 10, 4);
		display();
	}
	void Draw()
	{
		gameBoard->DrawBoard();
	}
	void MovePointer(int x, int y)
	{
		gameBoard->MovePointer(x, y);
	}
	void RotatePointer()
	{
		gameBoard->RotatePointer();
	}
	void setCellToPlayer()
	{
		gameBoard->setCellToPlayer();
	}

	void blockElement(TextBox^ tb)
	{
		tb->Enabled = false;
	}
	void blockElement(Button^ btn)
	{
		btn->Enabled = false;
	}
	void unblockElement(TextBox^ tb)
	{
		tb->Enabled = true;
	}
	void unblockElement(Button^ btn)
	{
		btn->Enabled = true;
	}
	void setVisualElementState(TextBox^ tb, bool b)
	{
		tb->Visible = b;
		tb->Enabled = b;
	}
	void setVisualElementState(Button^ btn, bool b)
	{
		btn->Visible = b;
		btn->Enabled = b;
	}
	void enableElement(Button^ btn)
	{
		setVisualElementState(btn, true);
	}
	void enableElement(TextBox^ tb)
	{
		setVisualElementState(tb, true);
	}
	void disableElement(Button^ btn)
	{
		setVisualElementState(btn, false);
	}
	void disableElement(TextBox^ tb)
	{
		setVisualElementState(tb, false);
	}
	/*void display()
	{
		if (isMainMenu)
		{
			pb->Visible = false;

			disableElement(tb_State);
			disableElement(tb_Control);
			disableElement(tb_Side);

			enableElement(buttonStart);
			disableElement(buttonDecreaseX);
			disableElement(buttonIncreaseX);
			disableElement(buttonDecreaseY);
			disableElement(buttonIncreaseY);
		}
		if (isNewGameMenu)
		{
			buttonStart->Text = "Default board size";
			buttonDecreaseX->Text = "Custom board size";
			buttonDecreaseX->Size = System::Drawing::Size(250, 50);
			buttonDecreaseX->Location = System::Drawing::Point(257, 278);

			enableElement(buttonStart);
			enableElement(buttonDecreaseX);
		}
		if (isBoardSizeChooseMenu)
		{

			enableElement(buttonStart);
			enableElement(buttonDecreaseX);
			enableElement(buttonIncreaseX);
			enableElement(buttonDecreaseY);
			enableElement(buttonIncreaseY);
			enableElement(tb_Side);
			enableElement(tb_State);

			buttonStart->Text = "Start game";
			buttonDecreaseX->Text = "-1";
			buttonDecreaseX->Size = System::Drawing::Size(100, 60);
			buttonDecreaseX->Location = System::Drawing::Point(115, 58);
		}
		if (isGameWindow)
		{
			pb->Visible = true;
			tb_State->Visible = true;
			tb_Control->Visible = true;

			enableElement(tb_State);
			enableElement(tb_Control);
			disableElement(tb_Side);

			disableElement(buttonStart);
			disableElement(buttonDecreaseX);
			disableElement(buttonIncreaseX);
			disableElement(buttonDecreaseY);
			disableElement(buttonIncreaseY);
		}
	}*/
	bool checkBoardCreationPossibility(int boardSizeX, int boardSizeY)
	{
		if (boardSizeX < Board::DEFAULT_BOARD_SIZE_X || boardSizeY < Board::DEFAULT_BOARD_SIZE_Y)
		{
			return false;
		}
		else if (boardSizeX >= Board::DEFAULT_BOARD_SIZE_X && boardSizeY >= Board::DEFAULT_BOARD_SIZE_Y)
		{
			return true;
		}
	}
	bool checkTextFieldCorrectness(TextBox^ tb)
	{
		bool textIsCorrect = true;
		try
		{
			Int32::Parse(tb->Text);
		}
		catch (FormatException^)
		{
			textIsCorrect = false;
		}
		return textIsCorrect;
	}
	void UpdateTextField(TextBox^ tb, bool b)
	{
		// true =1, false = -1
		try
		{
			int boardSize = Int32::Parse(tb->Text);
			if (b)
			{
				++boardSize;
			}
			else
			{
				--boardSize;
			}
			tb->Text = boardSize.ToString();
		}
		catch (FormatException^)
		{
			blockElement(buttonStart);
		}
	}
	void checkTextCorrectness(TextBox^ tb)
	{
		bool exceptionThrown = false;
		bool buttonsToUpdateX = (tb == tb_Side);
		bool textFieldXCorrect = checkTextFieldCorrectness(tb_Side);
		bool textFieldYCorrect = checkTextFieldCorrectness(tb_State);
		bool bothTextFieldsAreCorrectFormat = textFieldXCorrect && textFieldYCorrect;
		bool boardCanBeCreated;
		try
		{
			if (bothTextFieldsAreCorrectFormat)
			{
				int boardSizeX = Int32::Parse(tb_Side->Text);
				int boardSizeY = Int32::Parse(tb_State->Text);
				boardCanBeCreated = checkBoardCreationPossibility(boardSizeX, boardSizeY);
			}
			else
			{
				boardCanBeCreated = false;
			}
		}
		catch (FormatException^)
		{
			exceptionThrown = true;
		}
		if ((bothTextFieldsAreCorrectFormat && buttonsToUpdateX) || (buttonsToUpdateX && textFieldXCorrect))
		{
			unblockElement(buttonDecreaseX);
			unblockElement(buttonIncreaseX);
		}
		else if ((bothTextFieldsAreCorrectFormat && !buttonsToUpdateX) || (!buttonsToUpdateX && textFieldYCorrect))
		{
			unblockElement(buttonDecreaseY);
			unblockElement(buttonIncreaseY);
		}
		if (buttonsToUpdateX && !textFieldXCorrect)
		{
			blockElement(buttonDecreaseX);
			blockElement(buttonIncreaseX);
		}
		else if (!buttonsToUpdateX && !textFieldYCorrect)
		{
			blockElement(buttonDecreaseY);
			blockElement(buttonIncreaseY);
		}
		if (exceptionThrown || !boardCanBeCreated)
		{
			blockElement(buttonStart);
		}
		else if (!exceptionThrown && boardCanBeCreated)
		{
			unblockElement(buttonStart);
		}
	}
	void display()
	{
		if (isMainMenu)
		{
			pb->Visible = false;
			pb->Enabled = false;

			disableElement(tb_State);
			disableElement(tb_Control);
			disableElement(tb_Side);

			enableElement(buttonStart);
			disableElement(buttonDecreaseX);
			disableElement(buttonIncreaseX);
			disableElement(buttonDecreaseY);
			disableElement(buttonIncreaseY);
		}
		if (isNewGameMenu)
		{
			buttonStart->Text = "Default board size";
			buttonDecreaseX->Text = "Custom board size";
			buttonDecreaseX->Size = System::Drawing::Size(250, 50);
			buttonDecreaseX->Location = System::Drawing::Point(235, 395);
			enableElement(buttonStart);
			enableElement(buttonDecreaseX);
		}
		if (isBoardSizeChooseMenu)
		{
			buttonStart->Text = "Start game";
			buttonDecreaseX->Text = "-1";
			buttonDecreaseX->Size = System::Drawing::Size(100, 60);
			buttonDecreaseX->Location = System::Drawing::Point(115, 58);

			tb_Side->Text = "7";

			tb_State->Location = System::Drawing::Point(235, 216);
			tb_State->Size = System::Drawing::Size(250, 60);
			tb_State->ReadOnly = false;
			tb_State->Text = "5";
			enableElement(buttonStart);
			enableElement(buttonDecreaseX);
			enableElement(buttonIncreaseX);
			enableElement(buttonDecreaseY);
			enableElement(buttonIncreaseY);
			enableElement(tb_Side);
			enableElement(tb_State);
		}
		if (isGameWindow)
		{
			
			tb_State->Location = System::Drawing::Point(115, 379);
			tb_State->Size = System::Drawing::Size(490, 50);
			tb_State->ReadOnly = true;

//			enableElement();
			enableElement(tb_State);
			enableElement(tb_Control);
			disableElement(tb_Side);

			tb_State->Enabled = false;
			tb_Control->Enabled = false;

			disableElement(buttonStart);
			disableElement(buttonDecreaseX);
			disableElement(buttonIncreaseX);
			disableElement(buttonDecreaseY);
			disableElement(buttonIncreaseY);
//			pb->Size = System::Drawing::Size(490, 350);
			pb->Visible = true;
			pb->Enabled = true;
		}
	}
};