#include"GameManager.h"


bool GameManager::isGameOver = false;
int GameManager::playerTurn = 0;
int GameManager::winner = 0;
cell GameManager::usedCells[9] = { {-1,0 },{-1,0 }, {-1,0 },{-1,0 },{-1,0 },{-1,0 }, {-1,0 },{-1,0 },{-1,0 } };


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
			if (winCheck())
			{
				GameManager::isGameOver = true;
				return false;
			}
			else if (totalTurnUsed > 7)
			{
				GameManager::isGameOver = true;
				return false;
			}

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
	for (int i = 0; i <=8; ++i) {
		usedCells[i].cellID = -1;
		usedCells[i].owner = 0;
	}
}

bool GameManager::winCheck()
{

	int player1[9];
	int player2[9];// = { -1,-1,-1,-1,-1,-1,-1 };

	for (int i = 0; i <= 8; i++) //sort
	{
		if (usedCells[i].owner == 1)
		{
			player1[i] = usedCells[i].cellID;

		}
		if (usedCells[i].owner == 2)
		{
			player2[i] = usedCells[i].cellID;

		}
	}

	int winCount1 = 0;
	for (int i = 0; i < 8; i++)  //winning conditions[8]
	{
		
		winCount1 = 0;
		for (int j = 0; j <= 8; j++)
		{



			if (WinningCondition[i].a == player1[j])
			{
				winCount1++;

			}
			if (WinningCondition[i].b == player1[j])
			{
				winCount1++;

			}
			if (WinningCondition[i].c == player1[j])
			{
				winCount1++;

			}

		}

		if (winCount1 == 3) {
			winner = 1;
			return true;
		}

	}


	int winCount2 = 0;
	for (int i = 0; i < 8; i++) //winning conditions[8]
	{
		winCount2 = 0;
		for (int j = 0; j <= 8; j++)
		{
			
			if (WinningCondition[i].a == player2[j])
			{
				winCount2++;

			}
			if (WinningCondition[i].b == player2[j])
			{
				winCount2++;

			}
			if (WinningCondition[i].c == player2[j])
			{
				winCount2++;

			}




		}
		if (winCount2 == 3) {
			winner = 2;
			return true;
		}


	}
	return false;
}







bool GameManager::checkUsedCells(int cellNum)
{

	for (int i = 0; i <= 8; i++)
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

void GameManager::resetGame()
{
	playerTurn = 0;
	winner = 0;
	totalTurnUsed = -1;
	isGameOver = false;
}
