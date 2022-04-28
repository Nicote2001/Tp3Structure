#pragma once
struct Info {
	bool trajet;
	float distance;
	float cout;
};
class Graph
{
public:
	Info tab[100][100];

	void add(int idP1, int idP2, bool trajet, float distance, float cout);
	void read();
};

