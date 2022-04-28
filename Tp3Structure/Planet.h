#pragma once
#include <string>
#include <vector>
class Planet
{
public:
	int id;
	std::string name;
	std::string nation;
	int population;
	float posX;
	float posY;
	float fuelPrice;
	std::vector<std::string> enemy;

	Planet(int id, std::string name, float posX, float posY, int population, std::string nation, float fuelPrice);

	void addConflit(std::string);
};

