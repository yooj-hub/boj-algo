#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 2000000
using namespace std;

ll arr[MX];
ll tree[MX];
int n, m, k;

ll sum(int i) {
    ll ans = 0LL;
    while (i > 0) {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}

void update(int i, ll num) {
    while (i <= n) {
        tree[i] += num;
        i += (i & -i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        update(i, arr[i]);
    }
    for (int i = 0; i < m + k; i++) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            ll b, c;
            cin >> b >> c;
            ll diff = c - arr[b];
            arr[b] = c;
            update(b, diff);
        } else {
            ll b, c;
            cin >> b >> c;
            cout << sum(c) - sum(b-1) << '\n';
        }
    }
}