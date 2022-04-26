#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 1101010
using namespace std;

ll fac[MX];
ll inv[MX];
const int mod = 1e9 + 7;

ll pw(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1)
            ret = ret * a % mod;

        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

void make_table() {
    fac[0] = 1;
    for (int i = 1; i <= 1000000; i++) {
        fac[i] = fac[i - 1] * i% mod;
    }
    inv[1000000] = pw(fac[1000000], mod - 2);
    for (int i = 999999; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
}

ll comb(int a, int b) {
    ll ret = fac[a];
    ret = ret * inv[b] % mod;
    return ret = ret * inv[a - b] % mod;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    make_table();
    int n, m;
    cin >> n >> m;
    cout << comb(n, m) << '\n';
}