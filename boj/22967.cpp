#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;
int n;
int d[301][301];
int degree[301];
const int inf = 1e9 + 7;
vector<pair<int, int>> ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < 301; i++) {
        fill(d[i], d[i] + 301, inf);
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        d[a][b] = 1;
        d[b][a] = 1;
        degree[a]++;
        degree[b]++;
    }

    if (n <= 4) {
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (d[i][j] != 1) {
                    ans.push_back({i, j});
                }
            }
        }
        cout << "1\n";
        cout << ans.size() << '\n';
        for (auto &x : ans) {
            cout << x.first << ' ' << x.second << '\n';
        }
    } else {
        for (int i = 2; i <= n; i++) {
            if (d[1][i] != 1) {
                ans.push_back({1, i});
            }
        }
        cout << "2\n";
        cout << ans.size() << '\n';
        for (auto &x : ans) {
            cout << x.first << ' ' << x.second << '\n';
        }
    }
}