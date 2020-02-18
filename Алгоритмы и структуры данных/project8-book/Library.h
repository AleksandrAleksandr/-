#ifndef BOOK
#define BOOK
#include "vector"

class Book
{
public:
	Book(std::string name_, std::string author_, int year_);
	std::string name;
	std::string author;
	int year;
};

class Library
{
	
public:
	Library();
	std::vector<Book> books;
	void AddBook(std::string, std::string, int);
	Book GetBook(std::string);
	std::vector<Book> BooksByYear(int);
	std::vector<Book> BooksByAuthor(std::string);
	std::vector<std::string> PrintAuthors();
	void RemoveBook(std::string);
	void RemoveAuthor(std::string author);
};
#endif
