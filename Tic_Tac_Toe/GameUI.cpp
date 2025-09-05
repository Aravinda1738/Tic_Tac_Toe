#include "GameUI.h"




void GameUI::Draw(HDC hdc, HWND hwnd)
{
	
	if (GetClientRect(hwnd, &rc))
	{
		int width = rc.right - rc.left;
		int height = rc.bottom - rc.top;
		

		int left = (width - cellSize * 3) / 2;
		int top = (height - cellSize * 3) / 2;
		int right = left + cellSize * 3;
		int bottom = top + cellSize * 3;

	 // Rectangle(hdc, left, top, right, bottom);

	  for (int i=1;i<3;i++)
	  {
		  MoveToEx(hdc, left + cellSize*i, top, NULL);
		  LineTo(hdc, left + cellSize*i, bottom);

		  MoveToEx(hdc, left, top + cellSize * i, NULL);
		  LineTo(hdc, right, top+ cellSize * i);
	  }

	 
	}

}


int GameUI::GetCellNumberFromPoint(HWND hwnd, int xPos, int yPos)
{
	RECT rc;

	return -1;
}
