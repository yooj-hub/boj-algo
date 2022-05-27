#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int t, m, n, x, y, ty;
bool ok;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> m >> n >> x >> y;
        ok = false;
        if (x % n)
            ty = x % n;
        else
            ty = n;
        int g = __gcd(m,n);
        int ans = x;
        while (ans <= n/g * m) {
            if (ty == y) {
                ok = true;
                break;
            }

            ty = (ty + m) % n;
            if (ty == 0) {
                ty = n;
            }
            ans += m;
        }
        if (ok) {
            cout << ans << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}