#include "Servers.h"
#include <iostream>
using namespace std;


Servers::Servers(int num, int *servers, int *errors)
{
	this->numOfServers = num;
	if (num == 0)
	{
		cout << "no servers to analyze\n";
		return;
	}
	this->serverProbability = new int[num];
	this->errorProbability = new int[num];
	int sum = 0;
	for (int i = 0; i < num; i++)
	{
		this->serverProbability[i] = servers[i];
		this->errorProbability[i] = errors[i];
		sum += serverProbability[i] * errorProbability[i];
	}
	this->sum = sum;
}

double Servers::errorOnServerProbability(int num)
{
	return this->serverProbability[num - 1] * this->errorProbability[num - 1] / (double) this->sum;
}

Servers::~Servers()
{
	delete[] serverProbability;
	delete[] errorProbability;
}
