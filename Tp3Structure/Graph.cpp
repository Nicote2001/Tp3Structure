#include "Graph.h"
#include <iostream>


void Graph::add(int idP1, int idP2, bool trajet, float distance, float cout) 
{

	Info tmp;
	tmp.cout = cout;
	tmp.distance = distance;
	tmp.trajet = trajet;

	tab[idP1][idP2] = tmp;

	//calcul des size des row et col du tableau
	rows = sizeof tab / sizeof tab[0]; 

	cols = sizeof tab[0] / sizeof(int); 
}


void Graph::read()
{
	int i;
	int i2;
	
	for (i = 0; i < 20; i++) {
		for (i2 = 0; i2 < 20; i2++) {
			std::cout << tab[i][i2].cout << " " << tab[i][i2].distance << " " << tab[i][i2].trajet << std::endl;;
		}
	}

	/*
	for (Info var[100] : tab)
	{
		for (Info tmp : var)
		{
			std::cout << tmp.cout << " " << tmp.distance << " " << tmp.trajet << std::endl;
		}
	}
	*/
}

// function to perform DFS on the graph
void Graph::dfs(int start, vector<bool>& visited, int fuel, int destination)
{
	//a titre indicatif pour debug on out le chemin
	cout << start << " ";

	//si on atteint la destination lets put the crossable to true
	if (start == destination) 
	{
		isCrossable = true;
		cout << destination << endl;
	}

	//on visite la planete
    visited[start] = true;
 
	//on partcour toute les rows pour voir chaque planete
    for (int i = 0; i < rows; i++) {
		
		//si il y a un trajet entre la planete visite et la prochaine et quelle est pas visiter on rentre dans le if
        if (tab[start][i].trajet == 1 && (!visited[i])) 
		{
			//si la distance est correct par rapport au vaisseau on rentre
			if (tab[start][i].distance <= fuel) 
			{
				//recursivité pour contineuer le partcour en profondeur
				dfs(i, visited, fuel,destination);
			}
        }
    }

	//nb les var ROW et COL sont calculer a linit du tableau pour pouvoir les utiliser dans le projet
}
