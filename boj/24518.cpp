#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;

ll n, m, i, j;
const int mod = 1e9 + 7;

ll calc(ll start, ll end)
{
    ll ret = 0;
    if (start / m == end / m)
    {
        ret += ((start % m + end % m) * (end % m - start % m + 1))/2 % mod;
        ret %= mod;
    }
    else
    {
        ret += ((end % m) * (end % m + 1))/2 % mod;
        ret %= mod;
        ret += ((m - 1 + start % m) * (m - 1 - start % m + 1))/2 % mod;
        ret %= mod;
        ret += ((m * (m - 1)) * (end / m - start / m - 1))/2 % mod;
        ret %=mod;
    }
    return ret % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    ll ret = 0;
    i = 1;
    while (i <= n)
    {
        j = n / (n / i);
        ret = ((ret + (((n / i) * calc(i, j)) % mod)) % mod);
        i = j + 1;
    }
    cout << ret << '\n';
}