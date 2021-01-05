#include "Marine.h"



Marine::Marine()
{
	int health = 50;
}


Marine::~Marine()
{
}

int Marine::attack()
{
	return 10;
}

void Marine::takeDamage(int damage)
{
	health -= damage;
}
