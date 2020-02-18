#include <iostream>
#include "stdafx.h"
#include "cstdlib"
#include "list.h"

List::List()
{
	head=(Node*)malloc(sizeof(Node));
	head->next=NULL;
	tail=(Node*)malloc(sizeof(Node));
	tail->prev=NULL;
	sizel=0;
}

void List::AddToTail(int value)
{
	Node* tmp=(Node*)malloc(sizeof(Node));
	if (sizel==0){
		head->next=tmp;
		tail->prev=tmp;
		tmp->prev=NULL;
		tmp->next=NULL;
	}
	else {
		tmp->prev=tail->prev;
		tail->prev->next=tmp;
		tail->prev=tmp;
		tmp->next=NULL;
	}
	tmp->value=value;
	sizel++;
}

void List::AddToHead(int value)
{
	Node* tmp=(Node*)malloc(sizeof(Node));
	if (sizel==0){
		head->next=tmp;
		tail->prev=tmp;
		tmp->next = NULL;
		tmp->prev = NULL;
	}
	else {
		tmp->next=head->next;
		head->next->prev=tmp;
		head->next=tmp;
	}
	tmp->value=value;
	sizel++;
}

void List::Print()
{
	if (sizel==0)
		printf("empty");
	else{
		Node* tmp;
		tmp=head->next;
		while (tmp!=NULL)
		{
			printf("%d ",tmp->value);
			tmp=tmp->next;
		}
	}
}

Node* List::GetByIndex(int index)
{
	if (index>sizel||index<1)
		return NULL;
	else{
		Node* tmp = head->next;
		for(int i = 0; i < index - 1; i++){
			tmp = tmp->next;
		}
		return tmp;
	}
	
}


void List::DelByIndex(int index)
{
	if (index > sizel || index < 1)
		printf("There is no element with this index");
	else{
		Node* element = GetByIndex(index);
		if (index == 1){
			element->next->prev = NULL;
			head->next = element->next;
		}
		else if (index == sizel){
			element->prev->next = NULL;
			tail->prev = element->prev;
		}
		else{
			element->prev->next = element->next;//указатель next предыдущего элемента должен указывать на элемент, следуемый за удаляемым
			element->next->prev = element->prev;//указатель prev следующего(за удаляемым)  элемента должен указывать на предыдущий элемент
		}
		delete element;
		sizel--;
	}
}

void List::AddToSomePlace(int index,int value)
{
	if (index > sizel || index < 1)
	{
		printf("abroad of the list");
	}
	else if (index == 1)
		AddToHead(value);
	else if (index == sizel)
		AddToTail(value);
	else
	{
		Node* tmp = (Node*)malloc(sizeof(Node));
		Node* prev = GetByIndex(index-1);
		Node* next = GetByIndex(index);
		prev->next = tmp;
		next->prev = tmp;
		tmp->prev = prev;
		tmp->next = next;

		tmp->value = value;
		sizel++;
	}
}


