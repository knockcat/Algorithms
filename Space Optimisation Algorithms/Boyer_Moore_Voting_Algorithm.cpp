// Boyer Moore Voting Algorithm

#include<bits/stdc++.h>
using namespace std;
#define fast std::ios::sync_with_stdio(false);cin.tie(nullptr);


// Boyer Moore Voting Algorithm (majority ELement || constant space)

// At max we can have two majority elements with floor(n/3) and minimum we can have zero


vector<int> solve(vector<int>& nums) {
    
    int num1 = -1, num2 = -1, count1 = 0, count2 = 0;
    vector<int> v;

    for(auto itr : nums)
    {
        if(num1 == itr)
            ++count1;
        else if(num2 == itr)
            ++count2;
        else if(count1 == 0)
        {
            num1 = itr;
            count1 = 1;
        }
        else if(count2 == 0)
        {
            num2 = itr;
            count2 = 1;
        }
        else
            --count1, --count2;
    }

    count1 = count2 = 0;

    for(auto itr : nums)
    {
        if(itr == num1)
            ++count1;
        if(itr == num2)
            ++count2;
    }

    if(count1 > nums.size()/3)
        v.push_back(num1);
    if(count2 > nums.size()/3)
        v.push_back(num2);

    if(v.empty())
        return v;

    if(v[0] > v[1])
        swap(v[0],v[1]);

    return v;
}

int main()

{
    fast;
    cout<<"Boyer Moore Voting Algorithm"<<endl;
    
    vector<int> nums = {2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6};
    
    vector<int> ans = solve(nums);
    
    for(auto itr : ans)
        cout<<itr<<" ";
    
    cout<<endl;
    
    return 0;
}
