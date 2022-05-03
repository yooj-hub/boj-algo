#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;
int n, m;
vector<string> s;
bool check(int x) {
    if (x == 0)
        return true;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0 && x / i == i)
            return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    s.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int ans = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (check(s[i][j] - '0')) {
                ans = max(ans, s[i][j] - '0');
            }
        }
    }

    for (int sx = 0; sx < n; sx++) {
        for (int sy = 0; sy < m; sy++) {
            for (int i = -n + 1; i <= n - 1; i++) {
                for (int j = -m + 1; j <= m - 1; j++) {
                    if (i == 0 && j == 0) {
                        if (check(s[sx][sy] - '0'))
                            ans = max(ans, s[sx][sy] - '0');
                        continue;
                    }
                    int ret = 0;
                    for (int x = sx, y = sy; x < n && y < m && x >= 0 && y >= 0;
                         x += i, y += j) {
                        ret = (s[x][y] - '0') + ret * 10;
                        if (check(ret)) {
                            ans = max(ans, ret);
                        }
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}