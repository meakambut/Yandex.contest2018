#include <iostream>
#include <fstream>
#include "Servers.h"
using namespace std;
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		cout << "No input data\n";
		return 1;
	}

	ifstream in(argv[1]);
	if (!in)
	{
		cout << "Cannot open file.\n";
		return 1;
	}
	
	int num;
	int *servers = nullptr, *errors = nullptr;
	in >> num;
	if (num > 0)
	{
		servers = new int[num];
		errors = new int[num];
	}
	for (int i = 0; i < num; i++)
	{
		in >> servers[i];
		in >> errors[i];
	}
	Servers *serversCase = new Servers(num, servers, errors);
	cout.precision(10);
	for (int i = 1; i <= num; i++)
		cout << serversCase->errorOnServerProbability(i) << "\n";
	in.close();
	delete[] servers;
	delete[] errors;
	char ch;
	cin >> ch;
	return 0;
}