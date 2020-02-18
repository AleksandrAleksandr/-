// project4-list.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "conio.h"
#include "list.h"


int main()
{
	List lst;
	lst.AddToHead(3);
	lst.AddToHead(7);
	lst.AddToHead(15);
	lst.AddToTail(2);
	
	lst.AddToSomePlace(3,18);
	//lst.DelByIndex(3);
	//printf("%d \n",lst.GetByIndex(2)->value);
	lst.Print();

	_getch();
}

