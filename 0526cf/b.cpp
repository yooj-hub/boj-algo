#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

int t, n;
vector<int> p;
int d[MX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        p.clear();
        p.resize(n);
        memset(d, 0, sizeof(d));
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        if (p[0] > p[1]) {
            d[1] = 1;
        }
        for (int i = 2; i < n; i++) {
            d[i] = d[i - 1];
            if (p[i - 1] > p[i]) {
                d[i] = max(d[i - 2] + 1, d[i]);
            }
        }
        cout << d[n - 1] << '\n';
    }
}