#pragma once



struct cell {
	int cellID;
	int owner;

};
struct winSet {
	int a;
	int b;
	int c;

};

 class GameManager {


public:
	

	 bool UsePlayerTurn(int playerSelectedCell);
	 void clearCells();
	 bool winCheck();
	void resetGame();
private:
	



	bool checkUsedCells(int cellNum);
	void addTurn();


public:
	static bool isGameOver;
	static int playerTurn;
	static cell usedCells[9];
private:
	int totalTurnUsed = -1;
	winSet WinningCondition[8]{ {0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{3,5,8},{0,4,8},{2,4,6} };
	//012
	//345
	//678
	




};