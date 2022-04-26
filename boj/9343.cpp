#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 1101010
using namespace std;
const int mod = 1e9 + 7;
ll fac[MX * 2];
ll inv[MX * 2];

// 1111
ll pw(ll a, int b) {
    ll ret = 1;
    while (b) {
        if (b & 1) {
            ret = ret * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

void make_table() {
    fac[0] = 1;
    for (int i = 1; i <= 2000000; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
    inv[2000000] = pw(fac[2000000], mod - 2);
    for (int i = 1999999; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
}

ll combination(int n) {
    ll ret = fac[2 * n];
    ret = ret * inv[n] % mod;
    ret = ret * inv[n] % mod;
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    make_table();
    while (t--) {
        int n;
        cin >> n;
        cout << combination(n)/ combination(n-1) << '\n';
    }
}