#include "HashTable.h"


void main()
{
	HashTable table(1000000, "words.txt");
	table.Hash();
	table.Find("2nd");
	cout << endl;
	system("PAUSE");
}