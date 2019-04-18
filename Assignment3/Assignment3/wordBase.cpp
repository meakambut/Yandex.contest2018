#include "wordBase.h"



int wordBase::addWord(string word)
{
	set<string>::iterator p;
	
	p = words.find(word);
	
	if ( p == words.end())
	{
		words.insert(word);
		return word.size();
	}
	
	int maxpresses = 0;
	int intersection = 0;

	string start = "", end = "";
	start += word[0];
	end += word[0] + 1;

	set<string>::iterator pstart, pend;
	pstart = words.lower_bound(start);
	pend = words.lower_bound(end);
	p = pstart;

	while (p != pend)
	{
		if (word != *p)
		{
			int length = min(word.size(), (*p).size());
			intersection = 0;
			for (int i = 0; i < length; i++)
				if ((*p)[i] == word[i])
					intersection++;
				else
					break;
			if (maxpresses < intersection + 1)
				maxpresses = intersection + 1;

		}
		else
			maxpresses = intersection + 1;
		p++;
	}

	return min(maxpresses, (int) word.size());
}

wordBase::wordBase()
{
}


wordBase::~wordBase()
{
}
