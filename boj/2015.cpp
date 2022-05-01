#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;
map<int, ll> m;
int d[220202];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        d[i] = d[i - 1] + d[i];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] == k)
            ans++;
        ans += m[d[i]-k];
        m[d[i]]++;
    }
    cout << ans << '\n';
}