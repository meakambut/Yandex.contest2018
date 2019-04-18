#include <iostream>
#include <map>
#include <set>
using namespace std;
#pragma once
class Coworkers
{
private:
	map <int, set<int>> graph;
	set<int> team1, team2;

public:
	void addRelation(pair<int, int> edge);
	bool divideIntoTwoTeams();
	void showTwoTeams();
	Coworkers(int people);
	~Coworkers();
};

