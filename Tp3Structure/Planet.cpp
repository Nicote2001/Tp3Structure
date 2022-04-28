#include "Planet.h"

Planet::Planet(std::string name, float posX, float posY, int population, std::string nation, float fuelPrice)
{
	this->name = name;
	this->fuelPrice = fuelPrice;
	this->nation = nation;
	this->population = population;
	this->posX = posX;
	this->posY = posY;
}
