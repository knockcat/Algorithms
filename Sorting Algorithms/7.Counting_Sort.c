//Counting Sort

/* 
Time Complexity
    O(n+k)		n (number of element) k (range)
*/

//Not applicable for -ve numbers as there are no negative indices

#include<stdio.h>
#include<limits.h>				//for INT_MIN
#include<string.h>				//for memset function

void Counting(int*,int);
void print(int*,int);


int main()
{
	int i;
	int arr[] = {115,25,0,34,325,90,13,62,17};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	printf("\nElements in the Array\n\n");
	for(i = 0; i<n; i++)
    {
        printf("%d\t",arr[i]);
    }
    
    Counting(arr,n);
    print(arr,n);
    
    return 0;
}

void Counting(int arr[], int n)
{
	int k = INT_MIN,i = 0;
	int output[n];
	
	for(i = 0; i<n; i++)			//Finding Max element
	{
		if(arr[i] > k)
			k = arr[i];
	}

	int count[k+1];				//maintaning of count array of k+1
	
	//The function memset() is a library function from string.h. 
	//It is used to fill a block of memory with a particular value.
	
	memset(count, 0, sizeof(count));	//initializing count array with 0
	
	//storing count of each character
	for(i = 0; i<n; i++)
	{
		++count[arr[i]];
	}
	
	//modifing count array to show actual positons
	
	for(i = 1; i <= k; i++)			//i = 1 for maintaining stablility
	{
		count[i] += count[i-1];
	}

	//building sorted value in output array 
	for(i = n-1; i >= 0; i--)
	{
		output[--count[arr[i]]] = arr[i];
	}

	//copying values to orignal array
	
	for(i = 0; i < n; i++)
		arr[i] = output[i];

}

void print(int arr[],int n)
{
	int i;
    printf("\n\nArray after Sorting\n\n");
    for(i = 0; i<n; i++)
        printf("%d\t",arr[i]);
}
