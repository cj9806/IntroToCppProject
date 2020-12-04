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
bool turn = true;
void drawBoard()
{ 
	for (int i = 0;i < 3;i++) {
		cout << " " << gameBoard[i][0] << " | " << gameBoard[i][1] << " | " << gameBoard[i][2] << " | "<<endl;
		if (i < 2) {
			cout << "-------------"<<endl;
		}
	}
	
}
void takeTurn() 
{
	int pos;
	std::cout << "Enter 1-9" << std::endl;
	std::cin >> pos;
	
	if(turn)
	{
		if (pos == 1 && gameBoard[0][0] == ' ')
		{
			gameBoard[0][0] = 'X';
			turn = !turn;
		}
		else if (pos == 2 && gameBoard[0][1] == ' ')
		{
			gameBoard[0][1] = 'X';
			turn = !turn;
		}
		else if (pos == 3 && gameBoard[0][2] == ' ')
		{
			gameBoard[0][2] = 'X';
			turn = !turn;
		}
		else if (pos == 4 && gameBoard[1][0] == ' ')
		{
			gameBoard[1][0] = 'X';
			turn = !turn;
		}
		else if (pos == 5 && gameBoard[1][1] == ' ')
		{
			gameBoard[1][1] = 'X';
			turn = !turn;
		}
		else if (pos == 6 && gameBoard[1][2] == ' ')
		{
			gameBoard[1][2] = 'X';
			turn = !turn;
		}
		else if (pos == 7 && gameBoard[2][0] == ' ') {
			gameBoard[2][0] = 'X';
			turn = !turn;
		}
		else if (pos == 8 && gameBoard[2][1] == ' ') {
			gameBoard[2][1] = 'X';
			turn = !turn;
		}
		else if (pos == 9 && gameBoard[2][2] == ' ')
		{
			gameBoard[2][2] = 'X';
			turn = !turn;
		}	
		else {
			while (std::cin.fail())
			{
				std::cout << "Invalid Entry\nEnter 1-9" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin >> pos;
				if (pos == 0) { std::cin.fail(); }
			}
		}
	}
	else {
		if (pos == 1 && gameBoard[0][0])
		{
			gameBoard[0][0] = '0';
			turn = !turn;
		}
		else if (pos == 2 && gameBoard[0][1])
		{
			gameBoard[0][1] = '0';
			turn = !turn;
		}
		else if (pos == 3 && gameBoard[0][2])
		{
			gameBoard[0][2] = '0';
			turn = !turn;
		}
		else if (pos == 4 && gameBoard[1][0])
		{
			gameBoard[1][0] = '0';
			turn = !turn;
		}
		else if (pos == 5 && gameBoard[1][1])
		{
			gameBoard[1][1] = '0';
			turn = !turn;
		}
		else if (pos == 6 && gameBoard[1][2])
		{
			gameBoard[1][2] = '0';
			turn = !turn;
		}
		else if (pos == 7 && gameBoard[2][0]) {
			gameBoard[2][0] = '0';
			turn = !turn;
		}
		else if (pos == 8 && gameBoard[2][1]) {
			gameBoard[2][1] = '0';
			turn = !turn;
		}
		else if (pos == 9 && gameBoard[2][2])
		{
			gameBoard[2][2] = '0';
			turn = !turn;
		}
		
	}
}
int testWin()
{
	int win = 0;
	if      (gameBoard[0][0] == 'X' && gameBoard[0][1] == 'X' && gameBoard[0][2] == 'X') { win = 1; }
	else if (gameBoard[1][0] == 'X' && gameBoard[1][1] == 'X' && gameBoard[1][2] == 'X') { win = 1; }
	else if (gameBoard[2][0] == 'X' && gameBoard[2][1] == 'X' && gameBoard[2][2] == 'X') { win = 1; }
	else if (gameBoard[0][0] == 'X' && gameBoard[1][0] == 'X' && gameBoard[2][0] == 'X') { win = 1; }
	else if (gameBoard[0][1] == 'X' && gameBoard[1][1] == 'X' && gameBoard[2][1] == 'X') { win = 1; }
	else if (gameBoard[0][2] == 'X' && gameBoard[1][2] == 'X' && gameBoard[2][2] == 'X') { win = 1; }
	else if (gameBoard[1][1] == 'X' && gameBoard[2][2] == 'X' && gameBoard[0][0] == 'X') { win = 1; }
	else if (gameBoard[2][0] == 'X' && gameBoard[2][2] == 'X' && gameBoard[0][2] == 'X') { win = 1; }

	if      (gameBoard[0][0] == '0' && gameBoard[0][1] == '0' && gameBoard[0][2] == '0') { win = 2; }
	else if (gameBoard[1][0] == '0' && gameBoard[1][1] == '0' && gameBoard[1][2] == '0') { win = 2; }
	else if (gameBoard[2][0] == '0' && gameBoard[2][1] == '0' && gameBoard[2][2] == '0') { win = 2; }
	else if (gameBoard[0][0] == '0' && gameBoard[1][0] == '0' && gameBoard[2][0] == '0') { win = 2; }
	else if (gameBoard[0][1] == '0' && gameBoard[1][1] == '0' && gameBoard[2][1] == '0') { win = 2; }
	else if (gameBoard[0][2] == '0' && gameBoard[1][2] == '0' && gameBoard[2][2] == '0') { win = 2; }
	else if (gameBoard[1][1] == '0' && gameBoard[2][2] == '0' && gameBoard[0][0] == '0') { win = 2; }
	else if (gameBoard[2][0] == '0' && gameBoard[2][2] == '0' && gameBoard[0][2] == '0') { win = 2; }
	return win;

}
bool playing = true;
int main()
{	
	
	while (playing) {
		drawBoard();
		takeTurn();
		int win = testWin();
		if (win == 1) {
			cout << "congatulations player 1 wins" << endl;
			cout << "would you like to play again?\n" << "y/n" << endl;
			char again;
			cin >> again;
			if (again == 'y' ||again == 'Y')
			{
				win = 0;
				for (int i = 0;i < 3;i++) {
					for (int j = 0;j < 3;j++) {
						gameBoard[i][j] = ' ';
					}
				}
				turn = true;
			}
			else if(again == 'n'||again =='N') {
				playing = false;
			}
		}
		if (win == 1) {
			cout << "congatulations player 2 wins" << endl;
			cout << "would you like to play again?\n" << "y/n" << endl;
			char again;
			cin >> again;
			if (again == 'y' || again == 'Y')
			{
				win = 0;
				for (int i = 0;i < 3;i++) {
					for (int j = 0;j < 3;j++) {
						gameBoard[i][j] = ' ';
					}
				}
				turn = true;
			}
			else if (again == 'n' || again == 'N') {
				playing = false;
			}
		}

	}
	
	return 0;
}