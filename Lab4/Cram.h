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
	bool isGameOver;
	Board^ gameBoard;
	PictureBox^ pb;
	TextBox^ tb_State;
	TextBox^ tb_Control;
	Button^ buttonXDecr;
	Button^ buttonXIncr;
	Button^ buttonYdecr;
	Button^ buttonYIncr;
	Button^ buttonStart;
public:
	GameController(PictureBox^ pb1, TextBox^ tb1, TextBox^ tb2, Button^ bXDecr, Button^ bXIncr, Button^ bYdecr, Button^ bYIncr,	Button^ bStart)
	{
		isMainMenu = true;
		isNewGameMenu = false;
		isBoardSizeChooseMenu = false;
		isGameOver = false;
		pb = pb1;
		tb_State = tb1;
		tb_Control = tb2;
		buttonXDecr = bXDecr;
		buttonXIncr = bXIncr;
		buttonYdecr = bYdecr;
		buttonYIncr = bYIncr;
		buttonStart = bStart;

		buttonXDecr->Visible = false;
		buttonXIncr->Visible = false;
		buttonYdecr->Visible = false;
		buttonYIncr->Visible = false;
		buttonStart->Visible = false;
	}
	void gotoMainMenu()
	{
		isMainMenu = true;
		isNewGameMenu = false;
		isBoardSizeChooseMenu = false;

		buttonXDecr->Visible = false;
		buttonXIncr->Visible = false;
		buttonYdecr->Visible = false;
		buttonYIncr->Visible = false;
		buttonStart->Visible = false;
	}
	void gotoNewGameMenu()
	{
		isMainMenu = false;
		isNewGameMenu = true;
		isBoardSizeChooseMenu = false;
	}
	void gotoChooseMenu()
	{
		isMainMenu = false;
		isNewGameMenu = false;
		isBoardSizeChooseMenu = true;
	}
	void startGame(int boardSizeI, int boardSizeJ)
	{
		isGameOver = false;

		buttonXDecr->Visible = false;
		buttonXIncr->Visible = false;
		buttonYdecr->Visible = false;
		buttonYIncr->Visible = false;
		buttonStart->Visible = false;
		gameBoard = gcnew Board(pb, tb_State, tb_Control, boardSizeI, boardSizeJ);
	}

};