#include <bits/stdc++.h>
#define MX 101010

using namespace std;
vector<int> arr[MX];
int parent[MX];
int chk[MX];
int depth[MX];
int p[MX][17];

int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }

    int log = 1;
    for (log = 1; (1 << log) <= depth[u]; log++)
        ;

    log -= 1;

    for (int i = log; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = p[u][i];
        }
    }
    if (u == v) {
        return u;
    } else {
        for (int i = log; i >= 0; i--) {
            if (p[u][u] != 0 && p[u][i] != p[v][i]) {
                u = p[u][i];
                v = p[v][i];
            }
        }
        return p[u][0];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    depth[1] = 0;
    chk[1] = true;
    queue<int> q;
    q.push(1);
    parent[1] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int y : arr[x]) {
            if (!chk[y]) {
                depth[y] = depth[x] + 1;
                chk[y] = true;
                parent[y] = x;
                q.push(y);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        p[i][0] = parent[i];
    }
    for (int j = 1; (1 << j) < n; j++) {
        for (int i = 1; i <= n; i++) {
            if (p[i][j - 1] != 0) {
                p[i][j] = p[p[i][j - 1]][j - 1];
            }
        }
    }
    int m;
    cin >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
    return 0;
}