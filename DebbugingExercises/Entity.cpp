#include "Entity.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <algorithm>


Entity::Entity()
{
	maxHealth = 50;
	health = 50;
}


Entity::~Entity()
{
}

bool Entity::isAlive()
{
	return health > 0;
}
void Entity::takeDamage(int damage) 
{
	health -= damage;
}
int Entity::attack() {
	return rand() % 10 + 1;	
}
