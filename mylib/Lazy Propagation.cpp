#include<bits/stdc++.h>

#define ll long long int

using namespace std;
typedef vector<ll> vll;

ll init(vll &arr, vll &tree, int node, int start, int end) {
    if (start == end) {
        return tree[node] = arr[start];
    }
    return tree[node] = init(arr, tree, node * 2, start, (start + end) / 2) +
                        init(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}

void update_lazy(vll &tree, vll &lazy, int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update_range(vll &tree, vll &lazy, int node, int start, int end, int left, int right, ll diff) {
    update_lazy(tree, lazy, node, start, end);
    if (left > end || right < start) return;
    if (left <= start && end <= right) {
        tree[node] += (end - start + 1) * diff;
        if (start != end) {
            lazy[node * 2] += diff;
            lazy[node * 2 + 1] += diff;
        }
        return;
    }
    update_range(tree, lazy, node * 2, start, (start + end) / 2, left, right, diff);
    update_range(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];

}

ll sum(vll &tree, vll &lazy, int node, int start, int end, int left, int right) {
    update_lazy(tree, lazy, node, start, end);
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    return sum(tree, lazy, node * 2, start, (start + end) / 2, left, right) +
           sum(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vll arr(n + 1);
    vll tree((n + 1) * 4);
    vll lazy((n + 1) * 4);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int t = m + k;
    init(arr, tree, 1, 1, n);
    while (t--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int from, to;
            ll val;
            cin >> from >> to >> val;
            update_range(tree, lazy, 1, 1, n, from, to, val);
        } else {
            int from, to;
            cin >> from >> to;
            cout << sum(tree, lazy, 1, 1, n, from, to) << '\n';
        }
    }
}