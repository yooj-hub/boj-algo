#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int t, d, n, x;
int s[50001];
ll cnt[1000001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--) {
        memset(s, 0, sizeof(s));
        memset(cnt, 0, sizeof(cnt));
        cin >> d >> n;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            s[i] = (s[i - 1] + x % d) % d;
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            cnt[s[i]]++;
        }
        if (cnt[0] != 0) {
            ans += cnt[0];
            ans += (cnt[0] * (cnt[0] - 1)) / 2;
        }
        for (int i = 1; i < d; i++) {
            if (cnt[i] >= 2)
                ans += (cnt[i] * (cnt[i] - 1)) / 2;
        }
        cout << ans << '\n';
    }
}