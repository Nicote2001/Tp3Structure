#pragma once
using namespace std;
#include <vector>

struct Info {
	bool trajet;
	float distance;
	float cout;
};

class Graph
{
public:
	int rows;
	int cols;
	bool isCrossable;
	Info tab[100][100];

	void add(int idP1, int idP2, bool trajet, float distance, float cout);
	void read();

	void dfs(int start, vector<bool>& visited, int fuel, int destination);
};

