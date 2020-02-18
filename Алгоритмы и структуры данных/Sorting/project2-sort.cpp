// project2-sort.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "conio.h"
#include "time.h"

#define N 100000

void perestanovki(int* a)
{
	int id,max;
for(int k=0;k<N-1;k++)    
{
	max=a[0];id=0;

	for (int i=1;i<N-k;i++)
	{
		if (a[i]>max) { max=a[i];id=i;}
	};

	a[id]=a[N-k-1];
	a[N-k-1]=max;
};
}

void podschet(int* a)
{
	int max = 0;                      //сортировка подсчетом
for (int i = 0; i<N; i++)
{
if (a[i] > max) max=a[i];
}

int* count = (int*)malloc((max+1)*sizeof(int));//массив для подсчета частот
for (int i = 0; i<(max+1); i++)
	count[i]=0;

for (int i = 0; i<N; i++)
{
	count[a[i]]++;
};

int i = 0;
for (int j = 0; j<(max+1); j++)
{
	for (int k = 0; k<count[j]; k++)
	{
		a[i]=j;
		i++;
	};
};
free(count);
}

void printSortMas(int* a)
{
	printf("\n");
for (int i=0;i<N;i++)        
{
	//std::cout << a[i] <<" ";
	printf("%d ",a[i]);
};
}

void main()
{
clock_t startTime = clock();//std::cout << startTime << std::endl;
int* a=(int*)malloc(N*sizeof(int));
for (int i = 0; i < N; i++)
	a[i] = rand();

//perestanovki(a);
podschet(a);


clock_t endTime = clock();//std::cout << endTime << std::endl;
std::cout << "runtime " << (endTime - startTime)/1000 <<std::endl;

//printSortMas(a);
free(a);
_getch();
}

