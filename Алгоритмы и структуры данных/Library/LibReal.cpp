#include "stdafx.h"
#include "Lib.h"


Lib :: ~Lib()
{
	author.clear();
}

void Lib :: AddAuthor(string name)
{
	map <string, int> book;
	author.insert( pair<string, map<string, int>> (name, book) );
}

void Lib :: DeleteAuthor(string author_name)
{
	auto it_author = author.find(author_name);
	if (author.erase(it_author) == author.end())
		throw ReturnStatus::NO_SUCH_AUTHOR;
}

void Lib :: AddBook(string book_name, string author_name, int year)
{
	auto it_author = author.find(author_name);
	if (it_author == author.end())
	{
		AddAuthor(author_name);
	}
	it_author->second.insert(pair<string, int> (book_name, year));
}

void Lib :: DeleteBook(string book_name, string author_name)
{
	auto it_author = author.find(author_name);
	auto it_book = it_author->second.find(book_name);
	if (it_author->second.erase(it_book) == it_author->second.end())
		throw ReturnStatus::NO_SUCH_BOOK;
}

void Lib :: BooksByAuthor(string author_name)
{
	cout << "Books written by " << author_name << ":" << endl;
	auto it_author = author.find(author_name);
	if (it_author == author.end())
	{
		throw ReturnStatus::NO_SUCH_AUTHOR;
	}
	auto it_book = it_author->second.begin();
	for (it_book; it_book != it_author->second.end(); it_book++)
	{
		cout << it_book->first << ", " << it_book->second << endl;
	}
}

void Lib :: BooksByName(string book_name)
{
	bool search_res = false;
	auto it_author = author.begin();
	auto it_book = author.begin()->second.begin();
	cout << "Books named " << book_name << ":" << endl;
	for (it_author; it_author != author.end(); it_author++)
	{
		it_book = it_author->second.find(book_name);
		if (it_book != it_author->second.end())
		{
			cout << it_book->first << ", Author: " << it_author->first << endl;
			search_res = true;
		}
	}
	if (!search_res)
	{
		cout << "No such books" << endl;;
	}
}

void Lib :: BooksByYear(int year)
{
	bool search_res = false;
	auto it_author = author.begin();
	auto it_book = author.begin()->second.begin();
	cout << "Books of " << year << " year:" << endl;
	for (it_author; it_author != author.end(); it_author++)
	{
		for (it_book; it_book != author.begin()->second.end(); it_book++)
		{
			if (it_book->second == year)
			{
				cout << "Book: " << it_book->first << ", author: " << it_author->first << endl;
				search_res = true;
			}
		}
	}
	if (!search_res)
	{
		cout << "No such books" << endl;;
	}
}