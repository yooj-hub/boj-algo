#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010
using namespace std;

bitset<MX * 10> chk;
ll n, x;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> x;
    if ((n - 1) * (n - 2) < x * 2) {
        cout << -1;
        return 0;
    }
    chk[n] = 1;
    chk[n - 1] = 1;
    cout << n - 1 << ' ';
    for (int pos = 1; x; pos++) {
        if (x >= n - 1 - pos) {
            cout << pos << ' ';
            x -= (n - 1 - pos);
            chk[pos] = 1;
        }
    }
    cout << n << " ";
    for (int i = n; i >= 1; i--) {
        if (!chk[i])
            cout << i << " ";
    }
}