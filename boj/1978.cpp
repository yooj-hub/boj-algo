#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;
bitset<1001> b;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    b[1] = 1;
    for (int i = 2; i * i < 1000; i++) {
        if (!b[i]) {
            for (int k = i * i; k <= 1000; k += i)
                b[k] = 1;
        }
    }
    int ans = 0;
    while (t--) {
        int x;
        cin >> x;
        if (!b[x])
            ans++;
    }
    cout << ans << '\n';
}