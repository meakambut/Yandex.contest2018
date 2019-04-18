#include "Coworkers.h"



void Coworkers::addRelation(pair<int, int> edge)
{
	int vertex1 = edge.first, vertex2 = edge.second;
	map <int, set<int>>::iterator p;
	p = this->graph.find(vertex1);
	p->second.insert(vertex2);
	p = this->graph.find(vertex2);
	p->second.insert(vertex1);
}

bool Coworkers::divideIntoTwoTeams()
{
	int man1 = 1, man2;
	map <int, set<int>>::iterator p;
	p = graph.find(man1);

	//looking for a non-friend of man1;
	for (int i = 2; i <= (int) this->graph.size(); i++)
		if (p->second.find(i) == p->second.end())
		{
			man2 = i;
			break;
		}
	this->team1.insert(man1);
	this->team2.insert(man2);

	for(int i = 2; i <= (int) this->graph.size(); i++)
		if (i != man2)
		{
			p = graph.find(i);
			for (int x1 : this->team1)
			{
				if (p->second.find(x1) == p->second.end())
				{
					for (int x2 : this->team2)
						if (p->second.find(x2) == p->second.end())
							return false;
					this->team2.insert(i);
				}
				break;
			}
			this->team1.insert(i);
		}

	return true;
}

void Coworkers::showTwoTeams()
{
	cout << team1.size() << endl;
	for (int x : team1)
		cout << x << " ";
	cout << endl;
	for (int x : team2)
		cout << x << " ";
	cout << endl;
}

Coworkers::Coworkers(int people)
{
	set<int> voidset;
	for (int i = 1; i <= people; i++)
		this->graph.insert(make_pair(i, voidset));
}


Coworkers::~Coworkers()
{
}
