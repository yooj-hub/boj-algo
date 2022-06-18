#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;

ll mx, mn;
vector<bool> isPrime;
bool isp[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> mn >> mx;
    int sz = mx - mn + 1;
    isPrime.resize(sz, true);
    memset(isp, true, sizeof(isp));
    for (int i = 2; i <= 1000000; i++)
    {
        if (!isp[i])
            continue;
        int pv = i * 2;
        while (pv <= 1000000)
        {
            isp[pv] = false;
            pv += i;
        }
    }
    for (ll i = 2; i <= 1000000; i++)
    {
        if (!isp[i])
            continue;
        ll pv = i * i;
        ll start = (mn / pv) * pv;
        if (start < mn)
            start += pv;

        while (start <= mx)
        {
            isPrime[start - mn] = false;
            start += pv;
        }
    }
    ll answer = 0;
    for (int i = 0; i < isPrime.size(); i++)
    {
        if (isPrime[i])
            answer++;
    }
    cout << answer << '\n';
}