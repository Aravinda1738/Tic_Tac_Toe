#include "GameUI.h"




void GameUI::Draw(HWND hWnd, HDC hdc, RECT* pRect)
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

		return true;

	}
	SetRectEmpty(pRect);
	return false;
}

bool GameUI::GetCellRect(HWND hWnd, int index, RECT* pRect)
{
	RECT rcBoard;
	SetRectEmpty(pRect);
	if (index < 0 || index>8)
	{
		return false;
	}
	if (GetGameBoardRect(hWnd, &rcBoard))
	{
		int x = index % 3;
		int y = index / 3;

		pRect->left = (rcBoard.left + x * cellSize)+1;
		pRect->top = (rcBoard.top + y * cellSize)+1;
		pRect->right = (pRect->left + cellSize)-1;
		pRect->bottom = (pRect->top + cellSize)-1;
		return true;
	}

	return false;
}


int GameUI::GetCellNumberFromPoint(HWND hWnd, int xPos, int yPos)
{
	RECT rc;
	POINT pt = { xPos,yPos };

	if (GetGameBoardRect(hWnd, &rc))
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

void GameUI::printClick(HWND hWnd, POINT pt, int num)
{
	HDC hdc = GetDC(hWnd);
	if (NULL != hdc)
	{
		WCHAR temp[100];

		wsprintf(temp, L"index = %d", num);
		//wsprintf(temp, L"index = %d , %d",pt.x,pt.y);
		TextOut(hdc, pt.x, pt.y, temp, lstrlen(temp));
		ReleaseDC(hWnd, hdc);
	}
}

void GameUI::CreateUiBrush()
{
	hbr_Red = CreateSolidBrush(RGB(255, 0, 0));
	hbr_Blue = CreateSolidBrush(RGB(0, 0, 255));
	hrb_black = CreateSolidBrush(RGB(0, 0, 0));
}

HBRUSH GameUI::GetPlayerColour(int playerTurn)
{
	
	
	switch (playerTurn)
	{
	case 1:
	{
		return hbr_Red;
	}
	break;
	case 2:
	{
		return hbr_Blue;
	}
	break;
	case -1:
	{
		return hrb_black;
	}
	default:
		break;
	}
	
}
void GameUI::DeleteUiBrush()
{
	DeleteObject(hbr_Red);
	DeleteObject(hbr_Blue);
	DeleteObject(hrb_black);
}

