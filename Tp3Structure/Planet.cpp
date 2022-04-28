#include "Planet.h"

Planet::Planet(int id, std::string name, float posX, float posY, int population, std::string nation, float fuelPrice)
{
	this->id = id;
	this->name = name;
	this->fuelPrice = fuelPrice;
	this->nation = nation;
	this->population = population;
	this->posX = posX;
	this->posY = posY;
}

void Planet::addConflit(std::string nation)
{
	this->enemy.push_back(nation);
}
