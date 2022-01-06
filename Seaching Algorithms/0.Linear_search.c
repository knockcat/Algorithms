//Linear Search Implementation

/*
Time Complexity:
	Best Case 	: O(1)
	Worst Case	: O(n)
	Average Case: O((n+1)/2)
*/

#include<stdio.h>

int Linear(int*,int,int);

int main()
{
	int arr[] = {15,5,20,35,2,42,67,17};
	int key;
	
	int n = sizeof(arr)/sizeof(arr[0]);		//calculating size
	
	printf("Enter the Key you want to Search : ");
	scanf("%d",&key);
	
	int result = Linear(arr,key,n);			//function call
	
	(result == -1)
		? printf("\nElement Not Present in ARRAY\n")
		: printf("\nElement Present at Index %d\n",result);
	
	return 0;
	
}

int Linear(int arr[], int key,int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(key == arr[i])		//traversing array element 1 by 1
		{
			return i;
		}
	}
	return -1;
	
}
