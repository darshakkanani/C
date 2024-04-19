#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void printRandoms(int data[],int size)
{
    int lower = 1;
    int upper = size;
    for (int i = 0; i < size; i++)
    {
        data[i] = (rand() % (upper - lower + 1)) + lower;
    }
}

void merge(int arr[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 

	int L[n1], R[n2]; 

	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1 + j]; 

	i = 0; 

	j = 0; 

	k = l; 
	while (i < n1 && j < n2) { 
		if (L[i] <= R[j]) { 
			arr[k] = L[i]; 
			i++; 
		} 
		else { 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	while (i < n1) { 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 

	while (j < n2) { 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 

void mergeSort(int arr[], int l, int r) 
{ 
	if (l < r) { 

		int m = l + (r - l) / 2; 

		mergeSort(arr, l, m); 
		mergeSort(arr, m + 1, r); 

		merge(arr, l, m, r); 
	} 
} 

int main()
{
    int arr[50000];
    int size = 50000;
    printRandoms(arr,size);

    clock_t start = clock();
    mergeSort(arr, 0,size-1);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Merge Sort: %lf\n", time_taken);

    return 0;
}
