
#ifndef LIB_H
#define LIB_H
#include <iostream>
#include <string>
#include <list>
#include <map>            
#include <vector>
#include <iterator>
using namespace std;


enum class ReturnStatus
{
	OK = 0,
	NO_SUCH_AUTHOR = 1,
	NO_SUCH_BOOK = 2
};


class Lib
{
public:
	~Lib();
	map <string, map<string, int>> author;
	 
	void AddAuthor(string book_name);
	void DeleteAuthor(string autrhor_name);
	void AddBook(string book_name, string author_name, int year);
	void DeleteBook(string book_name, string author_name);
	void BooksByAuthor(string author_name);
	void BooksByName(string book_name);
	void BooksByYear(int year);
};


#endif