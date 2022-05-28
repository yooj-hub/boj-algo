#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int d[(1 << 16)][16];
int n;
int a[16][16];
const int inf = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < (1 << n); i++) {
        fill(d[i], d[i] + 16, inf);
    }
    d[1][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 1; j < n; j++) {
            if (i & (1 << j)) {
                for (int k = 0; k < n; k++) {
                    if (k != j && (i & (1 << k)) && a[k][j]) {
                        d[i][j] = min(d[i][j], d[i - (1 << j)][k] + a[k][j]);
                    }
                }
            }
        }
    }
    int ans = inf;
    for (int i = 1; i < n; i++) {
        if (a[i][0]) {
            ans = min(ans, d[(1 << n) - 1][i] + a[i][0]);
        }
    }
    cout << ans << '\n';
}