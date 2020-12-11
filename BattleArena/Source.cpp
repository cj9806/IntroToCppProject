#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <algorithm>
#include "Hero.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

void sort(Hero arr[], int n)
{
	for (int i = 0;i < n;i++)
	{
		for (int j = 0; j < n - i;j++)
		{
			if (arr[j].health < arr[j + 1].health)
			{
				Hero temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void attack(Hero team1[], Hero team2[])
{
	//first member of each team attcks a random target
	for (int i = 0; i < 6;i++)
	{
		//team 1attack
		//check if hero has health left
		if (team1[i].health > 0)
		{
			//target at random till you hitone standing
			bool targeting = true;
			int target;
			while (targeting)
			{	
				target = rand() % 6;
				if (team2[target].health > 0) targeting = false;
			}
			int damage1 = (rand() % 20) + 1;
			team2[target].health -= damage1;
			cout << team1[i].name << " attacks " << team2[target].name << " with " << team1[i].attackName << " for " << damage1 << "damage!\n" << endl;
		}
		else if(team1[i].health<1)
		{
			cout << team1[i].name << " has fallen in battle\n" << endl;
		}
		//team 2 attack
		if (team2[i].health > 0)
		{
			//target at random till you hit one standing
			bool targeting = true;
			int target;
			while (targeting)
			{
				target = rand() % 6;
				if (team1[target].health > 0) targeting = false;
			}
			int damage2 = (rand() % 20) + 1;
			team1[target].health -= damage2;
			cout << team2[i].name << " attacks " << team1[target].name << " with " << team2[i].attackName << " for " << damage2 << "damage!\n" << endl;
		}
		else if(team2[i].health<1)
		{
			cout << team2[i].name << " has fallen in battle\n" << endl;
		}
	}
}

int main()
{
	
	//declare teams
	Hero teamIronman[6] = {};
	Hero teamCaptain[6] = {};

	

	//team rosters
	teamIronman[0].name = "Iron Man";
	teamIronman[1].name = "War Machine";
	teamIronman[2].name = "Black Widow";
	teamIronman[3].name = "Black Panther";
	teamIronman[4].name = "The Vision";
	teamIronman[5].name = "Spider-Man";

	teamCaptain[0].name = "Captain America";
	teamCaptain[1].name = "Hawkeye";
	teamCaptain[2].name = "Falcon";
	teamCaptain[3].name = "Winter Soldier";
	teamCaptain[4].name = "Ant Man";
	teamCaptain[5].name = "Scarlet Witch";

	//hero stats
	
	teamCaptain[0].health = 150;
	teamCaptain[3].health = 150;
	teamIronman[0].health = 150;
	teamIronman[1].health = 150;

	teamIronman[0].attackName = "a Repulsor Blast";
	teamIronman[1].attackName = "a Repulsor Blast";
	teamIronman[2].attackName = "the Widow Bite";
	teamIronman[3].attackName = "a Claw Slash";
	teamIronman[4].attackName = "a Laser Beam";
	teamIronman[5].attackName = "a Web shot";

	teamCaptain[0].attackName = "a Flying Sheild";
	teamCaptain[1].attackName = "an Arrow Strike";
	teamCaptain[2].attackName = "a Wing Slice";
	teamCaptain[3].attackName = "Machine Gun Fire";
	teamCaptain[4].attackName = "a Stomp Attack";
	teamCaptain[5].attackName = "a Telekenetic Barrage";

	cout << "Welcome to battle arena" << endl;
	cout << endl;
	system("pause");

	cout << endl;
	//main game loop
	bool running = true;
	while (running)
	{
		srand(time(0));
		//main combat
		attack(teamIronman, teamCaptain);
		//sort
		sort(teamIronman, 5);
		sort(teamCaptain, 5);
		
		//check for win
		if (teamIronman[0].health == 0)
		{
			cout << "Team Captain America has won!\nPress enter to end the program" << endl;
			system("pause");
		}
		if (teamCaptain[0].health == 0)
		{
			cout << "Team Iron Man has won!\nPress enter to end the program" << endl;
			system("pause");
		}
		//user input
		cout << "\nPress enter to continue" << endl;
		
		system("pause");
	}
	//combat
	

	return 0;
}