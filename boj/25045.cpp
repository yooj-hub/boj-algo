#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 201010

using namespace std;

int n, m;
ll a[MX];
ll b[MX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    ll res = 0LL;
    int st = 1;
    for (int i = n; i >= 1; i--) {
        if (a[i] > b[st]) {
            res += a[i] - b[st++];
        }
        if(st>m) break;
    }
    cout << res << '\n';
}