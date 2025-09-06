#include"GameManager.h"


bool GameManager::isGameOver = false;
int GameManager::playerTurn = 0;
cell GameManager::usedCells[8] = { {-1,0 },{-1,0 }, {-1,0 },{-1,0 },{-1,0 },{-1,0 }, {-1,0 },{-1,0 } };


bool GameManager::UsePlayerTurn(int playerSelectedCell)
{



	if (totalTurnUsed > 7)
	{
		GameManager::isGameOver = true;
		return false;
	}
	else
	{
		if (checkUsedCells(playerSelectedCell) == false) // to check if selected cell is occupied
		{
			totalTurnUsed++;
			usedCells[totalTurnUsed].cellID = playerSelectedCell;


			addTurn();
			usedCells[totalTurnUsed].owner = playerTurn;
			winCheck();
			return true;


			/*if ((playerSelectedCell + 1) % 2 == 1 )
			{
				GameManager::playerTurn = 1;
				return true;
			}
			if ((playerSelectedCell + 1) % 2 == 0)
			{

			}*/
		}
	}



}

void GameManager::clearCells()
{
	for (int i = 0; i < 8; ++i) {
		usedCells[i].cellID = 0;
		usedCells[i].owner = 0;
	}
}

void GameManager::winCheck()
{

	int player1[5];
	int player2[5];

	for (int i = 0; i < 8; i++)
	{
		if (usedCells[i].owner == 1)
		{
			player1[i] = usedCells[i].cellID;

		}
		if (usedCells->owner == 2)
		{
			player2[i] = usedCells[i].cellID;

		}
	}

	int winCount1 = 0;
	for (int i = 0; i < 8; i++)
	{
		if (player1[i] == WinningCondition[i].a &&
			player1[i] == WinningCondition[i].b &&
			player1[i] == WinningCondition[i].c)
		{
			winCount1++;
		}
		if (winCount1 == 3) {
			GameManager::isGameOver = true;
			return;
		}
		else
		{
			winCount1 = 0;
		}

	}
	int winCount2 = 0;
	for (int i = 0; i < 8; i++)
	{
		if (player2[i] == WinningCondition[i].a &&
			player2[i] == WinningCondition[i].b &&
			player2[i] == WinningCondition[i].c)
		{
			winCount2++;
		}
		if (winCount2 == 3) {
			GameManager::isGameOver = true;
			return;
		}
		else
		{
			winCount2 = 0;
		}

	}
}







bool GameManager::checkUsedCells(int cellNum)
{

	for (int i = 0; i < 8; i++)
	{
		if (usedCells[i].cellID == cellNum)
		{
			return true;
		}
	}

	return false;
}

void GameManager::addTurn()
{
	playerTurn++;
	if (playerTurn > 2)
	{
		playerTurn = 1;
	}

}
