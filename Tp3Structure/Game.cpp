#include "Game.h"

void Game::PlanetFileReader(std::string fileName)
{
	ifstream file;
	std::string tmpName, tmpNation;
	float tmpFuelPrice,tmpPosX,tmpPosY;
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

			planetList.push_back(new Planet(tmpName,tmpPosX,tmpPosY,tmpPopulation,tmpNation,tmpFuelPrice));
		}

		file.close();
	}
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
	std::string TmpString, TmpString2, TmpString3 ;
	int TmpInt1, TmpInt2, TmpInt3;

	FicTransaction.open(fileName);

	if (!FicTransaction.fail()) {

		while (!FicTransaction.eof()) {

			FicTransaction >> Entree;

			switch (Entree) {
			case '#V': // Intuile puisque je fais pas le bonus
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
				//faire le cas des conflit si besoin
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

//constructeur
Game::Game()
{
	shipslist = vector<Ship*>();
	planetList = vector<Planet*>();


	//ajouter les filename en constant
	TransactionFileReader("fileNAME");
}
