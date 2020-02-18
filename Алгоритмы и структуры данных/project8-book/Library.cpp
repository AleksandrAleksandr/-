#include "stdafx.h"
#include "Library.h"
#include "string"
#include "algorithm"

Book::Book(std::string name_, std::string author_, int year_)
{
	name = name_;
	author = author_;
	year = year_;
}

Library::Library(void)
{
}

void Library::AddBook(std::string name, std::string author, int year)
{
	Book book(name, author, year);
	books.push_back(book);
}

Book Library::GetBook(std::string name)
{
	auto i = books.begin();
	for (i; i != books.end(); i++)
	{
		if (name == i->name) 
			return *i;
	}

	if (i == books.end())
		throw 1;
}

std::vector<Book> Library::BooksByYear(int year)
{
	std::vector<Book> yearBook;
	for (auto i = books.begin(); i != books.end(); i++)
	{
		if (year == i->year) 
		{
			yearBook.push_back(*i); 
		}
	}
	
	if (yearBook.size() == 0)
		throw 1;
	return yearBook;
}

std::vector<Book> Library::BooksByAuthor(std::string author)
{
	std::vector<Book> authorBooks;
	for (auto i = books.begin(); i != books.end(); i++)
	{
		if (author == i->author) 
		{
			authorBooks.push_back(*i); 
		}
	}
	
	if (authorBooks.size() == 0)
		throw 1;
	return authorBooks;
}

std::vector<std::string> Library::PrintAuthors()
{
	std::vector<std::string> authors;
	for (auto i = books.begin(); i != books.end(); i++)
	{
		auto check = std::find(authors.begin(), authors.end(), i->author);
		if (check == authors.end())
			authors.push_back(i->author);
	}
	
	if (authors.size() == 0)
		throw 1;
	return authors;
}

void Library::RemoveBook(std::string name)
{
	auto pos = std::find_if(books.begin(), books.end(), [&name](Book &arg) {return arg.name == name; });
	if (pos != books.end())
		books.erase(pos);
	else
		throw 1;
}

void Library::RemoveAuthor(std::string author)
{
	//auto pos = std::find_if(books.begin(), books.end(), [&author](Book &arg) {return arg.author == author; });
	std::vector<std::vector<Book>::iterator> ptrs;
	auto pos = books.begin();
    for (; pos != books.end(); pos++)
		if (pos->author == author)
        {
            ptrs.push_back(pos);
        }
    for (auto ptr : ptrs)
        books.erase(ptr);
}