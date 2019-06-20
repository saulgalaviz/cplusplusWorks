#include <iostream>
#include <fstream>

using namespace std;

bool won (char[], char);
void tie (char[]);
int victory(char, char[]);
int move (char[], char, int);

int main(char* board[], char tic)
{
	char map[13];
	int emptySpace = 0;

	ifstream getBoard;
	getBoard.open(board[1]);
	getBoard >> map;
	getBoard.close();

	for (int counter = 0; counter < 12; counter++)
	{
		if (map[counter] == ' ')
			emptySpace++;
	}

	int placement = victory(tic, map);
	if (placement == 12)
		placement = move(map, tic, emptySpace);
	map[placement] = tic;

	ofstream printBoard;
	printBoard.open(board[1]);
	printBoard << map;
	printBoard.close();

	if (!won(map, tic))
		tie(map);

	return 0;
}

bool won(char map[], char tic)
{
	bool won = false;
	bool enemyWon = false;
	char enemyTic;

	if (tic == 'X')
		enemyTic = 'O';

	else if (tic == 'O')
		enemyTic = 'X';

	if (map[0] == map[4] == map[8] == tic)
		won = true;
	if (map[1] == map[5] == map[9] == tic)
		won = true;
	if (map[2] == map[6] == map[10] == tic)
		won = true;

	if (map[0] == map[1] == map[2] == tic)
		won = true;
	if (map[4] == map[5] == map[6] == tic)
		won = true;
	if (map[8] == map[9] == map[10] == tic)
		won = true;

	if (map[0] == map[5] == map[10] == tic)
		won = true;
	if (map[8] == map[5] == map[2] == tic)
		won = true;

	if (won)
		cout << tic << "Wins!" << endl;

	//---------------------------------------

	if (map[0] == map[4] == map[8] == enemyTic)
		enemyWon = true;
	if (map[1] == map[5] == map[9] == enemyTic)
		enemyWon = true;
	if (map[2] == map[6] == map[10] == enemyTic)
		enemyWon = true;

	if (map[0] == map[1] == map[2] == enemyTic)
		enemyWon = true;
	if (map[4] == map[5] == map[6] == enemyTic)
		enemyWon = true;
	if (map[8] == map[9] == map[10] == enemyTic)
		enemyWon = true;

	if (map[0] == map[5] == map[10] == enemyTic)
		enemyWon = true;
	if (map[8] == map[5] == map[2] == enemyTic)
		enemyWon = true;

	if (enemyWon)
		cout << enemyTic << "Wins!" << endl;

	if (won || enemyWon)
		return true;

	else
		return false;
}

void tie(char map[])
{
	if (map[0] == map[1] == map[2] == map[4] == map[5] == map[6] == map[8] == map[9] == map[10] == ('X' || 'O'))
		cout << "Both players tied." << endl;
}

