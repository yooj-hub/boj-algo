#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int n, k;
vector<ll> a;
vector<ll> b;
vector<ll> c;
vector<ll> d;
vector<ll> cur;
vector<long double> tmp;
void find_max() {
    double fa = ((long double)a.back()) / cur[0];
    double fb = ((long double)b.back()) / cur[1];
    double fc = ((long double)c.back()) / cur[2];
    double fd = ((long double)d.back()) / cur[3];
    tmp = {fa, fb, fc, fd};
    sort(all(tmp));
    if (fa == tmp[3]) {
        cur[0] += a.back();
        cout << 'A' << ' ' << a.back() << '\n';
        a.pop_back();

    } else if (fb == tmp[3]) {
        cur[1] += b.back();
        cout << 'B' << ' ' << b.back() << '\n';
        b.pop_back();

    } else if (fc == tmp[3]) {
        cur[2] += c.back();
        cout << 'C' << ' ' << c.back() << '\n';
        c.pop_back();

    } else {
        cur[3] += d.back();
        cout << 'D' << ' ' << d.back() << '\n';
        d.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < 4; i++) {
        ll t;
        cin >> t;
        cur.push_back(t);
    }
    a.push_back(0LL);
    b.push_back(0LL);
    c.push_back(0LL);
    d.push_back(0LL);
    for (int i = 0; i < n; i++) {
        char x;
        ll t;
        cin >> x >> t;
        if (x == 'A') {
            a.push_back(t);

        } else if (x == 'B') {
            b.push_back(t);

        } else if (x == 'C') {
            c.push_back(t);

        } else {
            d.push_back(t);
        }
    }
    sort(all(a));
    sort(all(b));
    sort(all(c));
    sort(all(d));
    while (k--) {
        find_max();
    }
}