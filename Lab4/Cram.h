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

	Button^ buttonStart;
	Button^ buttonDecreaseX;
	Button^ buttonIncreaseX;
	Button^ buttonDecreaseY;
	Button^ buttonIncreaseY;
public:
	
	GameController(PictureBox^ pb1, TextBox^ tb1, TextBox^ tb2, Button^ btnStart, Button^ btnDecreaseX, Button^ btnIncreaseX, Button^ btnDecreaseY, Button^ btnIncreaseY)
	{
		isMainMenu = true;
		isNewGameMenu = false;
		isBoardSizeChooseMenu = false;
		isGameWindow = false;
		isGameOver = false;

		pb = pb1;
		tb_State = tb1;
		tb_Control = tb2;
		buttonStart = btnStart;

		buttonDecreaseX = btnDecreaseX;
		buttonIncreaseX = btnIncreaseX;
		buttonDecreaseY = btnDecreaseY;
		buttonIncreaseY = btnIncreaseY;
//		gameBoard = gcnew Board(pb, tb1, tb2, 10, 4);
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
	void setButtonState(Button^ btn, bool b)
	{
		btn->Visible = b;
		btn->Enabled = b;
	}
	void enableButton(Button^ btn)
	{
		setButtonState(btn, true);
	}
	void disableButton(Button^ btn)
	{
		setButtonState(btn, false);
	}
	void display()
	{
		if (isMainMenu)
		{
			pb->Visible = false;
			tb_State->Visible = false;
			tb_Control->Visible = false;

			enableButton(buttonStart);
			disableButton(buttonDecreaseX);
			disableButton(buttonIncreaseX);
			disableButton(buttonDecreaseY);
			disableButton(buttonIncreaseY);
		}
		if (isNewGameMenu)
		{
			buttonStart->Text = "Default board size";
			buttonDecreaseX->Text = "Custom board size";
			buttonDecreaseX->Size = System::Drawing::Size(250, 50);
			buttonDecreaseX->Location = System::Drawing::Point(257, 278);
			enableButton(buttonStart);
			enableButton(buttonDecreaseX);
		}
		if (isBoardSizeChooseMenu)
		{
			enableButton(buttonStart);
			enableButton(buttonDecreaseX);
			enableButton(buttonIncreaseX);
			enableButton(buttonDecreaseY);
			enableButton(buttonIncreaseY);

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

			disableButton(buttonStart);
			disableButton(buttonDecreaseX);
			disableButton(buttonIncreaseX);
			disableButton(buttonDecreaseY);
			disableButton(buttonIncreaseY);
		}
	}
};