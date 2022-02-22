// Jump Search Implementation

/*
Time Complexity:
    Best Case 	: Time Complexity : O(√n)

    Average Case: O(n/m + (m-1))  n is size & m is jump
*/

#include <stdio.h>
#include <math.h>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int JumpSearch(int *, int, int); // arr, size , key

int main()
{
    int arr[] = {-9, 0, 15, 25, 34, 35, 90, 413, 672, 1799};
    //	array need to be sorted for implementing Jump search
    int key;

    int n = sizeof(arr) / sizeof(arr[0]); // calculating size

    printf("Enter the Key you want to Search : ");
    scanf("%d", &key);

    // Find the index of 'x' using Jump Search
    int result = JumpSearch(arr, n, key);

    (result == -1)
        ? printf("\nElement Not Present in ARRAY\n")
        : printf("\nElement Present at Index %d\n", result);

    return 0;
}

int JumpSearch(int arr[], int n, int key)
{
    // Finding block size to be jumped
    int step = sqrt(n);

    // Finding the block where element is
    // present (if it is present)
    int prev = 0;

    while (arr[MIN(step, n) - 1] < key)
    {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }

    // Doing a linear search for x in block
    // beginning with prev.
    while (arr[prev] < key)
    {
        ++prev;
        if (prev == MIN(step, n))
            return -1;
    }
    // If element is found
    if (arr[prev] == key)
        return prev;

    return -1;
}
