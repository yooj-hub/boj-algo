#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 4404040
using namespace std;
const int mod = 1e9 + 7;

ll arr[MX];
ll inv[MX];

ll pw(ll a, int b) {
    ll ret = 1;
    while (b>0) {
        if (b & 1) {
            ret *= (a % mod);
            ret %= mod;
        }
        a *= a;
        a %= mod;
        b >>=1;
    }
    return ret;
}

void make_table() {
    arr[0] = 1;
    for (int i = 1; i <= 4000000; i++) {
        arr[i] = arr[i-1] * i % mod;
    }
    inv[4000000] = pw(arr[4000000], mod - 2);
    for (int i = 3999999; i >= 0; i--) {
        inv[i] = (inv[i + 1] * (i + 1)) % mod;
    }
}

ll calc(int n, int k) {
    if (k == n || k == 0)
        return 1LL;

    ll ret = arr[n];
    ret = ret * inv[k] % mod;
    ret = ret * inv[n-k] % mod;

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    make_table();
    cout << calc(n,k)<<'\n';
}