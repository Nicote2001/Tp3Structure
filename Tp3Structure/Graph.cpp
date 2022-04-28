#include "Graph.h"
#include <iostream>


void Graph::add(int idP1, int idP2, bool trajet, float distance, float cout) {

	Info tmp;
	tmp.cout = cout;
	tmp.distance = distance;
	tmp.trajet = trajet;

	tab[idP1][idP2] = tmp;


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
