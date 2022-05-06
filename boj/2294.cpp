#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;

int d[10001];
const int inf = 1e9 + 7;
vector<int> coins;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    coins.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    fill(d, d + 10001, inf);
    d[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j - coins[i] >= 0) {
                d[j] = min(d[j], d[j - coins[i]] + 1);
            }
        }
    }
    cout << ((d[k] == inf) ? -1 : d[k]) << '\n';
}