int victory(char tic, char map[])
{
	int placement = 12;
	char enemyTic;

	if (tic == 'X')
		enemyTic = 'O';

	else if (tic == 'O')
		enemyTic = 'X';

	//Check if you can win first.

	//Vertical
	if (map[0] == map[4] == tic && map[8] == ' ')
		placement = 8;

	else if (map[0] == map[8] == tic && map[4] == ' ')
		placement = 4;

	else if (map[4] == map[8] == tic && map[0] == ' ')
		placement = 0;


	else if (map[1] == map[5] == tic && map[9] == ' ')
		placement = 9;

	else if (map[1] == map[9] == tic && map[5] == ' ')
		placement = 5;

	else if (map[5] == map[9] == tic && map[1] == ' ')
		placement = 1;


	else if (map[2] == map[6] == tic && map[10] == ' ')
		placement = 10;

	else if (map[2] == map[10] == tic && map[6] == ' ')
		placement = 6;

	else if (map[6] == map[10] == tic && map[2] == ' ')
		placement = 2;

	//Horizontal
	else if (map[0] == map[1] == tic && map[2] == ' ')
		placement = 2;

	else if (map[0] == map[2] == tic && map[1] == ' ')
		placement = 1;

	else if (map[1] == map[2] == tic && map[0] == ' ')
		placement = 0;


	else if (map[4] == map[5] == tic && map[6] == ' ')
		placement = 6;

	else if (map[4] == map[6] == tic && map[5] == ' ')
		placement = 5;

	else if (map[5] == map[6] == tic && map[4] == ' ')
		placement = 4;


	else if (map[8] == map[9] == tic && map[10] == ' ')
		placement = 10;

	else if (map[8] == map[10] == tic && map[9] == ' ')
		placement = 9;

	else if (map[9] == map[10] == tic && map[8] == ' ')
		placement = 8;

	//Diagonal
	else if (map[0] == map[5] == tic && map[10] == ' ')
		placement = 10;

	else if (map[0] == map[10] == tic && map[5] == ' ')
		placement = 5;

	else if (map[5] == map[10] == tic && map[0] == ' ')
		placement = 0;


	else if (map[2] == map[5] == tic && map[8] == ' ')
		placement = 8;

	else if (map[2] == map[8] == tic && map[5] == ' ')
		placement = 5;

	else if (map[5] == map[8] == tic && map[2] == ' ')
		placement = 2;

	//If you can't win, but you want to prevent enemy from winning

	//Vertical
	else if (map[0] == map[4] == enemyTic && map[8] == ' ')
		placement = 8;

	else if (map[0] == map[8] == enemyTic && map[4] == ' ')
		placement = 4;

	else if (map[4] == map[8] == enemyTic && map[0] == ' ')
		placement = 0;


	else if (map[1] == map[5] == enemyTic && map[9] == ' ')
		placement = 9;

	else if (map[1] == map[9] == enemyTic && map[5] == ' ')
		placement = 5;

	else if (map[5] == map[9] == enemyTic && map[1] == ' ')
		placement = 1;


	else if (map[2] == map[6] == enemyTic && map[10] == ' ')
		placement = 10;

	else if (map[2] == map[10] == enemyTic && map[6] == ' ')
		placement = 6;

	else if (map[6] == map[10] == enemyTic && map[2] == ' ')
		placement = 2;

	//Horizontal
	else if (map[0] == map[1] == enemyTic && map[2] == ' ')
		placement = 2;

	else if (map[0] == map[2] == enemyTic && map[1] == ' ')
		placement = 1;

	else if (map[1] == map[2] == enemyTic && map[0] == ' ')
		placement = 0;


	else if (map[4] == map[5] == enemyTic && map[6] == ' ')
		placement = 6;

	else if (map[4] == map[6] == enemyTic && map[5] == ' ')
		placement = 5;

	else if (map[5] == map[6] == enemyTic && map[4] == ' ')
		placement = 4;


	else if (map[8] == map[9] == enemyTic && map[10] == ' ')
		placement = 10;

	else if (map[8] == map[10] == enemyTic && map[9] == ' ')
		placement = 9;

	else if (map[9] == map[10] == enemyTic && map[8] == ' ')
		placement = 8;

	//Diagonal
	else if (map[0] == map[5] == enemyTic && map[10] == ' ')
		placement = 10;

	else if (map[0] == map[10] == enemyTic && map[5] == ' ')
		placement = 5;

	else if (map[5] == map[10] == enemyTic && map[0] == ' ')
		placement = 0;


	else if (map[2] == map[5] == enemyTic && map[8] == ' ')
		placement = 8;

	else if (map[2] == map[8] == enemyTic && map[5] == ' ')
		placement = 5;

	else if (map[5] == map[8] == enemyTic && map[2] == ' ')
		placement = 2;

	return placement;
}

int move(char map[], char tic, int emptySpace)
{
	int placement = 12;
	char enemyTic;

	if (tic == 'X')
		enemyTic = 'O';

	else if (tic == 'O')
		enemyTic = 'X';

	switch (emptySpace)
	{
	case 9:
		if (map[0] == map[1] == map[2] == map[4] == map[5] == map[6] == map[8] == map[9] == map[10] == ' ')
			placement = 0;
		break;
	case 8:
		if ((map[0] || map[2] || map[8] || map[10]) == enemyTic) // Corner pieces
			placement = 5;

		else if (map[1] == enemyTic)
			placement = 2;

		else if (map[4] == enemyTic)
			placement = 0;

		else if (map[6] == enemyTic)
			placement = 10;

		else if (map[9] == enemyTic)
			placement = 8;

		else if (map[5] == enemyTic) //Center piece
			placement = 10;
		break;
	case 7:
		if ((map[1] || map[4] || map[6] || map[9]) == tic)
		{
			if (map[5] == enemyTic)
				placement = 10;
			else
				placement = 5;
		}

		else if (map[0] == tic)
		{
			if (map[10] == enemyTic)
				placement = 5;
			else
				placement = 10;
		}

		else if (map[2] == tic)
		{
			if (map[8] == enemyTic)
				placement = 5;
			else
				placement = 8;
		}

		else if (map[8] == tic)
		{
			if (map[2] == enemyTic)
				placement = 5;
			else
				placement = 2;
		}

		else if (map[10] == tic)
		{
			if (map[0] == enemyTic)
				placement = 5;
			else
				placement = 0;
		}

		else if (map[5] == tic && (map[8] || map[0] || map[2] || map[10]) == enemyTic)
		{
			if (map[8] == enemyTic)
				placement = 10;
			else
				placement = 8;
		}

		else if (map[5] == tic && (map[1] || map[4] || map[6] || map[9]) == enemyTic)
		{
			if (map[1] == enemyTic)
				placement = 2;

			else if (map[4] = enemyTic)
				placement = 0;

			else if (map[6] = enemyTic)
				placement = 10;

			else
				placement = 8;
		}
		break;
	case 0:
		cout << "There are no more spaces!" << endl;
	}

	if (placement == 12 || map[placement] == enemyTic)
	{
		if (map[5] == ' ')
			placement = 5;
		else if (map[0] == ' ')
			placement = 0;
		else if (map[2] == ' ')
			placement = 2;
		else if (map[8] == ' ')
			placement = 8;
		else if (map[10] == ' ')
			placement = 10;
		else if (map[1] == ' ')
			placement = 1;
		else if (map[4] == ' ')
			placement = 4;
		else if (map[6] == ' ')
			placement = 6;
		else if (map[9] == ' ')
			placement = 9;
		
	}

	return placement;
}