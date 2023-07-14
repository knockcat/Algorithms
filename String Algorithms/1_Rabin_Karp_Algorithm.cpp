// Time Complexity -> O(n+m) on average, worst O(n*m)
// Space Complexity -> O(1)

/*
The average and best-case running time of the Rabin-Karp algorithm is O(n+m), but its worst-case time is O(nm).
The worst case of the Rabin-Karp algorithm occurs when all characters of pattern and text are the same as the hash values
of all the substrings of txt[] match with the hash value of pat[]. 
*/

vector<int> stringMatch(string text, string pattern) {
  // Write your code here.

  int n = text.size();
  int m = pattern.size();
  int d = 256;
  int h = 1;
  int q = 101;
  int t = 0;
  int p = 0;

  vector<int> ans;

  for (int i = 0; i < m - 1; ++i)
    h = (h * d) % q;

  for (int i = 0; i < m; ++i) {
    p = (p * d + pattern[i]) % q;
    ;
    t = (t * d + text[i]) % q;
  }

  for (int i = 0; i <= n - m; ++i) {
    if (t == p) {
      int j;
      for (j = 0; j < m; ++j) {
        if (pattern[j] != text[i + j])
          break;
      }

      if (j == m)
        ans.push_back(i+1);
    }

    if (i < n - m) {
      t = (d * (t - text[i] * h) + text[i + m]) % q;
      if (t < 0)
        t = t + q;
    }
  }

  return ans;
}
