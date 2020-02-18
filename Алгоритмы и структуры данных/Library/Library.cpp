#include "stdafx.h"
#include "Lib.h"


void main()
{
	Lib Lib;
	Lib.AddAuthor("Dostoevsky");
	Lib.AddBook("1", "Dostoevsky", 1895);
	Lib.AddBook("2", "Dostoevsky", 1899);

	Lib.AddAuthor("Leskov");
	Lib.AddBook("1", "Leskov", 1895);

	try
	{
		Lib.DeleteAuthor("Dostoevsky");
	}
	catch(...)
	{
		cout << "No such author" << endl;
	}

	try
	{
		Lib.DeleteBook("1", "Leskov");
	}
	catch (...)
	{
		cout << "No such books" << endl;
	}


	Lib.BooksByName("5");
	Lib.BooksByYear(1895);
	system("PAUSE");
}