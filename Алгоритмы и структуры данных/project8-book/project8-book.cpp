// project8-book.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "Library.h"
#include "iostream"
#include "string"
#include "exception"


int main()
{
	Library lib;
	lib.AddBook("Harry Potter", "Rouling", 1999);
	lib.AddBook("Philosophical stone", "Rouling", 2000);
	lib.AddBook("Secret Room", "Tolkien", 2000);

	

	try
	{
		Book book1 = lib.GetBook("Philosophical stone");
		std::cout<<"lib.GetBook(\"Philosophical stone\"):"<<std::endl;
		std::cout<< book1.author <<" "<< book1.year<<std::endl<<std::endl;	
	}
	catch(...)
	{
		std::cout<<"lib.GetBook(\"Philosophical stone\") - there is no this book"<<std::endl<<std::endl;
	}

	try
	{
		std::vector<Book> yearBooks = lib.BooksByYear(2000);
		std::cout<<"lib.BooksByYear(2000):"<<std::endl;
		for (auto i = yearBooks.begin(); i !=  yearBooks.end(); i++)
			std::cout<< i->name <<" "<<i->author<<" "<<i->year<<std::endl;
		std::cout<<std::endl;
	}
	catch(...)
	{
		std::cout<<"lib.BooksByYear(2000) - there is no books in this year"<<std::endl;
	}

	try
	{
		std::vector<Book> authorBooks = lib.BooksByAuthor("Rouling");
		std::cout<<"lib.BooksByAuthor(\"Rouling\"):"<<std::endl;
		for (auto i = authorBooks.begin(); i !=  authorBooks.end(); i++)
			std::cout<< i->name <<" "<<i->year<<std::endl;
		std::cout<<std::endl;
	}
	catch(...)
	{
		std::cout<<"lib.BooksByAuthor(\"Rouling\") - this autor doesn't have books"<<std::endl;
	}

	try
	{
		std::vector<std::string> authors = lib.PrintAuthors();
		std::cout<<"lib.PrintAuthors():"<<std::endl;
		for (auto i = authors.begin(); i !=  authors.end(); i++)
			std::cout<< *i <<std::endl;
		std::cout<<std::endl;
	}
	catch(...)
	{
		std::cout<<"lib.PrintAuthors() - there is no authors in library"<<std::endl;
	}

	try
	{
		lib.RemoveBook("Secret Room");
		std::cout<<"lib.RemoveBook(\"Secret Room\"): successful"<<std::endl<<std::endl;
	}
	catch(...)
	{
		std::cout<<"lib.RemoveBook(\"Secret Room\") - there is no this book"<<std::endl;
	}

	system("pause");
}

