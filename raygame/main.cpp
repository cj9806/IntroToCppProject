#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

char gameBoard[3][3] = {
		{' ',' ',' '},
		{' ',' ',' '},
		{' ',' ',' '} };
void drawBoard()
{ 
	for (int i = 0;i < 3;i++) {
		cout << " " << gameBoard[i][0] << " | " << gameBoard[i][1] << " | " << gameBoard[i][2] << " | "<<endl;
		if (i < 2) {
			cout << "-------------"<<endl;
		}
	}
	
}
void takeTurn(bool turn) 
{

	int pos = 0;
	cin >> pos;
	if(turn)
	{
		if (pos == 1 && gameBoard[0][0] == ' ')
		{
			gameBoard[0][0] = 'X';
		}
		else if (pos == 2 && gameBoard[0][1] == ' ')
		{
			gameBoard[0][1] = 'X';
		}
		else if (pos == 3 && gameBoard[0][2] == ' ')
		{
			gameBoard[0][2] = 'X';
		}
		else if (pos == 4 && gameBoard[1][0] == ' ')
		{
			gameBoard[1][0] = 'X';
		}
		else if (pos == 5 && gameBoard[1][1] == ' ')
		{
			gameBoard[1][1] = 'X';
		}
		else if (pos == 6 && gameBoard[1][2] == ' ')
		{
			gameBoard[1][2] = 'X';
		}
		else if (pos == 7 && gameBoard[2][0] == ' ') {
			gameBoard[2][0] = 'X';
		}
		else if (pos == 8 && gameBoard[2][1] == ' ') {
			gameBoard[2][1] = 'X';
		}
		else if (pos == 9 && gameBoard[2][2] == ' ')
		{
			gameBoard[2][2] = 'X';
		}
		else 
		{
			cout << "not a valid input" << endl;
			pos = 0;
		}
	}
	else {
		if (pos == 1 && gameBoard[0][0])
		{
			gameBoard[0][0] = '0';
		}
		else if (pos == 2 && gameBoard[0][1])
		{
			gameBoard[0][1] = '0';
		}
		else if (pos == 3 && gameBoard[0][2])
		{
			gameBoard[0][2] = '0';
		}
		else if (pos == 4 && gameBoard[1][0])
		{
			gameBoard[1][0] = '0';
		}
		else if (pos == 5 && gameBoard[1][1])
		{
			gameBoard[1][1] = '0';
		}
		else if (pos == 6 && gameBoard[1][2])
		{
			gameBoard[1][2] = '0';
		}
		else if (pos == 7 && gameBoard[2][0]) {
			gameBoard[2][0] = '0';
		}
		else if (pos == 8 && gameBoard[2][1]) {
			gameBoard[2][1] = '0';
		}
		else if (pos == 9 && gameBoard[2][2])
		{
			gameBoard[2][2] = '0';
		}
		else
		{
			cout << "not a valid input" << endl;
			pos = 0;
		}
	}
}
char testWin()
{
	char win = '0';
	if      (gameBoard[0][0] == 'X' && gameBoard[0][1] == 'X' && gameBoard[0][2] == 'X') { win = '1'; }
	else if (gameBoard[1][0] == 'X' && gameBoard[1][1] == 'X' && gameBoard[1][2] == 'X') { win = '1'; }
	else if (gameBoard[2][0] == 'X' && gameBoard[2][1] == 'X' && gameBoard[2][2] == 'X') { win = '1'; }
	else if (gameBoard[0][0] == 'X' && gameBoard[1][0] == 'X' && gameBoard[2][0] == 'X') { win = '1'; }
	else if (gameBoard[0][1] == 'X' && gameBoard[1][1] == 'X' && gameBoard[2][1] == 'X') { win = '1'; }
	else if (gameBoard[0][2] == 'X' && gameBoard[1][2] == 'X' && gameBoard[2][2] == 'X') { win = '1'; }
	else if (gameBoard[1][1] == 'X' && gameBoard[2][2] == 'X' && gameBoard[0][0] == 'X') { win = '1'; }
	else if (gameBoard[2][0] == 'X' && gameBoard[2][2] == 'X' && gameBoard[0][2] == 'X') { win = '1'; }

	if      (gameBoard[0][0] == '0' && gameBoard[0][1] == '0' && gameBoard[0][2] == '0') { win = '2'; }
	else if (gameBoard[1][0] == '0' && gameBoard[1][1] == '0' && gameBoard[1][2] == '0') { win = '2'; }
	else if (gameBoard[2][0] == '0' && gameBoard[2][1] == '0' && gameBoard[2][2] == '0') { win = '2'; }
	else if (gameBoard[0][0] == '0' && gameBoard[1][0] == '0' && gameBoard[2][0] == '0') { win = '2'; }
	else if (gameBoard[0][1] == '0' && gameBoard[1][1] == '0' && gameBoard[2][1] == '0') { win = '2'; }
	else if (gameBoard[0][2] == '0' && gameBoard[1][2] == '0' && gameBoard[2][2] == '0') { win = '2'; }
	else if (gameBoard[1][1] == '0' && gameBoard[2][2] == '0' && gameBoard[0][0] == '0') { win = '2'; }
	else if (gameBoard[2][0] == '0' && gameBoard[2][2] == '0' && gameBoard[0][2] == '0') { win = '2'; }
	return win;

}

int main()
{
	bool turn = true;
	bool playing = true;
	while (playing) {
		drawBoard();
		takeTurn(turn);
		turn = !turn;
		testWin();
	}
	
	return 0;
}