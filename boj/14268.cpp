#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010
using namespace std;
ll arr[1 << 17];
ll tree[1 << 19];
ll lazy[1 << 19];
int s[1 << 17];
int e[1 << 17];
vector<int> g[1 << 17];
int counter = 0;

void dfs(int x, int par) {
    s[x] = ++counter;
    for (auto &nxt : g[x]) {
        if (nxt == par)
            continue;
        dfs(nxt, x);
    }
    e[x] = counter;
}

void update_lazy(int node, int start, int end) {
    if (lazy[node] == 0)
        return;

    tree[node] += (end - start + 1) * lazy[node];
    if (start != end) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
}

void update_range(int node, int start, int end, int left, int right, int diff) {
    update_lazy(node, start, end);
    if (start > right || end < left)
        return;
    if (left <= start && end <= right) {
        lazy[node] += diff;
        update_lazy(node, start, end);
        return;
    }
    update_range(node * 2, start, (start + end) / 2, left, right, diff);
    update_range(node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int node, int start, int end, int idx) {
    update_lazy(node, start, end);
    if (idx < start || idx > end)
        return 0LL;
    if (start == end)
        return tree[node];
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, idx) +
           query(node * 2 + 1, mid + 1, end, idx);
}

int n, m;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int to;
        cin >> to;
        if (to == -1)
            continue;
        g[to].push_back(i);
    }

    dfs(1, -1);
    for (int i = 0; i < m; i++) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int a, w;
            cin >> a >> w;
            update_range(1, 1, n, s[a], e[a], w);
        } else {
            int a;
            cin >> a;
            cout << query(1, 1, n, s[a]) << '\n';
        }
    }
}