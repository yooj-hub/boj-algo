#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 251010

using namespace std;
ll arr[MX];
ll tree[MX * 4];
ll tree2[MX * 4];
int n, k;

ll init(int node, int start, int end) {
    if (start == end)
        return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] =
               init(node * 2, start, mid) & init(node * 2 + 1, mid + 1, end);
}

void update2(int node, int start, int end, int idx, int val) {
    if (start > idx || idx > end)
        return;
    tree2[node] += val;
    if (start != end) {
        update2(node * 2, start, (start + end) / 2, idx, val);
        update2(node * 2 + 1, (start + end) / 2 + 1, end, idx, val);
    }
}

ll query(int node, int start, int end, int left, int right) {
    if (start > right || left > end)
        return 0;
    if (left <= start && end <= right)
        return tree2[node];
    return query(node * 2, start, (start + end) / 2, left, right) +
           query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(int node, int start, int end, int left, int right, ll val) {
    if (start > right || end < left)
        return;
    if (((tree[node] & val) == val))
        return;
    if (left <= start && end <= right) {
        if (start == end) {
            if (tree[node] == k)
                update2(1, 1, n, start, -1);
            tree[node] |= val;
            if (tree[node] == k)
                update2(1, 1, n, start, 1);
            return;
        }
    }
    val = val & (~tree[node]);
    update(node * 2, start, (start + end) / 2, left, right, val);
    update(node * 2 + 1, (start + end) / 2 + 1, end, left, right, val);
    tree[node] = tree[node * 2] & tree[node * 2 + 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (arr[i] == k) {
            update2(1, 1, n, i, 1);
        }
    }
    init(1, 1, n);
    int q;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 2) {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << '\n';
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            update(1, 1, n, l, r, x);
        }
    }
}