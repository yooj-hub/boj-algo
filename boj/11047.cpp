#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

int n, k;
vector<int> coins;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    coins.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        int t = k / coins[i];
        ans += t;
        k -= t * coins[i];
        if (k == 0)
            break;
    }
    cout << ans << '\n';
}