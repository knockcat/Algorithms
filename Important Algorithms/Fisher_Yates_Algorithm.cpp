// Fisher Yates Algorithm

// For Random Shuffling of an array

// We will traverse the Array from End
// The algorith will generate an random index using rand() function as (j = rand() % size) with the remaining window
// (which is equal to array size at First)
// We perform a swap operation with the randowm[index] and endOfWindow[index]
// and decrement the window size (as --size).

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> org;
    int n;
    Solution(vector<int> &nums)
    {
        org = nums;
        n = nums.size();
    }

    vector<int> reset()
    {
        return org;
    }

    vector<int> shuffle()
    {
        vector<int> temp = org;
        int size = org.size();

        for (int i = n - 1; i >= 0; --i)
        {
            int j = rand() % size;
            swap(temp[i], temp[j]);
            --size;
        }
        return temp;
    }
};

void print(vector<int> &nums)
{
    for (auto itr : nums)
        cout << itr << " ";
    cout << endl;
}

int32_t main()
{

    vector<int> nums = {1, 2, 3};
    Solution *obj = new Solution(nums);
    vector<int> param_1 = obj->reset();
    vector<int> param_2 = obj->shuffle();

    print(param_1);
    param_2 = obj->shuffle();
    print(param_2);
    param_2 = obj->shuffle();
    print(param_2);
    param_2 = obj->shuffle();
    print(param_2);
    param_2 = obj->shuffle();
    print(param_2);

    return 0;
}