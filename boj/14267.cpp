#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 110101
using namespace std;
vector<int> g[MX];
int n, q;
int counter;
int s[MX];
int e[MX];
ll tree[MX * 4];
ll lazy[MX * 4];
void dfs(int current, int par) {
    s[current] = ++counter;
    for (auto &nxt : g[current]) {
        if (nxt == par)
            continue;
        dfs(nxt, current);
    }
    e[current] = counter;
}

void update_lazy(int node, int start, int end) {
    if (lazy[node] == 0)
        return;
    tree[node] += lazy[node] * (end - start + 1);
    if (start != end) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
}

void update_range(int node, int start, int end, int left, int right, int val) {
    update_lazy(node, start, end);
    if (start > right || left > end)
        return;
    if (left <= start && end <= right) {
        lazy[node] += val;
        update_lazy(node, start, end);
        return;
    }
    update_range(node * 2, start, (start + end) / 2, left, right, val);
    update_range(node * 2 + 1, (start + end) / 2 + 1, end, left, right, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int node, int start, int end, int idx) {
    update_lazy(node, start, end);
    if (start > idx || idx > end)
        return 0LL;
    if (start == end)
        return tree[node];
    return query(node * 2, start, (start + end) / 2, idx) +
           query(node * 2 + 1, (start + end) / 2 + 1, end, idx);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        if (p == -1)
            continue;
        g[p].push_back(i);
    }
    dfs(1, -1);
    while (q--) {
        int idx, val;
        cin >> idx >> val;
        update_range(1, 1, n, s[idx], e[idx], val);
    }
    for (int i = 1; i <= n; i++) {
        cout << query(1, 1, n, s[i]) << ' ';
    }
}