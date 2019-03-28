#pragma once
class Servers
{
private:
	int numOfServers;
	int *serverProbability;
	int *errorProbability;
	int sum;

public:
	Servers(int num, int *servers, int *errors);
	double errorOnServerProbability(int num);
	~Servers();
};

