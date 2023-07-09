// Time complexity -> O(N)
// Space complexity -> O(1)

#include<bits/stdc++.h>
using namespace std;

int getPartition(vector<int>& arr, int low, int high)
{
	int pivotElement = arr[high];
	int pivotIndex = low;

	for(int i = low; i <= high; ++i)
	{
		if(arr[i] < pivotElement)
		{
			swap(arr[i], arr[pivotIndex++]);
		}
	}

	swap(arr[pivotIndex], arr[high]);

	return pivotIndex;
}

int quickSelect(vector<int> &arr, int low, int high, int k) {
  int pivotIndex = getPartition(arr, low, high);

  if (pivotIndex == k)
    return arr[k];
  else if (pivotIndex < k)
    return quickSelect(arr, pivotIndex + 1, high, k);
  else
    return quickSelect(arr, low, pivotIndex - 1, k);
}

vector<int> kthSmallLarge(vector<int> &arr, int n, int k) {
  vector<int> v(2);

  v[0] = quickSelect(arr, 0, n-1, k - 1);
  v[1] = quickSelect(arr, 0, n-1, n - k);

  return v;
}

int main()
{
    vector<int> v = {-21, -67, 38, -99, 15, 59, -6, 12, 26, -77};
    
    int k = 8;
    
    vector<int> ans = kthSmallLarge(v, v.size(), k);
    
    cout<<k<<"th Smallest "<<ans[0]<<endl;
    cout<<k<<"th Largest "<<ans[1]<<endl;
    
    return 0;
}
