// Time Complexity -> O(n+m) n and m is length of text and pattern
// Space Complexity -> O(k) here k is the lenght of n + '$' + m

#include<bits/stdc++.h>
using namespace std;

vector<int> calculateZ(string& str)
{
  int n = str.length();

  vector<int> z(n);

  int left = 0, right = 0;

  z[0] = 0;

  for(int k = 1; k < n; ++k)
  {
    if(k > right)
    {
      left = right = k;

      while(right < n and str[right] == str[right-left])
        ++right;
      
      z[k] = right - left;
      
      --right;
    }
    else
    {
      int k1 = k - left;

      if(z[k1] + k <= right)
      {
        z[k] = z[k1]; 
      }
      else
      {
        left = k;
        
        while(right < n and str[right] == str[right-left])
          ++right;
        
        z[k] = right - left;

        --right;
      }
    }
  }

  return z;
  
}

int zAlgorithm(string s, string p, int n, int m)
{
	// Write your code here

  string c = p;

  c += '#';
  
  c += s;
  
  int size = c.size();

  vector<int> z = calculateZ(c);

  int cnt = 0;

  for(int i = 0; i < size; ++i)
  {
    if (z[i] == m) {
      ++cnt;
    }
  }

  return cnt;
}

int main()

{
    
    int n = 10, m = 4;
    string text = "codercodes";
    string pattern = "code";
    
    cout<<"no of Occurences of pattern in text "<<zAlgorithm(text,pattern,n,m)<<endl;
    
    return 0;
}
