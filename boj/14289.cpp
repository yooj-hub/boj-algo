#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const int MOD = 1e9 + 7;
int n, m, d;
int a, b;

struct matrix {
    int sz;
    ll data[1000][1000];

    matrix(int sz) {
        this->sz = sz;
        memset(data, 0, sizeof(data));
    }
    matrix operator*(matrix other) {
        matrix ret = *new matrix(sz);
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                ll tmp = 0;
                for (int k = 0; k < sz; k++) {
                    tmp += (data[i][k] % MOD) * (other.data[k][j] % MOD);
                    tmp %= MOD;
                }
                ret.data[i][j] = tmp;
            }
        }
        return ret;
    }
};

matrix pw(int k, matrix &base) {

    matrix ret = matrix(base.sz);
    for (int i = 0; i < base.sz; i++) {
        ret.data[i][i] = 1;
    }
    while (k) {
        if (k & 1) {
            ret = ret * base;
        }
        base = base * base;
        k >>= 1;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    matrix base = *new matrix(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--;
        b--;
        base.data[a][b] = 1;
        base.data[b][a] = 1;
    }
    cin >> d;
    matrix ret = pw(d, base);
    cout << ret.data[0][0];
}