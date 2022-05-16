#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
map<string, int> m1;
map<string, string> m2;
int n, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string k;
        cin >> k;
        m1[k] = i;
        m2[to_string(i)] = k;
    }

    while (m--) {
        string q;
        cin >> q;
        if (m1.find(q) != m1.end()) {
            cout << m1[q] << '\n';
        } else {
            cout << m2[q] << '\n';
        }
    }
}