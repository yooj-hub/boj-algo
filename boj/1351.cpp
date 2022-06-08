#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;
ll n, p, q;
map<ll, ll> m;

ll solve(int x)
{
    if (m.find(x) != m.end())
        return m[x];
    return m[x] = solve(x / p) + solve(x / q);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> p >> q;
    m[0LL] = 1LL;
    cout << solve(n);
}