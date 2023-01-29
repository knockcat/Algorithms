#include <bits/stdc++.h>
using namespace std;

#define ll long long int
ll mod = 1e9 + 7;

ll expo(ll x, ll y, ll mod)
{
    ll res = 1;

    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }

    return res;
}

int32_t main()
{
    ll ans = expo(2, 2000, mod);
    ans = (ans + mod) % mod;
    cout << ans << endl;
}