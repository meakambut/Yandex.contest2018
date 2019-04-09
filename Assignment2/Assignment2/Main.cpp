#include <iostream>
#include <set>
#include <iterator>
#include <map>
#include <string>
#include <fstream>
#include <vector>
#include "Appointments.h"

using namespace std;

int main(int argc, char *argv[])
{
	map<string, set<pair<int, int>>> appointmentList;
	
	map<string, set<pair<int, int>>>::iterator p;
	set<pair<int, int>>::iterator pset, pnext, pprev;

	if (argc < 2)
	{
		cout << "There is no data to test\n";
		return 0;
	}

	ifstream in(argv[1]);
	if(!in)
	{
		cout << "Cannot open file\n";
		return 0;
	}

	int numOfRequests;
	in >> numOfRequests;
	Appointments timeTable;
	for (int i = 0; i < numOfRequests; i++)
	{
		string command;
		in >> command;
		
		if (command == "APPOINT")
		{
			int day, hour, min, duration;
			in >> day;
			in >> hour;
			char symb;
			in >> symb;
			in >> min;
			in >> duration;
			int numOfParticipants;
			in >> numOfParticipants;
			vector<string> participants;
			for (int j = 0; j < numOfParticipants; j++)
			{
				string name;
				in >> name;
				participants.push_back(name);
			}
			
			string res = timeTable.setAppointment(day, hour, min, duration, participants);
				if (res == "")
					cout << "OK\n";
				else
					cout << "FAIL\n" << res << endl;
		}
		else
			if (command == "PRINT")
			{
				int day;
				in >> day;
				string name;
				in >> name;
				cout << timeTable.print(day, name);
			}
	}

	in.close();
	char ch;
	cin >> ch;
	return 1;
}