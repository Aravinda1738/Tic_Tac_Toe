#pragma once
#include <Windowsx.h>

#include "framework.h"
#include "GameManager.h"



class GameUI {

public:
	void Drawboard(HWND hWnd, HDC hdc, RECT* pRect);
	bool GetGameBoardRect(HWND hWnd, RECT* pRect);
	bool GetCellRect(HWND hWnd, int index, RECT* pRect);
	int GetCellNumberFromPoint(HWND hWnd, int xPos, int yPos);

	void printClick(HWND hWnd, POINT pt, int num);

	void UpdateUiInCell(HDC hdc, HWND hWnd,int index);
	void UpdateUiCells(HDC hdc, HWND hWnd);
	void ClearUiCells(HDC hdc, HWND hWnd);


	void DrawUiPlayerTurn(HDC hdc, HWND hWnd);

public:


	const int cellSize = 100;
	void DeleteUiBrush();
	void CreateUiBrush();
	
	HBRUSH GetPlayerColour(int cellIndex);
private:
	HBRUSH hbr_Red, hbr_Blue,hrb_black, hrb_white;
	GameManager gm;
};


