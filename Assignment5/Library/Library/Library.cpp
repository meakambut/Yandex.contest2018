#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cout << "no input data\n";
		return 0;
	}

	ifstream in(argv[1]);
	if (!in)
	{
		cout << "Cannot open file.\n";
		return 0;
	}

	int takeOut;
	int books;
	int day;
	in >> takeOut;
	in >> books;
	in >> day;
	int count = 1;
	while (books >= 0)
	{
		if (day == 6 || day == 7)
			books -= count;
		else
			books = books + takeOut - count;
		count++;
		day = (day + 1) % 7 + 1;
	}
	in.close();
	int res = 0;
	if (count != 1)
		res = count - 2;
	cout << res;
	char ch;
	cin >> ch;
	return 1;
}