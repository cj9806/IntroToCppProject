#pragma once
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::rand;

class Hero
{
public:
	string name;
	int health = 100;
	string attackName;
	int minAttack;
	int maxAttack;

	void Attack(Hero enemy)
	{
		
	}
};

