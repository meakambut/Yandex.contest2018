#pragma once
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Appointments
{
private: 
	map<string, set<pair<int, int>>> appointmentList;
public:
	string setAppointment(int day, int hour, int min, int duration, vector<string> participants);
	string print(int day, string name);

public:
	Appointments();
	~Appointments();
};

