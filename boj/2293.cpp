#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

int n, k;
vector<int> coins;
int d[10001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    coins.resize(n);
    d[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    for (auto coin : coins) {
        for (int j = coin; j <= k; j++) {
            d[j] += d[j - coin];
        }
    }
    cout << d[k];
}