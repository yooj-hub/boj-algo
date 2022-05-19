#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
map<char, int> ci;
int cnt = 1;
const int mod = 900528;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++) {
        ci[a[i]] = cnt++;
    }
    int ans = 0;
    for (int i = 0; i < b.size(); i++) {
        ans = (ans * a.size() + ci[b[i]]) % mod;
    }
    cout << ans <<'\n';
}