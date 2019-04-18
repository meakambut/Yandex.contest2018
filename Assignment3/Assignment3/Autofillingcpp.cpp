#include "wordBase.h"

int main(int argc, char *argv[])
{
	wordBase text;
	cout << text.addWord("an") << endl;
	cout << text.addWord("apple") << endl;
	//cout << text.addWord("an") << endl;
	cout << text.addWord("a") << endl;
	cout << text.addWord("big") << endl;
	cout << text.addWord("apple") << endl << endl;
	cout << text.addWord("hello") << endl;
	cout << text.addWord("world") << endl;
	cout << text.addWord("hello") << endl;
	cout << text.addWord("he") << endl;
	cout << text.addWord("he") << endl;
	char c;
	cin >> c;
	return 0;
}