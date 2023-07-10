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
public:
	
	GameController(PictureBox^ pb1, TextBox^ tb1, TextBox^ tb2)
	{
		isMainMenu = true;
		isNewGameMenu = false;
		isBoardSizeChooseMenu = false;
		isGameOver = false;
		pb = pb1;
		tb_State = tb1;
		tb_Control = tb2;
		gameBoard = gcnew Board(pb, tb1, tb2, 10, 4);
	}
	void gotoMainMenu()
	{
		isMainMenu = true;
		isNewGameMenu = false;
		isBoardSizeChooseMenu = false;
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
		gameBoard = gcnew Board(pb, tb_State, tb_Control, boardSizeI, boardSizeJ);
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
};