#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Ship.h"
#include "Planet.h"

using namespace std;

class Game
{
public:
	Game();

	vector<Ship*> shipslist;
	vector<Planet*> planetList;

	void PlanetFileReader(std::string fileName);
	void ShipFileReader(std::string fileName);
	void TransactionFileReader(std::string fileName);	

	//pas encore implemanter
	void IsCrossable();
	void FindShortWay();
	void FindCheapestWAy();

private:

};

