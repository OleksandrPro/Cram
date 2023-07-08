#pragma once

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