#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int n, k;
int d[101][100001];
vector<pair<int, int>> items;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    items.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        items[i] = {a, b};
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (items[i].first <= j) {
                d[i][j] = max(d[i - 1][j],
                              d[i - 1][j - items[i].first] + items[i].second);
            } else {
                d[i][j] = d[i - 1][j];
            }
        }
    }
    cout << d[n][k] << '\n';
}