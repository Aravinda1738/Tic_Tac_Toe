#pragma once
#include "framework.h"
#include <Windowsx.h>



class GameUI {

public:
	void Draw(HWND hWnd,HDC hdc, RECT* pRect);
	bool GetGameBoardRect(HWND hWnd, RECT* pRect);
	int GetCellNumberFromPoint(HWND hWnd,int xPos,int yPos);

	void printClick(HWND hWnd, POINT pt, int num);


public:

	
	const int cellSize = 100;


};


