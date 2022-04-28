#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;

ll tree[1101010];
int pre[1101010];
int arr[1101010];
int n;

void add(int i)
{
    while (i <= n)
    {
        tree[i]++;
        i += i & (-i);
    }
}

ll sum(int i)
{
    ll ret = 0;
    while (i)
    {
        ret += tree[i];
        i -= (i & (-i));
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        pre[t] = i;
    }
    for(int i=1; i<=n;i++){
        int t;
        cin >> t;
        arr[i] = pre[t];
    }
    ll ans = 0LL;
    for(int i=1; i<=n;i++){
        int j = arr[i];
        ans += sum(n) - sum(j);
        add(j);
    }
    cout << ans << '\n';

}