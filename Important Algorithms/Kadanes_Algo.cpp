/*
For getting maximum contiguous subarray sum in O(N)

Kadane's Algorithm is Divided into 3 Steps
    Run a For Loop
    1. Keep track of Running sum as currSum
    2. update maxSum as max(maxSum, currSum)
    3. if(currSum < 0)
            update currSum as 0
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = v.size();

    int currSum = 0, maxSum = INT_MIN;

    for (int i = 0; i < n; ++i)
    {
        currSum += v[i];
        maxSum = max(maxSum, currSum);
        if (currSum < 0)
            currSum = 0;
    }

    cout << "Maximum Subarray Sum : " << maxSum << '\n';
}
