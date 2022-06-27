#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define ll long long int
#define MX 101010

using namespace std;

int t, n;
ll d[1000][1 << 4];

ll go(int idx, int state)
{
    if (idx == n * 4 && state == 0)
    {
        return 1LL;
    }
    if (idx >= n * 4)
        return 0LL;

    ll &ans = d[idx][state];
    if (ans !=-1)
        return ans;
    ans = 0;
    if (state & 1)
    {
        return ans += go(idx + 1, state >> 1);
    }
    // 가로
    if ((state & 2) == 0 && idx % 4 != 3)
    {
        ans += go(idx + 2, state >> 2);
    }
    // 세로
    ans += go(idx + 1, (state >> 1) | (1 << 3));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--)
    {
        cin >> n;
        memset(d, -1, sizeof(d));
        cout << go(0, 0) << '\n';
    }
}