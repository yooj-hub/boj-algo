#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 201010

using namespace std;
int t, n, m;
int a[MX];
int b[MX];
int x;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--) {
        x = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        cin >> m;
        for (int i = 1; i <= m; i++) {
            cin >> b[i];
            x = (x + b[i]) % n;
        }
        x++;
        cout << a[x] << '\n';
    }
}