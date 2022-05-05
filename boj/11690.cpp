#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;
const ll mod = (1LL << 32);
bitset<100000001> b;
ll n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    ll ans = 1LL;
    ll i = 2;
    for (; i * i <= n; i++) {
        if (!b[i]) {
            ll tmp = 1LL;
            while (tmp * i <= n)
                tmp *= i;
            ans = (ans * tmp) % mod;
            ll k = i * i;
            while (k <= n) {
                b[k] = 1;
                k += i;
            }
        }
    }
    for(;i<=n; i++) if(!b[i]) ans = (ans * i)%mod;
    

    cout << ans << '\n';
}