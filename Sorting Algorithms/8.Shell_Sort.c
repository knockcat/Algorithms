//Shell Sort

/* 
Time Complexity
    Best  Case : O(nlogn)
    Worst Case : O(n^2) 		//depend upon gap
*/

//In this Sorting Technique less no. of comparrisons required in compare to insertion sort.

#include<stdio.h>

void ShellSort(int*,int);
void swap(int*,int*);
void print(int*,int);

int main()
{
	int i;
	int arr[] = {23,29,15,19,31,7,9,5,2};	//Initializing an array
	int n = sizeof(arr)/sizeof(arr[0]);
	
	printf("\n\nElements in the Array\n\n");
	for(i = 0; i<n; i++)
	{
		printf("%d\t",arr[i]);
	}
	
	ShellSort(arr,n);
	print(arr,n);
	
	return 0;
	
}

void ShellSort(int arr[], int n)
{
	int i,j,gap;
	
	for(gap = n/2; gap > 0; gap = gap/2)			//initially gap = n/2 , decreasing by n/2
	{
		for(j = gap ; j < n; j++)
		{
			for(i = j-gap; i >= 0; i = i-gap)	//i =  i-gap
			{
				if(arr[i+gap] >= arr[i])
					break;
				else
					swap(&arr[i+gap],&arr[i]);
			}
		}
	}
}

void swap(int *a, int *b)				//swap contents
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print(int arr[],int n)
{
	int i;
    printf("\n\nArray after Sorting\n\n");
    for(i = 0; i<n; i++)
        printf("%d\t",arr[i]);
}
