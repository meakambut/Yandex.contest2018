#include "interns.h"



void interns::addSkill(int numi, int typei, int di)
{
	this->skills[2 * (numi - 1) + typei - 1] += di;
}

int interns::indexMaxElem(vector<int> array)
{
	int maxindex = 0, maxelem = array[0];
	for (int i = 1; i < array.size(); i++)
	{
		if (maxelem < array[i])
		{
			maxelem = array[i];
			maxindex = i;
		}
	}
	return maxindex;
}

void interns::showSkills()
{
	for (int i = 0; i < this->n; i += 2)
	{
		cout << this->skills[i] << " ";
	}
	cout << endl;
	for (int i = 1; i < this->n; i += 2)
	{
		cout << this->skills[i] << " ";
	}
	cout << endl;
}

int interns::maxEfficiency()
{
	vector<int> aux(this->skills), di;
	for (int i = 0; i < this->n; i += 2)
		di.push_back(abs(aux[i] - aux[i+1]));
	int sum = 0, j, team1 = 0, team2 = 0;
	for (int i = 0; i < this->n/2; i++)
	{
		j = indexMaxElem(di);
		di[j] = 0;
		if (team1 == this->n / 4) //if management team is full, add all remaining skills of developers
		{
			for (int k = 0; k < this->n; k += 2)
				sum += aux[k + 1];
			return sum;
		}
		else
			if (team2 == this->n / 4) //if developement team is full, add all remaining team of managers
			{
				for (int k = 0; k < this->n; k += 2)
					sum += aux[k];
				return sum;
			}
			else //assign intern to a team, nullify both his skills in order not to consider them in the future
			{
				if (aux[2 * j] > aux[2 * j + 1])
				{
					sum += aux[2 * j];
					team1++;
				}
				else
				{
					sum += aux[2 * j + 1];
					team2++;
				}
				aux[2 * j] = 0;
				aux[2 * j + 1] = 0;
			}
	}
	return sum;
}

interns::interns(int n)
{
	this->n = 2*n;
	for (int i = 0; i < n; i++)
	{
		this->skills.push_back(0);
		this->skills.push_back(0);
	}
}


interns::~interns()
{
}
