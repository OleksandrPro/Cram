#pragma once

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