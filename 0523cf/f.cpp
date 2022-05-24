#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 501010
#define INDEX first
#define DISTANCE second

using namespace std;
int n;
vector<pair<int, int>> graph[MX + 1];
ll d[MX + 1];
int depth[MX + 1];
int chk[MX + 1];
int parent[MX + 1][20];
bool is_leaf[MX + 1];
bool chk2[MX+1];

void dfs(int v, int dist, int dep) {
    chk[v] = 1;
    d[v] = dist;
    depth[v] = dep;
    bool x = true;
    for (auto nxt : graph[v]) {
        if (chk[nxt.INDEX])
            continue;
        parent[nxt.INDEX][0] = v;
        dfs(nxt.INDEX, dist + nxt.DISTANCE, dep + 1);
        bool x = false;
    }
    if (x) {
        is_leaf[v] = true;
    }
}

void makeTable() {
    for (int i = 1; i <= 15; i++) {
        for (int j = 1; j <= n; j++) {
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    }
}

ll lca(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);
    int diff = depth[u] - depth[v];
    ll ret = 0;
    for (int i = 0; diff; i++) {
        if (diff & 1) {
            if(!chk2[u]){
                ret += (d[u]);
                chk2[u] = true;
            }
            u = parent[u][i];
        }
        diff >>= 1;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        graph[u].emplace_back(v, x);
        graph[v].emplace_back(u, x);
    }
    dfs(1, 0, 0);
    makeTable();
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (is_leaf[i]) {
            ans += lca(1, i);
        }
    }
    cout << ans;
}