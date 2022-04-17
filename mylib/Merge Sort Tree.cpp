#include<bits/stdc++.h>

using namespace std;
int n, arr[101010];
vector<int> tree[1 << 18];
const int sz = 1 << 17;

void add(int x, int v) {
    x |= sz;
    tree[x].push_back(v);
}

void build() {
    for (int i = 1; i <= n; i++) add(i, arr[i]);
    for (int i = sz - 1; i; i--) {
        tree[i].resize(tree[i * 2].size() + tree[i * 2 + 1].size());
        merge(tree[i * 2].begin(), tree[i * 2].end(), tree[i * 2 + 1].begin(), tree[i * 2 + 1].end(), tree[i].begin());
    }
}

int query(int l, int r, int k) {
    l |= sz, r |= sz;
    int ret = 0;
    while (l <= r) {
        if (l & 1) {
            ret += tree[l].end() - upper_bound(tree[l].begin(), tree[l].end(), k);
            l++;
        }
        if (~r & 1) {
            ret += tree[r].end() - upper_bound(tree[r].begin(), tree[r].end(), k);
            r--;
        }
        l >>= 1, r >>= 1;
    }
    return ret;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int m;
    build();
    cin >> m;
    for (int i = 0; i < m; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << query(l, r, k) << '\n';
    }
    return 0;
}
