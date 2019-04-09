#include "Appointments.h"

string Appointments::setAppointment(int day, int hour, int min, int duration, vector<string> participants)
{
	set<pair<int, int>> timeList;
	map<string, set<pair<int, int>>>::iterator p;
	int time = (day - 1) * 24 + hour * 60 + min;
	pair<int, int> appointmentTime = make_pair(time, time + duration);
	set<pair<int, int>>::iterator pset, pnext, pprev;
	string namesFailed = "";
	for (int j = 0; j < participants.size(); j++)
	{
		
		string name;
		name = participants[j];
		p = this->appointmentList.find(name);

		if (p == this->appointmentList.end())
		{	
			timeList.insert(appointmentTime);
			this->appointmentList.insert(make_pair(name, timeList));
		}
		else
		{
			pnext = p->second.lower_bound(appointmentTime);
			pprev = pnext;
			pprev--;
			if (pnext != p->second.end())
			{
				if (p->second.size() > 1)
				{
					if (pnext->first >= appointmentTime.second && pprev->second <= appointmentTime.first)
						p->second.insert(appointmentTime);
					else
						namesFailed += p->first + " ";
				}
				else
				{
					if (pnext->first >= appointmentTime.second)
						p->second.insert(appointmentTime);
					
					else
						namesFailed += p->first + " ";
				}
			}
			else
			{
				if (p->second.size() >= 1)
				{
					pprev = p->second.end();
					pprev--;
					if (pprev->second <= appointmentTime.first)
						p->second.insert(appointmentTime);
					else
						namesFailed += p->first + " ";
				}
			}
		}
	}
	if (namesFailed != "")
		namesFailed.pop_back();
	return namesFailed;
}
string Appointments::print(int day, string name)
{
	map<string, set<pair<int, int>>>::iterator p;
	p = appointmentList.find(name);
	string res = "";
	for (pair<int, int> pset : p->second)
	{
		if (pset.first > 24 * 60 * (day - 1) && pset.second < 24 * 60 * day)
		{
			pair<int, int> appointmentTime;
			appointmentTime = make_pair(pset.first, pset.second);
			if (appointmentTime.first % (24 * 60) / 60 / 10 == 0)
				res += "0";
			res += to_string(appointmentTime.first % (24 * 60) / 60) + ":";
			if (appointmentTime.first % 60 / 10 == 0)
				res += "0";
			res += to_string(appointmentTime.first % 60) + " ";
			if ((appointmentTime.second - appointmentTime.first) / 10 == 0)
				res += "0";
			res += to_string(appointmentTime.second - appointmentTime.first) + " ";
			for (pair<string, set<pair<int, int>>> pmap : appointmentList)
				if (pmap.second.find(appointmentTime) != pmap.second.end())
					res += pmap.first + " ";
			res.pop_back();
			res += '\n';
		}
	}
	return res;
}

Appointments::Appointments()
{
}


Appointments::~Appointments()
{
}
