#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int n, r, c;
ll ans = 0;
ll tmp = 0;
void f(int sx, int sy, int sz) {
    if (sx == r && sy == c) {
        ans = tmp;
        return;
    }

    if (sx <= r && r < sx + sz && sy <= c && c < sy + sz) {
        f(sx, sy, sz / 2);
        f(sx, sy + sz / 2, sz / 2);
        f(sx + sz / 2, sy, sz / 2);
        f(sx + sz / 2, sy + sz / 2, sz / 2);
    } else {
        tmp += sz * sz;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> r >> c;
    f(0, 0, (1 << n));
    cout << ans << '\n';
}