#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 51

using namespace std;
ll d[MX][MX][MX];
vector<int> g[MX];
vector<int> tree[MX];
const int mod = 1e9 + 7;
int n, k;

void make_tree(int cur, int par) {
    for (auto nxt : g[cur]) {
        if (nxt == par)
            continue;
        tree[cur].push_back(nxt);
        make_tree(nxt, cur);
    }
}

ll go(int root, int cnt, int e) {
    ll &ans = d[root][cnt][e];
    if (ans != -1)
        return ans;
    if (cnt == 0) {
        return 1;
    }
    if (e == tree[root].size()) {
        if (cnt == 1) {
            return 1;
        } else {
            return 0;
        }
    }
    ans = 0;
    for (int i = 0; i < cnt; i++) {
        ll t1 = go(tree[root][e], i, 0);
        ll t2 = go(root, cnt - i, e + 1);
        ans = (ans + (t1 * t2) % mod)%mod;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    make_tree(1, -1);
    memset(d, -1, sizeof(d));
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + go(i, k, 0)) % mod;
    }
    cout << ans << '\n';
}