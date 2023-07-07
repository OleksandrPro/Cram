#pragma once
#include <algorithm>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

ref class Cell
{
	ref struct Coordinates
	{
		unsigned int x;
		unsigned int y;
	};
	ref struct States
	{
		bool isEmpty;
		bool isPlayer_1;
		bool isPlayer_2;
		bool isHighlighted;
	};
	ref struct HasAdjacent
	{
		bool left;
		bool right;
		bool up;
		bool down;
	};
	ref struct AdjacentCells
	{
		Cell^ left;
		Cell^ right;
		Cell^ up;
		Cell^ down;
	};
private:
	States^ state;
	Coordinates^ coordinates;
	HasAdjacent^ hasAdjacentCells;
	AdjacentCells^ adjacentCells;
	bool hasAtLeastOneEmptyAdjacentCell;
public:
	Cell(unsigned int x, unsigned int y)
	{
		coordinates = gcnew Coordinates;
		coordinates->x = x;
		coordinates->y = y;
		state = gcnew States;
		state->isEmpty = true;
		state->isPlayer_1 = false;
		state->isPlayer_2 = false;
		state->isHighlighted = false;
		hasAdjacentCells = gcnew HasAdjacent;
		adjacentCells = gcnew AdjacentCells;
		hasAtLeastOneEmptyAdjacentCell = true;
	}
	int getX()
	{
		return coordinates->x;
	}
	int getY()
	{
		return coordinates->y;
	}
	void setEmpty()
	{
		state->isEmpty = true;
		state->isHighlighted = false;
	}
	void setToPlayer_1()
	{
		state->isEmpty = false;
		state->isPlayer_1 = true;
		state->isPlayer_2 = false;
		state->isHighlighted = false;
	}
	void setToPlayer_2()
	{
		state->isEmpty = false;
		state->isPlayer_1 = false;
		state->isPlayer_2 = true;
		state->isHighlighted = false;
	}
	void setHighlited()
	{
		state->isHighlighted = true;
	}
	void ReleaseHighlight()
	{
		state->isHighlighted = false;
	}
	bool isCellEmpty()
	{
		return state->isEmpty;
	}

	void setIsAdjacentExist_left(bool b)
	{
		hasAdjacentCells->left = b;
	}
	void setIsAdjacentExist_right(bool b)
	{
		hasAdjacentCells->right = b;
	}
	void setIsAdjacentExist_up(bool b)
	{
		hasAdjacentCells->up = b;
	}
	void setIsAdjacentExist_down(bool b)
	{
		hasAdjacentCells->down = b;
	}

	bool getIsAdjacentExist_left()
	{
		return hasAdjacentCells->left;
	}
	bool getIsAdjacentExist_right()
	{
		return hasAdjacentCells->right;
	}
	bool getIsAdjacentExist_up()
	{
		return hasAdjacentCells->up;
	}
	bool getIsAdjacentExist_down()
	{
		return hasAdjacentCells->down;
	}

	void setAdjacent_left(Cell^ cell)
	{
		adjacentCells->left = cell;
	}
	void setAdjacent_right(Cell^ cell)
	{
		adjacentCells->right = cell;
	}
	void setAdjacent_up(Cell^ cell)
	{
		adjacentCells->up = cell;
	}
	void setAdjacent_down(Cell^ cell)
	{
		adjacentCells->down = cell;
	}

	Cell^ getAdjacent_left()
	{
		return adjacentCells->left;
	}
	Cell^ getAdjacent_right()
	{
		return adjacentCells->right;
	}
	Cell^ getAdjacent_up()
	{
		return adjacentCells->up;
	}
	Cell^ getAdjacent_down()
	{
		return adjacentCells->down;
	}
	void setHasAtLeastOneEmptyAdjacentCell(bool b)
	{
		hasAtLeastOneEmptyAdjacentCell = b;
	}
	bool getHasAtLeastOneEmptyAdjacentCell()
	{
		return hasAtLeastOneEmptyAdjacentCell;
	}
	void Draw(Graphics^ g)
	{
		Bitmap^ img;
		int bitMapSize = 70;

		if (state->isHighlighted && state->isPlayer_1)
		{
			img = gcnew Bitmap("highlighted_player1_cell.png");
		}
		else if (state->isHighlighted && state->isPlayer_2)
		{
			img = gcnew Bitmap("highlighted_player2_cell.png");
		}
		else if (state->isHighlighted && state->isEmpty)
		{
			img = gcnew Bitmap("highlighted_cell.png");
		}
		else if (state->isPlayer_1)
		{
			img = gcnew Bitmap("player1_cell.png");
		}
		else if (state->isPlayer_2)
		{
			img = gcnew Bitmap("player2_cell.png");
		}
		else if (state->isEmpty)
		{
			img = gcnew Bitmap("empty_cell.png");
		}

		g->DrawImage(img, (int)(coordinates->x * bitMapSize), (int)(coordinates->y * bitMapSize));
	}
};
ref class Board
{
	ref class Pointer
	{
		ref struct PointerPosition
		{
			int x;
			int y;
			int x2;
			int y2;
		};
	private:
		PointerPosition^ pointerPosition;
	public:
		Pointer()
		{
			pointerPosition = gcnew PointerPosition;
			setPointerPosition(0, 0, 1, 0);
		}
		int getPointerPosition_x()
		{
			return pointerPosition->x;
		}
		int getPointerPosition_y()
		{
			return pointerPosition->y;
		}
		int getPointerPosition_x2()
		{
			return pointerPosition->x2;
		}
		int getPointerPosition_y2()
		{
			return pointerPosition->y2;
		}
		void setPosition_x(int a)
		{
			pointerPosition->x = a;
		}
		void setPosition_y(int a)
		{
			pointerPosition->y = a;
		}
		void setPosition_x2(int a)
		{
			pointerPosition->x2 = a;
		}
		void setPosition_y2(int a)
		{
			pointerPosition->y2 = a;
		}
		void setPointerPosition(int x, int y, int x2, int y2)
		{
			setPosition_x(x);
			setPosition_y(y);
			setPosition_x2(x2);
			setPosition_y2(y2);
		}
		void UpdatePosition(int x, int y, int x2, int y2)
		{
			pointerPosition->x += x;
			pointerPosition->y += y;
			pointerPosition->x2 += x2;
			pointerPosition->y2 += y2;
		}
	};
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
//	array<EmptyListElement^, 2>^ listOfEmpty;
	bool gameOver;
	// Methods
	void FillBoard()
	{
		for (int i = 0; i < boardSize->i; i++) {
			for (int j = 0; j < boardSize->j; j++) {
				cells[i, j] = gcnew Cell(i, j);
//				listOfEmpty[i, j] = gcnew EmptyListElement;
//				listOfEmpty[i, j]->cell = cells[i, j];
//				listOfEmpty[i, j]->isEmpty = cells[i, j]->isCellEmpty();
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
	/*
	void RemoveFromEmptyCellsList(Cell^ cell)
	{
		int x = cell->getX();
		int y = cell->getY();
		listOfEmpty[x, y] = nullptr;
	}
	*/
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
		for each (Cell^ item in adjacentCells)
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
					if (cll!=nullptr && cll->isCellEmpty())
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
		for each (Cell^ cell in cells)
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
//		listOfEmpty = gcnew array < EmptyListElement^, 2>(boardSize->i, boardSize->j);
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
