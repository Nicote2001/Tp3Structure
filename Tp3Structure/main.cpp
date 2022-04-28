#include "Game.h"
int main()
{
	Game run;
	run.PlanetFileReader("Planetes_20.txt");

	run.graph.read();

	
	system("PAUSE");
}