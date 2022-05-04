#include <bits/stdc++.h>
#define ll unsigned long long int
#define all(x) x.begin(), x.end()

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll x;
    cin >> x;
    ll start = 0;
    ll end = sqrt(x) + 1;
    ll ans = 0;
    bool ok = true;
    while (start <= end) {
        ll mid = (start + end) / 2;
        if (mid >= sqrt(x)) {
            end = mid - 1;
            if (ok || ans > mid) {
                ans = mid;
                ok = false;
            }

        } else {
            start = mid + 1;
        }
    }
    cout << ans << '\n';
}