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
		cout << "Open Error!\n";
	}
	else
	{
		int coliz = 0;
		string str;
		while (getline(file, str))
		{
			int HashValue = GetHash(str);
			if (table[HashValue] == "")
			{
				table[HashValue] = str;
			}
			else
			{
				bool check = false;
				for (int i = HashValue + 1; i < table_size; i++)
				{
					if (table[i] == "")
					{
						table[i] = str;
						check = true;
						break;
					}
				}
				coliz++;
				if (!check)
				{
					table.push_back(str);
					table_size++;
				}
			}

		}
		cout << "Number of collisions: " << coliz << endl;
		return coliz;
	}
	return -1;
}

void HashTable::Find(string str)
{
	int HashValue = GetHash(str);
	int count = 1;
	unsigned int start_time = clock();
	if (table[HashValue] == "")
	{
		cout << "No such word" << endl;
		return;
	}
	else
	{
		for (int i = HashValue; i < table_size; i++)
		{
			if (table[i] == str)
			{
				unsigned int end_time = clock();
				cout << "The word was found, time: " << end_time - start_time << endl;
				return;
			}
			if (table[i] == "")
			{
				cout << "No such word" << endl;
				return;
			}
		}
		cout << "No such word" << endl;
	}
}