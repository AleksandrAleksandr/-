// project7-merge_sort.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "cstdlib"

#define N 1000000

void merge(int* ar, unsigned int n)
{
	unsigned int step = 1;
	int * temp = (int*)malloc(n * sizeof(int));
	while (step < n)
	{
		int left = 0;
		int mid = left + step;
		int right = left + 2*step;
		int index = 0;//index of new array

		do
		{
			mid = mid < n ? mid : n;
			right = right < n ? right : n;
			int i1 = left;
			int i2 = mid;
			for (; i1 < mid && i2 < right;)
			{
				if (ar[i1] < ar[i2]) temp[index++] = ar[i1++];
				else temp[index++] = ar[i2++];
			}
			while (i1 < mid) temp[index++] = ar[i1++];
			while (i2 < right) temp[index++] = ar[i2++];
			left += 2*step;
			mid  += 2*step;
			right += 2*step;
		}while (left < n);

		for (int i = 0; i < n; i++) ar[i] = temp[i];
		step *= 2;
	}



}

int main()
{
	int * array = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++)
		array[i] = (rand() );

	merge(array, N);

//for (int i = 0; i < N; i++)
   // printf(" %d ", array[i]);
	system("pause");
}

