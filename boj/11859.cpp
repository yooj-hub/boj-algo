#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;
int d[110101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    for (int i = 1; i <= n; i++) {
        d[i] = d[i - 1] + d[i];
    }
    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << d[b] - d[a - 1] << '\n';
    }
}