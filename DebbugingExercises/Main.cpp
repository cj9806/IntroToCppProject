// A Debugging Exercise by Marc Chee (marcc@aie.edu.au)
// 18/12/2016

// Marines are trying to "de-bug" an area (haha . . . haha)
// However something's up with this code . . . figure out what's going wrong
// When you're finished, there should be no compiler errors or warnings
// The encounter should also run and finish correctly as per the rules in the comments

// In many cases there are differences between what's in otherwise identical sections
// for Marines and Zerglings. It's good to be able to tell what the differences are
// and why they might be important.

// What's efficient and inefficient? Why?
// What uses more memory and what doesn't? Why?

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <algorithm>
#include <vector>
#include "Marine.h"
#include "Zergling.h"

using std::vector;
using std::cout;
using std::endl;

vector<Marine> squad;
vector<Zergling> swarm;

// Is there a Marine Alive?
bool marineAlive(vector<Marine> squad)
{
	return squad.size() > 0;
}

// Is there a zergling Alive
bool zerglingAlive(vector<Zergling> swarm)
{
	return swarm.size() > 0;
}

int main()
{


	int squadSize = 30;
	int swarmSize = 20;

	// Set up the Squad and the Swarm at their initial sizes listed above

	Marine m;
	for (size_t i = 0; i < squadSize; i++)
	{
		squad.push_back(m);
	}

	for (size_t i = 0; i < swarmSize; i++)
	{
		Zergling z;
		swarm.push_back(z);
	}

	cout << "A squad of marines approaches a swarm of Zerglings and opens fire! The Zerglings charge!" << endl;
	// Attack each other until only one team is left alive
	while (marineAlive(squad) && zerglingAlive(swarm)) // If anyone is left alive to fight . . .
	{
		srand(time(0));
		if (marineAlive(squad)) // if there's at least one marine alive
		{
			for (size_t i = 0; i < squadSize; i++) // go through the squad
			{
				// each marine will attack the first zergling in the swarm
				if (swarmSize == 0) {
					break;
				}
				else if (swarm[0].health <= 0)//check if marine is alive
				{
					cout << "The marine succumbs to his wounds." << endl;
					swarm.erase(swarm.begin());
					swarmSize--;

				}
				else {
					if (swarm.size() > 0)
					{
						cout << "A marine attacks for " << squad[i].attack() << " damage." << endl;
						int damage = squad[i].attack();
						swarm[0].takeDamage(damage);
					}
				}
			}
		}
		if (zerglingAlive(swarm)) // if there's at least one zergling alive
		{
			for (size_t i = 0; (i < swarmSize); i++) // loop through zerglings
			{
				if (squadSize == 0) {
					break;
				}
				else if (squad[0].health <= 0)//check if marine is alive
				{
					cout << "The marine succumbs to his wounds." << endl;
					squad.erase(squad.begin());
					squadSize--;

				}
				else {
					if (squad.size() > 0)
					{
						cout << "A zergling attacks for " << swarm[i].attack() << " damage." << endl;
						int damage = swarm[i].attack();
						squad[0].takeDamage(damage);
					}
				}
			}
		}
	}

	// Once one team is completely eliminated, the fight ends and one team wins
	cout << "The fight is over. ";
	if (marineAlive(squad))
	{
		cout << "The Marines win." << endl;
	}
	else
	{
		cout << "The Zerg win." << endl;
	}
}