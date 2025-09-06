#include "GameUI.h"




void GameUI::Draw(HWND hWnd,HDC hdc, RECT * pRect)
{
	RECT rc;
	

	 // Rectangle(hdc, left, top, right, bottom);
		for (int i = 1; i < 3; i++)
		{
			MoveToEx(hdc, pRect->left + cellSize * i, pRect->top, NULL);
			LineTo(hdc, pRect->left + cellSize * i, pRect->bottom);

			MoveToEx(hdc, pRect->left, pRect->top + cellSize * i, NULL);
			LineTo(hdc, pRect->right, pRect->top + cellSize * i);



		}
	
	  
}

bool GameUI::GetGameBoardRect(HWND hWnd, RECT* pRect)
{
	RECT rc;
	if (GetClientRect(hWnd, &rc))
	{
		int width = rc.right - rc.left;
		int height = rc.bottom - rc.top;


		pRect->left = (width - cellSize * 3) / 2;
		pRect->top = (height - cellSize * 3) / 2;
		pRect->right = pRect->left + cellSize * 3;
		pRect->bottom = pRect->top + cellSize * 3;

		// Rectangle(hdc, left, top, right, bottom);

		return TRUE;

	}
	SetRectEmpty(pRect);
	return false;
}


int GameUI::GetCellNumberFromPoint(HWND hWnd, int xPos, int yPos)
{
	RECT rc;
	POINT pt = {xPos,yPos};
	
	if (GetGameBoardRect(hWnd,&rc))
	{

		if (PtInRect(&rc, pt))
		{
			xPos = pt.x - rc.left;
			yPos = pt.y - rc.top;


			int column = xPos / cellSize;
			int row = yPos / cellSize;




			return column + row * 3;
		}
	}
	
	

	return -1;
}

void GameUI::printClick(HWND hWnd, POINT pt,int num)
{
	HDC hdc = GetDC(hWnd);
	if (NULL != hdc)
	{
		WCHAR temp[100];

		wsprintf(temp, L"index = %d",num);
		//wsprintf(temp, L"index = %d , %d",pt.x,pt.y);
		TextOut(hdc, pt.x,pt.y, temp, lstrlen(temp));
		ReleaseDC(hWnd, hdc);
	}
}
