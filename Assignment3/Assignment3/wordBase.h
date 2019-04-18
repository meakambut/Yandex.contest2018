#include <set>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#pragma once
using namespace std;
class wordBase
{
private:
	set<string> words;
public:
	int addWord(string word);
	wordBase();
	~wordBase();
};

