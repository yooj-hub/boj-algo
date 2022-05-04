#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;

vector<ll> arr;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, k;
    cin >> k >> n;
    arr.resize(k);
    ll mx = -1;
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
        mx = max(arr[i], mx);
    }
    ll left = 1;
    ll right = mx;
    ll ans = -1;
    while (left <= right) {
        ll mid = (left + right) / 2;
        ll tmp = 0;
        for (auto &x : arr) {
            tmp += x / mid;
        }
        if (tmp >= n) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << ans;
}