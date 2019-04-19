#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class interns
{
private:
	vector<int> skills;
	int n;
public:
	void addSkill(int numi, int typei, int di);
	int indexMaxElem(vector<int> array);
	void showSkills();
	int maxEfficiency();
	interns(int n);
	~interns();
};

