#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
int search(int array[], int l, int r)
{
	int mid = (l+r)/2;
	
	
	cout << "Is your number " << mid << "?" << endl;
	cout << "1)This is my number, Your really good!\n2)My number is higher that this.\n3)My number is lower than this." << endl;
	char choice[50] = {};
	cin >> choice;
	//if its right
	if(choice[0] == '1')
	{
		return mid;
	}
	// the number is higher
	else if(choice[0] == '2')
	{
		return search(array, mid + 1, r);
	}
	//if the numberis lower
	else if(choice[0] == '3')
	{
		return search(array, l, mid - 1);
	}
	//all else fails
	else 
	{ 
		cout << "I'm sorry, I dont understand" << endl;
		return search(array, l, r);
	}
	
}

int main()
{
	
	//game loop
	bool playing = true;
	while (playing) {
		cout << "I'm really good at guessing numbers, think of a rangeofnumbersandill figure it out" << endl;
		//declare search area as null for dynamic pointing
		int* searchArea = NULL;
		//get data from player
		
		cout << "Enter a minumum range" << endl;
		int minRange = 0;
		cin >> minRange;

		cout << "now enter a maximum range" << endl;
		int maxRange = 0;
		cin >> maxRange;

		cout << "now think of a number between those two and I'll find out\nPress Enter to Continue" << endl;
		cin;
		//create array to search
		searchArea = new int[maxRange];
		for (int i = 0;i < maxRange;i++)
		{
			searchArea[i] = minRange + i;
		}
		//search  teh array
		int guess = search(searchArea, minRange, maxRange);
		cout << "the number you are thinkingof is: " << guess <<"!"<< endl;
		
		

		//c++ looks at memory, and says to your face "pick it up bitch"
		delete[] searchArea;
		searchArea = NULL;

		//ask if  they want to play again
		cout << "Would you like to play again?\nY/N" << endl;
		char choice[50];
		cin >> choice;
		if (choice[0] == 'Y'||'y');
		else playing = false;
	}
	return 0;
}