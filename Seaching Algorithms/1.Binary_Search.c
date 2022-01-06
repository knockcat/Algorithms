//Binary Search Implementation

/*
Time Complexity:
	Best Case 	: O(1)
	Worst Case	: O(logn)
	Average Case: O(logn)
*/

#include<stdio.h>

int Binary(int*,int,int,int);	//arr left right key

int main()
{
	int arr[] = {-9,0,15,25,34,35,90,413,672,1799};
	//	array need to be sorted for implementing binary search
	int key;
	
	int n = sizeof(arr)/sizeof(arr[0]);		//calculating size
	
	printf("Enter the Key you want to Search : ");
	scanf("%d",&key);
	
	int result = Binary(arr,0,n-1,key);		//arr left right key	//function call
	
	(result == -1)
		? printf("\nElement Not Present in ARRAY\n")
		: printf("\nElement Present at Index %d\n",result);
	
	return 0;
	
}

int Binary(int arr[], int l, int r, int key)
{
	if(r >= l)
	{
		int mid = (l+r)/2;
	
		if(key == arr[mid])
			return mid;
	
		else if(key < arr[mid])
			return Binary(arr,l,mid-1,key);	//recursive call r = mid - 1
	
		else
			return Binary(arr,mid+1,r,key);	//recursive call l = mid + 1
	}
	return -1;
}
