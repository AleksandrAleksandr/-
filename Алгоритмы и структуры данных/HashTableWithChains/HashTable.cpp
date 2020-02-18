#include "HashTable.h"

HashTable::HashTable(int table_size, string file_name)
{
	this->table_size = table_size;
	this->file_name = file_name;
	table.resize(table_size);
}

HashTable::~HashTable()
{
	table.clear();
}

int HashTable::GetHash(string str)
{
	const int p = 31;
	long long hash = 0, p_pow = 1;
	for (size_t i = 0; i<str.length(); ++i)
	{
		hash += (str[i] - 'a' + 1) * p_pow;
		p_pow *= p;
	}
	int a = hash % table_size;
	return abs(hash % table_size);
}
/*int HashTable::GetHash(string str)
{
	return str.length();
}*/


int HashTable::Hash()
{
	ifstream file(file_name);
	if (!file.is_open())
	{
		cout << "Open Error!\n" << endl;
	}
	else
	{
		int coliz = 0;
		string str;
		while (getline(file, str))
		{
			auto a = table[GetHash(str)].begin();
			if (!table[GetHash(str)].empty())
				coliz++;
			table[GetHash(str)].push_front(str);
		}
		cout << "Number of collisions: " << coliz << endl;
		return coliz;
	}
	return -1;
}

void HashTable::Find(string str)
{
	unsigned int start_time = clock();
	int HashValue = GetHash(str);
	if (table[HashValue].empty())
	{
		cout << "No such word";
	}
	else
	{
		for (auto it = table[HashValue].begin(); it != table[HashValue].end(); it++)
		{
			{
				unsigned int end_time = clock();
				cout << "The word was found, time: " << end_time - start_time;
				return;
			}
		}
		cout << "No such word";
	}
}