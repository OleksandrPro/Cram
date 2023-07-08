#pragma once
#include <algorithm>
#include "Cell.h"
#include "Pointer.h"

ref class Board
{
	ref struct BoardSize
	{
		int i;
		int j;
	};
	ref struct ActivePlayer
	{
		bool isPlayer_1;
		bool isPlayer_2;
	};
	ref struct EmptyListElement
	{
		Cell^ cell;
		bool isEmpty;
	};
private:
	// Fields
	array<Cell^, 2>^ cells;
	const int DEFAULT_BOARD_SIZE_I = 7;
	const int DEFAULT_BOARD_SIZE_J = 5;
	BoardSize^ boardSize;
	PictureBox^ pb;
	TextBox^ tb_State;
	TextBox^ tb_Control;
	Pointer^ pointer;
	ActivePlayer^ activePlayer;
	bool gameOver;
	// Methods
	void FillBoard()
	{
		for (int i = 0; i < boardSize->i; i++) {
			for (int j = 0; j < boardSize->j; j++) {
				cells[i, j] = gcnew Cell(i, j);
			}
		}
		HighlightPointerCells();
	}
	void setAdjacencyForAllCells()
	{
		for (int i = 0; i < boardSize->i; i++) {
			for (int j = 0; j < boardSize->j; j++) {
				CheckAdjacentCellExistance(cells[i, j]);
				setAdjacentCells(cells[i, j]);
			}
		}
	}
	void HighlightPointerCells()
	{
		int x = pointer->getPointerPosition_x();
		int y = pointer->getPointerPosition_y();
		int x2 = pointer->getPointerPosition_x2();
		int y2 = pointer->getPointerPosition_y2();

		cells[x, y]->setHighlited();
		cells[x2, y2]->setHighlited();
	}
	void ReleasePointerCells()
	{
		int x = pointer->getPointerPosition_x();
		int y = pointer->getPointerPosition_y();
		int x2 = pointer->getPointerPosition_x2();
		int y2 = pointer->getPointerPosition_y2();

		cells[x, y]->ReleaseHighlight();
		cells[x2, y2]->ReleaseHighlight();
	}
	void setActivePlayer_1()
	{
		activePlayer->isPlayer_1 = true;
		activePlayer->isPlayer_2 = false;
	}
	void setActivePlayer_2()
	{
		activePlayer->isPlayer_1 = false;
		activePlayer->isPlayer_2 = true;
	}
	bool getPlayer1()
	{
		return activePlayer->isPlayer_1;
	}
	bool getPlayer2()
	{
		return activePlayer->isPlayer_2;
	}
	void CheckAdjacentCellExistance(Cell^ cell)
	{
		bool s1 = cell->getX() - 1 >= 0;
		bool s2 = cell->getX() + 1 < boardSize->i;
		bool s3 = cell->getY() - 1 >= 0;
		bool s4 = cell->getY() + 1 < boardSize->j;

		cell->setIsAdjacentExist_left(s1);
		cell->setIsAdjacentExist_right(s2);
		cell->setIsAdjacentExist_up(s3);
		cell->setIsAdjacentExist_down(s4);
	}
	void setAdjacentCells(Cell^ cell)
	{
		int x = cell->getX();
		int y = cell->getY();
		if (cell->getIsAdjacentExist_left())
		{
			cell->setAdjacent_left(cells[x - 1, y]);
		}
		if (cell->getIsAdjacentExist_right())
		{
			cell->setAdjacent_right(cells[x + 1, y]);
		}
		if (cell->getIsAdjacentExist_up())
		{
			cell->setAdjacent_up(cells[x, y - 1]);
		}
		if (cell->getIsAdjacentExist_down())
		{
			cell->setAdjacent_down(cells[x, y + 1]);
		}
		array<Cell^, 1>^ adjacentCells = getArrayOfAjacentCells(cell);
		for each (Cell ^ item in adjacentCells)
		{
			if (item != nullptr && item->isCellEmpty())
			{
				cell->setHasAtLeastOneEmptyAdjacentCell(true);
				return;
			}
		}
	}
	array<Cell^, 1>^ getArrayOfAjacentCells(Cell^ cell)
	{
		array<Cell^, 1>^ result = gcnew array<Cell^, 1>(4);
		result[0] = cell->getAdjacent_left();
		result[1] = cell->getAdjacent_right();
		result[2] = cell->getAdjacent_up();
		result[3] = cell->getAdjacent_down();
		return result;
	}
	void updateAdjacentCellsState(Cell^ cell)
	{
		array<Cell^, 1>^ adjacentCells = getArrayOfAjacentCells(cell);
		for each (Cell ^ item in adjacentCells)
		{
			if (item != nullptr)
			{
				array<Cell^, 1>^ chechThisCells = getArrayOfAjacentCells(item);
				for each (Cell ^ cll in chechThisCells)
				{
					if (cll != nullptr && cll->isCellEmpty())
					{
						item->setHasAtLeastOneEmptyAdjacentCell(true);
						break;
					}
					item->setHasAtLeastOneEmptyAdjacentCell(false);
				}
			}
		}
	}
	bool CheckMovePossibility()
	{
		for each (Cell ^ cell in cells)
		{
			if (cell->isCellEmpty() && cell->getHasAtLeastOneEmptyAdjacentCell())
			{
				return true;
			}
		}
		return false;
	}
	void PrintGameState()
	{
		tb_State->Clear();
		if (gameOver)
		{
			if (getPlayer1())
			{
				tb_State->AppendText("Second player wins");
			}
			else if (getPlayer2())
			{
				tb_State->AppendText("First player wins");
			}
		}
		else if (getPlayer1())
		{
			tb_State->AppendText("First player's turn");
			tb_State->BackColor = Color::Red;
		}
		else if (getPlayer2())
		{
			tb_State->AppendText("Second player's turn");
			tb_State->BackColor = Color::CornflowerBlue;
		}
	}
	void PrintControl()
	{
		tb_Control->WordWrap = true;
		tb_Control->Clear();
		String^ text = "Control:\r\nWASD - Cell movement\r\nR - Rotate cell\r\nE - Color cell\r\n";
		tb_Control->Text = text;
	}
public:
	Board(PictureBox^ pb1, TextBox^ tb1, TextBox^ tb2, int boardSizeI, int boardSizeJ)
	{
		pb = pb1;
		tb_State = tb1;
		tb_Control = tb2;
		pointer = gcnew Pointer;
		boardSize = gcnew BoardSize;
		activePlayer = gcnew ActivePlayer;
		gameOver = false;

		if ((boardSizeI < DEFAULT_BOARD_SIZE_I) || (boardSizeJ < DEFAULT_BOARD_SIZE_J))
		{
			boardSize->i = DEFAULT_BOARD_SIZE_I;
			boardSize->j = DEFAULT_BOARD_SIZE_J;
		}
		else
		{
			boardSize->i = boardSizeI;
			boardSize->j = boardSizeJ;
		}
		cells = gcnew array<Cell^, 2>(boardSize->i, boardSize->j);
		FillBoard();
		setAdjacencyForAllCells();
		setActivePlayer_1();
		PrintGameState();
		PrintControl();
	}
	void MovePointer(int xx, int yy)
	{
		int x = pointer->getPointerPosition_x();
		int y = pointer->getPointerPosition_y();
		int x2 = pointer->getPointerPosition_x2();
		int y2 = pointer->getPointerPosition_y2();
		// условия возможности перемещения указателя
		// тк указатель состоит из 2х клеток определяются "координаты" указателя в качестве единой сущности
		// выбираются максимальные координаты по X и Y, а также минимальный по X и Y среди соответствующих координат клеток
		// происходит проверка входят ли "координаты" указателя в область координат доски
		// при выполнении необходимых условий убирается обводка указателя, изменяются его координаты, и указатель снова обводится
		bool s1 = (std::max(x + xx, x2 + xx) < boardSize->i);
		bool s2 = (std::min(x + xx, x2 + xx) >= 0);
		bool s3 = (std::max(y + yy, y2 + yy) < boardSize->j);
		bool s4 = (std::min(y + yy, y2 + yy) >= 0);

		if (s1 && s2 && s3 && s4)
		{
			ReleasePointerCells();
			pointer->UpdatePosition(xx, yy, xx, yy);
			HighlightPointerCells();
		}
	}
	void RotatePointer()
	{
		int x = pointer->getPointerPosition_x();
		int y = pointer->getPointerPosition_y();
		int x2 = pointer->getPointerPosition_x2();
		int y2 = pointer->getPointerPosition_y2();
		ReleasePointerCells();
		if (x < x2 && y + 1 < boardSize->j)
		{
			pointer->setPosition_x2(x);
			pointer->setPosition_y2(y + 1);
		}
		else if (x < x2 && y - 1 >= 0)
		{
			pointer->setPosition_x(x);
			pointer->setPosition_y(y - 1);
			pointer->setPosition_x2(x);
			pointer->setPosition_y2(y);
		}
		else if (y < y2 && x + 1 < boardSize->i)
		{
			pointer->setPosition_x2(x + 1);
			pointer->setPosition_y2(y);
		}
		else if (y < y2 && x - 1 >= 0)
		{
			pointer->setPosition_x(x - 1);
			pointer->setPosition_y(y);
			pointer->setPosition_x2(x);
			pointer->setPosition_y2(y);
		}
		HighlightPointerCells();
	}
	void setCellToPlayer()
	{
		int x = pointer->getPointerPosition_x();
		int y = pointer->getPointerPosition_y();
		int x2 = pointer->getPointerPosition_x2();
		int y2 = pointer->getPointerPosition_y2();
		if (cells[x, y]->isCellEmpty() && cells[x2, y2]->isCellEmpty())
		{
			ReleasePointerCells();
			if (getPlayer1())
			{

				cells[x, y]->setToPlayer_1();
				cells[x2, y2]->setToPlayer_1();
				updateAdjacentCellsState(cells[x, y]);
				updateAdjacentCellsState(cells[x2, y2]);
				setActivePlayer_2();

			}
			else if (getPlayer2())
			{

				cells[x, y]->setToPlayer_2();
				cells[x2, y2]->setToPlayer_2();
				updateAdjacentCellsState(cells[x, y]);
				updateAdjacentCellsState(cells[x2, y2]);
				setActivePlayer_1();

			}
			HighlightPointerCells();
			gameOver = !CheckMovePossibility();
			PrintGameState();
		}
	}
	void DrawBoard()
	{
		Bitmap^ bmp = gcnew Bitmap(pb->Width, pb->Height);
		Graphics^ g = Graphics::FromImage(bmp);
		g->Clear(pb->BackColor);
		if (!gameOver)
		{
			for (int i = 0; i < boardSize->i; i++) {
				for (int j = 0; j < boardSize->j; j++) {
					cells[i, j]->Draw(g);
				}
			}
		}
		else
		{
			if (getPlayer1())
			{
				bmp = gcnew Bitmap("player_2_wins.png");
			}
			else if (getPlayer2())
			{
				bmp = gcnew Bitmap("player_1_wins.png");
			}
			g->DrawImage(bmp, (int)(0), (int)(0));
		}
		pb->Image = bmp;
	}
};