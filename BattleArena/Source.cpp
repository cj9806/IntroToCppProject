#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include "Hero.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;


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
	teamCaptain[3].name = "Ant Man";
	teamCaptain[3].name = "Scarlet Witch";

	//hero stats
	/*Ironman, WM, WS, and Cap all have +50% health on account of being super soldier/walking artilery platforms, all others will have base 100 health
	* all attacks will deal 10*(x/10) damage
	  IM,WM attacks  will be called repulsor blasts
	  Black  widow will get The Widows Bite
	  black panther has claws
	  vision has a gatt danged lazer
	  spiderman has web shot

	  captain america has a sheild throw
	  Hawkeye get expert arrow
	  falcon has a wing attack
	  winter soldier has gun
	  ant man has stomp
	  scarlet witch has Telekenetic barrage
	*/

	return 0;
}