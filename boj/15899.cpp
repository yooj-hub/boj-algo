#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 202020

using namespace std;
int co[MX];
int arr[MX];
vector<int> tree[MX * 4];
vector<int> g[MX];
int counter;
const int mod = 1e9 + 7;
int in[MX];
int out[MX];

void dfs(int current, int parent) {
    in[current] = ++counter;
    arr[counter] = co[current];
    for (auto nxt : g[current]) {
        if (nxt == parent)
            continue;
        dfs(nxt, current);
    }
    out[current] = counter;
}

void init(int node, int start, int end) {
    if (start == end) {
        tree[node].push_back(arr[start]);
        return;
    }
    init(node * 2, start, (start + end) / 2);
    init(node * 2 + 1, (start + end) / 2 + 1, end);
    tree[node].resize(tree[node * 2].size() + tree[node * 2 + 1].size());
    merge(all(tree[node * 2]), all(tree[node * 2 + 1]), tree[node].begin());
}

int query(int node, int start, int end, int left, int right, int val) {
    if (start > right || left > end)
        return 0;
    if (left <= start && end <= right) {
        return tree[node].size() -
               (tree[node].end() - upper_bound(all(tree[node]), val));
    }
    return query(node * 2, start, (start + end) / 2, left, right, val) +
           query(node * 2 + 1, (start + end) / 2 + 1, end, left, right, val);
}

int n, m, c;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++) {
        cin >> co[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int from, to;
        cin >> from >> to;
        g[from].push_back(to);
        g[to].push_back(from);
    }
    dfs(1, -1);

    init(1, 1, n);

    ll ans = 0;
    while (m--) {
        int a, b;
        cin >> a >> b;
        ans = (ans + query(1, 1, n, in[a], out[a], b) % mod) % mod;
    }
    cout << ans;
}