#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

int a, b;
float a_base, inv_a_base;
float b_base, inv_b_base;
float ap[19];
float bp[19];
const ll mod = 1e9+7;
int comb[19][19];

void make_comb() {
    for (int i = 0; i <= 18; i++) {
        comb[i][0] = 1;
        comb[i][i] = 1;
        for (int j = 1; j < i; j++) {
            comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
        }
    }
}

long double pw(ll x, int y) {
    ll ret = 1.0;
    int cnt = 2 * y;
    while (y) {
        if (y & 1)
            ret *= x;
            if(ret > mod){
                ret %= mod;
                cnt -= 10;
            }
        x *= x;
        y >>= 1;
    }
    return ret;
}

bitset<19> isPrime;

int main() {
    cin >> a >> b;
    a_base = a;
    b_base = b;
    inv_a_base = 100 - a;
    inv_b_base = 100 - b;
    make_comb();
    for (int i = 0; i <= 18; i++) {
        ap[i] = pw(inv_a_base, 18 - i) * pw(a_base, i) * (float)comb[18][i];
        bp[i] = pw(inv_b_base, 18 - i) * pw(b_base, i) * (float)comb[18][i];
    }
    float ret = 1.0;
    for (int i = 4; i <= 18; i += 2)
        isPrime[i] = 1;
    for (int i = 3; i * i <= 18; i += 2) {
        if (isPrime[i])
            continue;
        for (int k = i * i; k <= 18; k += i) {
            isPrime[k] = 1;
        }
    }
    for (int i = 0; i <= 18; i++) {
        for (int j = 0; j <= 18; j++) {
            if (isPrime[i] && isPrime[j]) {
                ret -= ap[j] * bp[i];
            }
        }
    }
    printf("%f", ret);
}