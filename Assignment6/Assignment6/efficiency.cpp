#include "interns.h"

int main(int argc, char *argv[])
{
	ifstream in(argv[1]);
	if (!in)
	{
		cout << "Cannot open file\n";
		return 1;
	}

	int numOfInterns;
	in >> numOfInterns;
	interns team(numOfInterns);
	cout << "new team created\n";
	for (int i = 0; i < numOfInterns; i++)
	{
		int di;
		in >> di;
		team.addSkill(i + 1, 1, di);
	}
	
	for (int i = 0; i < numOfInterns; i++)
	{
		int di;
		in >> di;
		team.addSkill(i + 1, 2, di);
	}
	cout << "all initial skilles added\n";
	int numOfSertificates;
	in >> numOfSertificates;
	cout << "initial skills: \n";
	team.showSkills();
	cout << "initial max efficiency: " << team.maxEfficiency() << endl;
	cout << "num of new certifictaes: " << numOfSertificates << endl;
	for (int i = 0; i < numOfSertificates; i++)
	{
		int numi, typei, di;
		in >> numi;
		in >> typei;
		in >> di;
		team.addSkill(numi, typei, di);
		cout << i + 1 << " new certificate added\n";
		cout << "current skills: \n";
		team.showSkills();
		cout << "current max efficiency: ";
		cout << team.maxEfficiency() << endl;
	}
	in.close();

	char c;
	cin >> c;
	return 0;
}