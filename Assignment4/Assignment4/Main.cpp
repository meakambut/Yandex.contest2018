#include "Coworkers.h"
#include <fstream>

int main(int argc, char *argv[])
{
	ifstream in(argv[1]);
	if (!in)
	{
		cout << "Cannot open file\n";
		return 1;
	}

	int vertexes, edges;
	in >> vertexes;
	in >> edges;

	Coworkers teambuilding(vertexes);
	for (int i = 0; i < edges; i++)
	{
		int vertex1, vertex2;
		in >> vertex1;
		in >> vertex2;
		teambuilding.addRelation(make_pair(vertex1, vertex2));
	}
	
	if (teambuilding.divideIntoTwoTeams())
		teambuilding.showTwoTeams();
	else
		cout << "-1" << endl;
	char c;
	cin >> c;
	return 0;
}