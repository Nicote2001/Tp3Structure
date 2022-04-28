#pragma once
#include <string>
class Planet
{
public:
	std::string name;
	std::string nation;
	int population;
	float posX;
	float posY;
	float fuelPrice;

	Planet(std::string name, float posX, float posY, int population, std::string nation, float fuelPrice);
};

