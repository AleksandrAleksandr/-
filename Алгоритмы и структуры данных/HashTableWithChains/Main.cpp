#include "HashTable.h"


void main()
{
	HashTable table(1000000, "words.txt");
	table.Hash();
	table.Find("brows");
	cout << endl;
	system("PAUSE");
}