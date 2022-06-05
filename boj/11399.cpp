#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

int n;
vector<int> p;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(all(p));
    int ans = 0;
    int tmp = 0;
    for (auto x : p) {
        ans += x + tmp;
        tmp += x;
    }
    cout << ans;
}