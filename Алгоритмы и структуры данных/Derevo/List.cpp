#include "stdafx.h"
#include "cstdlib"
#include "List.h"
#include "string"
#include "iostream"
#include "queue"
using namespace std;

List::List()
{
	siz=0;
	count=0;
	num = 2;
	/*Node* root_tree = (Node*)malloc(sizeof(Node));
	root_tree = NULL;
	Node** root = &root_tree;*/
}

void List::Push(Node** root,int value, const char* name, bool go)
{	
	if (*root == NULL)
	{
		*root = (Node*)malloc(sizeof(Node));
		(*root)->left = NULL;
		(*root)->right = NULL;
		(*root)->value = value;
		(*root)->string_number = siz++;
		(*root)->name = name;
		for (int i = 0; i < strlen(name); i++)
			((*root)->indus[i]) = *(name+i);
		for (int i = strlen(name); i < 10; i++)
			((*root)->indus[i]) = 32;
		//(*root)->indus += *(name);
		//std::cout << ((*root)->indus)<<std::endl;
		(*root)->go = go;
	}
	else
	{
		if (value < (*root)->value)
		{
			Push(&(*root)->left,value, name, go);
		}
		else if (value > (*root)->value) 
		{
			Push(&(*root)->right,value, name, go);
		}
	}
}

int List::FindById(Node** root,int id)
{
	if (id > (*root)->value)
	{  
		count++;
		FindById(&(*root)->right,id);
	}
	else if (id < (*root)->value)
	{
		count++;
		FindById(&(*root)->left,id);
	}
	else 
	{
		for (int i = 0; i < 10; i++)
		std::cout << ((*root)->indus[i]);
				
		if ((*root)->go == 1) printf(" good boy\n");
		if ((*root)->go == 0) printf(" bandit\n");
		printf("found for  %d iterations\n",count);
	}
	return 0;
}

int List::SaveTree(Node** root) 
{ 
if (*root == NULL) 
{ 
return -1; 
} 
queue<Node *> q; // Создаем очередь 
q.push(*root); // Вставляем корень в очередь 
FILE *file = NULL;
	char name[] = "tree.txt";
	fopen_s(&file,name,"w");

while (!q.empty()) // пока очередь не пуста 
{ 
Node* temp = q.front(); // Берем первый элемент в очереди 
q.pop(); // Удаляем первый элемент в очереди 
if ((temp->left != NULL) && (temp->right != NULL)) 
{ 
//fprintf(file, "%d %s %d %d %d\n", temp->value, temp->indus, temp->go, num++, num); // Печатаем значение первого элемента в очереди 
fprintf(file, "%d ", temp->value);
for (int k = 0; temp->indus[k] != 32; k++) fprintf(file, "%c", temp->indus[k]);
fprintf(file, " %d %d %d\n", temp->go, num++, num); 
num++; 
} 
else if (temp->left != NULL) {
//fprintf(file, "%d %s %d %d %d\n", temp->value, temp->indus, temp->go, num++, 0); 
fprintf(file, "%d ", temp->value);
for (int k = 0; temp->indus[k] != 32; k++) fprintf(file, "%c", temp->indus[k]);
fprintf(file, " %d %d %d\n", temp->go, num++, 0); 
}
else if(temp->right != NULL) {
//fprintf(file, "%d %s %d %d %d\n", temp->value, temp->indus, temp->go, 0, num++); 
fprintf(file, "%d ", temp->value);
for (int k = 0; temp->indus[k] != 32; k++) fprintf(file, "%c", temp->indus[k]);
fprintf(file, " %d %d %d\n", temp->go, 0, num++); 
}
else{ 
//fprintf(file, "%d %s %d %d %d\n", temp->value, temp->indus, temp->go, 0, 0);
fprintf(file, "%d ", temp->value);
for (int k = 0; temp->indus[k] != 32; k++) fprintf(file, "%c", temp->indus[k]);
fprintf(file, " %d %d %d\n", temp->go, 0, 0); 
}

 if (temp->left != NULL)
	q.push(temp->left);
 if (temp->right != NULL)
	q.push(temp->right); 
} 
fclose(file);
}

int List::FindFromFileById(FILE* file, int id)
{
char* buf = (char*)malloc(20*sizeof(char));
std::string s="";
int child;
int oldChild = 1;
int IndusIndex;
int i = 0;
count = 0;
fgets(buf,20,file);

	while (1){
		s="";i = 0;
		while (buf[i] != ' ')
		{
			s+=buf[i];
			i++;
		}
		IndusIndex = atoi(s.c_str());

		if (id < IndusIndex)
		{
			i++; count++;
			while (buf[i] != ' '){
				i++;
			}
			i++;i++;i++;s="";
			while (buf[i] != ' '){
				s+=buf[i];
				i++;
			}
			child = atoi(s.c_str());
			//std::cout<< child <<std::endl;
			for (int p = oldChild; p < child; p++)
			{
				//for(int l = 0; l < sizeof(buf); l++) buf[l]=0;
				free(buf);
				char* buf = (char*)malloc(20*sizeof(char));
				fgets(buf,20,file);
			}
			oldChild = child;
		}
		else if (id > IndusIndex)
		{
			i++; count++;
			while (buf[i] != ' '){
				i++;
			}
			i++;i++;i++;s="";
			while (buf[i] != ' '){
				i++;
			}
			i++;
			while (buf[i] != '\n'){
				s+=buf[i];
				i++;
			}
			child = atoi(s.c_str());
			//std::cout<< child <<std::endl;
			for (int p = oldChild; p < child; p++)
			{
				//for(int l = 0; l < sizeof(buf); l++) buf[l]=0;
				free(buf);
				char* buf = (char*)malloc(20*sizeof(char));
				fgets(buf,20,file);
			}
			oldChild = child;
		}
		else 
		{
			i++;s="";
			while (buf[i] != ' '){
				s+=buf[i];
				i++;
			}
			std::string IndusName = s;
			i++;
			s="";

			s = buf[i];
			i++;
			bool IndusBool = atoi(s.c_str());
			if (IndusBool == 1) std::cout<< IndusName << ' ' << "is a god boy" <<std::endl;
			else std::cout<< IndusName << ' ' << "is bandit" <<std::endl;
			std::cout<< "found for " << count << " iter" <<std::endl;
			break;
		}

	}
return 1;
}


