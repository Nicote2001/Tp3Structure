#include "Game.h"
#include <cmath>

void Game::initGraph() {
	for(Planet * var : planetList)
	{
		for (Planet * var2 : planetList)
		{
			float DiffX = 0;
			float DiffY = 0;
			float distance = 0;
			float cout = 0;
			bool trajet = false;

			if (var != var2) {
				DiffX = var->posX - var2->posX;
				DiffY = var->posY - var2->posY;
				distance = sqrt(pow(DiffX, 2) + pow(DiffY, 2));
				cout = var->fuelPrice * distance;
				trajet = distance <= 250;
			}
			
			graph.add(var->id, var2->id, trajet, distance, cout);
		}
	}
}

void Game::PlanetFileReader(std::string fileName)
{
	ifstream file;
	std::string tmpName, tmpNation;
	float tmpFuelPrice, tmpPosX, tmpPosY;
	int tmpPopulation;

	file.open(fileName);

	if (!file.fail()) {

		while (!file.eof()) {

			file >> tmpName;
			file >> tmpPosX;
			file >> tmpPosY;
			file >> tmpPopulation;
			file >> tmpNation;
			file >> tmpFuelPrice;

			planetList.push_back(new Planet(planetList.size(), tmpName, tmpPosX, tmpPosY, tmpPopulation, tmpNation, tmpFuelPrice));
		}

		file.close();
	}
	initGraph();

}

void Game::ShipFileReader(std::string fileName)
{
	ifstream file;
	std::string tmpType;
	float tmpFuel;

	file.open(fileName);

	if (!file.fail()) {

		while (!file.eof()) {

			file >> tmpType;
			file >> tmpFuel;

			shipslist.push_back(new Ship(tmpFuel, tmpType));
		}

		file.close();
	}
}

void Game::TransactionFileReader(std::string fileName)
{
	std::ifstream FicTransaction;
	char Entree;
	std::string TmpString, TmpString2, TmpString3;
	int TmpInt1, TmpInt2, TmpInt3;

	FicTransaction.open(fileName);

	if (!FicTransaction.fail()) {

		while (!FicTransaction.eof()) {

			FicTransaction >> Entree;

			switch (Entree) {
			case '#V':
				FicTransaction >> TmpString;
				ShipFileReader(TmpString);
				break;

			case '#P':
				FicTransaction >> TmpString;
				PlanetFileReader(TmpString);
				break;

			case '?1':
				FicTransaction >> TmpString;
				FicTransaction >> TmpString2;
				FicTransaction >> TmpString3;
				//inserer dans la fonction
				IsCrossable();
				break;

			case '?2':
				FicTransaction >> TmpString;
				FicTransaction >> TmpString2;
				FicTransaction >> TmpString3;
				//inserer dans la fonction
				FindShortWay();
				break;

			case '?3':
				FicTransaction >> TmpString;
				FicTransaction >> TmpString2;
				FicTransaction >> TmpString3;
				//inserer dans la fonction
				FindCheapestWAy();
				break;

			case '/':
				FicTransaction >> TmpString;
				FicTransaction >> TmpString2;
				//inserer dans la fonction
				CreateConflict(TmpString, TmpString2);
				break;

			case '&':
				//afficher tout les V , S et conflits
				break;

			default:
				std::cout << "Probleme de lecture de la transaction." << std::endl;
			}
		}

		FicTransaction.close();

	}
}

void Game::IsCrossable()
{
}

void Game::FindShortWay()
{
}

void Game::FindCheapestWAy()
{
}

void Game::CreateConflict(std::string NationA, std::string NationB)
{

	// Ajout à une liste pour l'affichage

	Conflit Tmp;
	Tmp.NationA = NationA;
	Tmp.NationB = NationB;

	conflitList.push_back(Tmp);

	// Ajout conflit pour Nation A

	for (Planet* Var : planetList) {
		if (NationA == Var->nation) {
			Var->addConflit(NationB);
		}
	}

	// Ajout Conflit pour Nation B

	for (Planet* Var : planetList) {
		if (NationB == Var->nation) {
			Var->addConflit(NationA);
		}
	}

}

void Game::Afficher()
{
	// Afficher Planet
	std::cout << "/////////////////////// Planètes ///////////////////////" << endl;

	for (Planet* Var : planetList) {

		std::cout << std::endl;

		std::cout << "Nom: " << Var->name << std::endl;
		std::cout << "Nation: " << Var->nation << std::endl;
		std::cout << "Population: " << Var->population << std::endl;
		std::cout << "Coord: " << Var->posX << " , " << Var->posY << std::endl;
		std::cout << "En guerre avec: ";

		for (std::string NationEn : Var->enemy) {
			std::cout << NationEn;
		}

		std::cout << std::endl;
		std::cout << "-----------" << std::endl;
		std::cout << std::endl;

	}

	//Afficher Ship
	std::cout << "/////////////////////// Vaiseaux ///////////////////////" << endl;

	for (Ship* Var : shipslist) {

		std::cout << std::endl;

		std::cout << "Nom: " << Var->type << std::endl;
		std::cout << "Capacité Carburant: " << Var->fuel << std::endl;

		std::cout << std::endl;
		std::cout << "-----------" << std::endl;
		std::cout << std::endl;
	}

	// Afficher Conflits
	std::cout << "/////////////////////// Vaiseaux ///////////////////////" << endl;
	std::cout << std::endl;

	for (Conflit War : conflitList) {
		std::cout << "Conflit: " << War.NationA << " VS " << War.NationB << std::endl;
	}

	std::cout << std::endl;
	std::cout << "-----------" << std::endl;
	std::cout << std::endl;

}

//constructeur
Game::Game()
{
	shipslist = vector<Ship*>();
	planetList = vector<Planet*>();


	//ajouter les filename en constant
	//TransactionFileReader("fileNAME");
}