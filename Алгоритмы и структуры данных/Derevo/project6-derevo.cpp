// project6-derevo.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "List.h"
#include "conio.h"
#include "iostream"
#include "string"


	List lst;
	Node* root = NULL;

void ReadFromFileAndCreateTree()
{
	FILE *file = NULL;
	char name[] = "data.txt";
	char buf[20];
	std::string s="";

	fopen_s(&file,name,"r");

	if (file != NULL) 
	{
		while (1)
		{
		fgets(buf,sizeof(buf),file);
		int i=0;
		
		while (buf[i] != ' ')
		{
			s+=buf[i];
			i++;
		}
		int IndusIndex = atoi(s.c_str());
		i++;
		s="";

		while (buf[i] != ' ')
		{
			s+=buf[i];
			i++;
		}
		std::string IndusName = s;
		i++;
		s="";

		s=buf[i];
		bool IndusBool = atoi(s.c_str());
		s="";
		if (feof(file) != 0) break;
		lst.Push(&root, IndusIndex, IndusName.c_str(), IndusBool);
		}
	}
	else printf("not open");
}

int FindFromFile(int id)
{
	FILE *file;
	char name[] = "tree.txt";
	fopen_s(&file,name,"r");
	lst.FindFromFileById(file, id);
	return 0;
}

int main()
{
	//ReadFromFileAndCreateTree();
	//lst.SaveTree(&root);
	FindFromFile(17);
	
    system("pause");
	return 0;
}

