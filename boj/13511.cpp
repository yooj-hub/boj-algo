#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010
using namespace std;
const int sz = 18;
int p[MX][sz];
ll dist[MX];
int depth[MX];
int check[MX];
vector<pair<ll, int>> g[MX];

int n, m;

int get_lca(int u, int v) {
    if (depth[u] > depth[v])
        swap(u, v);
    int diff = depth[v] - depth[u];
    for (int i = 0; diff; i++) {
        if (diff & 1)
            v = p[v][i];
        diff >>= 1;
    }
    if (u == v)
        return u;
    for (int i = sz - 1; i >= 0; i--) {
        if (p[u][i] != p[v][i]) {
            u = p[u][i];
            v = p[v][i];
        }
    }
    return p[u][0];
}

ll get_dist(int u, int v) {
    int lca = get_lca(u, v);
    return dist[u] + dist[v] - 2 * dist[lca];
}
ll getk(int u, int v, int k) {
    int lca = get_lca(u, v);
    int diff = depth[u] - depth[lca];
    k--;
    if (diff >= k) {
        for (int i = 0; k; i++) {
            if (k & 1)
                u = p[u][i];
            k >>= 1;
        }
        return u;
    } else {
        k = depth[v] - depth[lca] + diff - k;
        for (int i = 0; k; i++) {
            if (k & 1)
                v = p[v][i];
            k >>= 1;
        }
        return v;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        g[from].push_back({cost, to});
        g[to].push_back({cost, from});
    }
    depth[1] = 0;
    check[1] = true;
    queue<int> q;
    p[1][0] = 0;
    dist[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (auto &nxt : g[current]) {
            if (check[nxt.second])
                continue;
            dist[nxt.second] = nxt.first + dist[current];
            depth[nxt.second] = depth[current] + 1;
            check[nxt.second] = true;
            p[nxt.second][0] = current;
            q.push(nxt.second);
        }
    }
    for (int j = 1; j < sz; j++) {
        for (int i = 1; i <= n; i++) {
            p[i][j] = p[p[i][j - 1]][j - 1];
        }
    }
    cin >> m;
    while (m--) {
        int kind;
        cin >> kind;
        if (kind == 1) {
            int a, b;
            cin >> a >> b;
            cout << get_dist(a, b) << '\n';
        } else {
            int a, b, c;
            cin >> a >> b >> c;
            cout << getk(a, b, c) << '\n';
        }
    }
}