#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Ship.h"
#include "Planet.h"
#include "Graph.h"

using namespace std;

struct Conflit{
	std::string NationA;
	std::string NationB;
};

class Game
{
public:
	Game();

	vector<Ship*> shipslist;
	vector<Planet*> planetList;
	vector<Conflit> conflitList;
	Graph graph;

	void PlanetFileReader(std::string fileName);
	void ShipFileReader(std::string fileName);
	void TransactionFileReader(std::string fileName);
	void initGraph();

	//pas encore implemanter
	void IsCrossable(int start,Ship ship,int destination);
	void FindShortWay();
	void FindCheapestWAy();

	void CreateConflict(std::string NationA, std::string NationB);
	void Afficher();

private:

};

