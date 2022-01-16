//Bucket/Bin Sort

/* 
Time Complexity	O(n)
Space Complexity O(n)     
*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

int GetMax(int*, int);
void BucketSort(int*,int);
void Insert(struct Node**,int);
int Delete(struct Node*, struct Node **);

//Sorted Insert in Buckets
void Insert(struct Node **H,int x)
{
	struct Node *t,*q=NULL,*p=*H;
 
	t=(struct Node*)malloc(sizeof(struct Node));
 	t->data=x;
 	t->next=NULL;
 
 	if(*H==NULL)
 		*H=t;
 	else
 	{
 		while(p && p->data<x)
 	{
 		q=p;
 		p=p->next;
 	}
 	if(p==*H)
 	{
 		t->next=*H;
 		*H=t;
 	}
 	else
 	{
 		t->next=q->next;
 		q->next=t;
 	}
 	}
 
}


//Delete from Sorted Buckets
int Delete(struct Node *p , struct Node **q)
{
	struct Node *curr = p, *prev = p;
	int data = curr -> data;
	curr = curr -> next;
	free(prev);
	prev = NULL;
	*q = curr;
	return data;
}
	
//func to find max value from array
int GetMax(int arr[],int n)
{
	int k = INT_MIN,i = 0;
	int output[n];
	
	for(i = 0; i<n; i++)			//Finding Max element
	{
		if(arr[i] > k)
			k = arr[i];
	}
	return k;
}

//print values of array
void print(int arr[],int n)
{
	int i;
    printf("\n\nArray after Sorting\n\n");
    for(i = 0; i<n; i++)
        printf("%d\t",arr[i]);
}

//Bucket Sort
void BucketSort(int arr[], int n)
{
	int i,j,max;
	max = GetMax(arr,n);		//finding max element for max size;
	
	struct Node **Bins;			//pointer to pointer
	
	//create Buckets/bins and allocate memoty
	Bins = (struct Node **)malloc(sizeof(struct Node*)*(max+1));	//creating array of pointers
	
	//Initializing empty bins/buckets to NULL
	for(i = 0; i<max+1; i++)
		Bins[i] = NULL;
	
	//filling bucket with respective element
	for(i = 0; i<n; i++)
		Insert(&Bins[arr[i]],arr[i]);
	
	//Updating Array with Sorted Buckets/values
	i  = 0,j =0;
	while(i<max+1)
	{	
		while(Bins[i] != NULL)
			arr[j++] = Delete(Bins[i],&Bins[i]);
		i++;
	}	

}

int main()
{
	int i;
//	int arr[] = {115,25,0,34,325,90,13,62,17};
	
	int arr[] = {115,245,10,34,40,90,69,66,7};

	int n = sizeof(arr)/sizeof(arr[0]);
	
	printf("\nElements in the Array\n\n");
	for(i = 0; i<n; i++)
    {
        printf("%d\t",arr[i]);
    }
    
    BucketSort(arr,n);
    print(arr,n);
    
    return 0;
}
