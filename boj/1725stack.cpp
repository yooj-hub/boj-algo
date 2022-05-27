#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

int n, l, r;
ll arr[MX];
stack<ll> stk;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    ll ans = 0;
    stk.push(0);
    for (int i = 1; i <= n+1; i++) {
        while (!stk.empty() && arr[stk.top()] > arr[i]) {
            ll height = arr[stk.top()];
            stk.pop();
            ans = max(ans, height * ((ll)i - (ll)1 - stk.top()));
        }
        stk.push(i);
    }
    cout << ans << '\n';
}