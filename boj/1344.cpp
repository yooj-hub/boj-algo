#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

long double d[19][19][19];
bitset<19> isPrime;
int a, b;
long double ap, bp;

long double go(int idx, int aw, int bw) {
    if (idx < aw || idx < bw || aw < 0 || bw < 0)
        return 0;
    if (d[idx][aw][bw] != -1.0)
        return d[idx][aw][bw];
    long double &ret = d[idx][aw][bw];
    ret = 0.0;
    ret += (1.0 - ap) * (1.0 - bp) * go(idx - 1, aw, bw);
    ret += ap * (1.0 - bp) * go(idx - 1, aw - 1, bw);
    ret += ap * bp * go(idx - 1, aw - 1, bw - 1);
    ret += (1.0 - ap) * bp * go(idx - 1, aw, bw - 1);
    return ret;
}

void make_isPrime() {
    isPrime[0] = 1;
    isPrime[1] = 1;
    for (int i = 4; i <= 18; i += 2)
        isPrime[i] = 1;
    for (int i = 3; i * i <= 18; i += 2) {
        if (isPrime[i])
            continue;
        for (int x = i * i; x <= 18; x += i) {
            isPrime[x] = 1;
        }
    }
}
void init() {
    ap = (long double)a * 0.01;
    bp = (long double)b * 0.01;

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            fill(d[i][j], d[i][j] + 19, -1.0);
        }
    }
}

int main() {
    make_isPrime();
    cin >> a >> b;
    init();
    long double ans = 1.0;
    d[0][0][0] = 1.0;
    for (int i = 0; i <= 18; i++) {
        for (int j = 0; j <= 18; j++) {
            if (isPrime[i] && isPrime[j]) {
                ans -= go(18, i, j);
            }
        }
    }
    printf("%.10Lf", ans);
}