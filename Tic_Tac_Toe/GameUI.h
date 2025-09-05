#pragma once
#include "framework.h"
#include "Windowsx.h"



class GameUI {

public:
	void Draw(HDC hdc, HWND hwnd);
	int GetCellNumberFromPoint(HWND hwnd,int xPos,int yPos);



public:

	RECT rc{};
	const int cellSize = 100;


};


