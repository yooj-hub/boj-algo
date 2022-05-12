#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int n;
ll arr[18][18];

ll get_score(int r) {
    ll ret = 0LL;
    for (int j = 0; j < n; j++) {
        ll color = 0LL;
        ll non_color = 0LL;
        for (int i = 0; i < n; i++) {
            if (r & (1 << i)) {
                non_color += arr[i][j];
            } else {
                color += arr[i][j];
            }
        }
        ret += max(color, non_color);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    ll tot = 0LL;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            tot += arr[i][j];
        }
    }
    ll ans = 0LL;

    for (int i = 0; i < (1 << n); i++) {
        ans = max(tot - get_score(i), ans);
    }
    cout << ans << '\n';
}