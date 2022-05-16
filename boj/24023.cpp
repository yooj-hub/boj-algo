#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 201010

using namespace std;

int n, k;
ll arr[MX];
ll s[MX];
int cnt[32];

int change_cnt(int x, int op) {
    int idx = 0;
    while (x) {
        if (x & 1) {
            if (op == 1) {
                cnt[idx]++;
            } else {
                cnt[idx]--;
            }
        }
        x >>= 1;
        idx++;
    }
    int res = 0;
    for (int i = 0; i <= 31; i++) {
        if (cnt[i] >= 1) {
            res |= (1 << i);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int s = 1, e = 1;
    int res = change_cnt(arr[1], 1);
    bool ok = false;
    while (true) {
        // cout << s << ' ' <<e << endl;

        // cout << res << endl;
        if (res == k) {
            ok = true;
            break;
        }
        if (s > n || e > n) {
            break;
        }
        if (res > k) {
            res = change_cnt(arr[s++], -1);
        } else {
            res = change_cnt(arr[++e], 1);
        }
    }
    if (ok) {
        cout << s << ' ' << e << '\n';
    } else {
        cout << -1;
    }
}
