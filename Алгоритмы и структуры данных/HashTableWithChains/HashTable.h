#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <list>
#include <ctime>
using namespace std;

class HashTable
{
public:
	HashTable(int table_size, string file_name);
	~HashTable();
	vector<list<string>> table;
	int Hash();
	void Find(string str);
private:
	int GetHash(string str);
	int table_size;
	string file_name;

};

#endif
