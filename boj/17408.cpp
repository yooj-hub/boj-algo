#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 110101

using namespace std;

int arr[MX];
int tree[MX * 4];

void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = start;
        return;
    }
    init(node * 2, start, (start + end) / 2);
    init(node * 2 + 1, (start + end) / 2 + 1, end);
    if (arr[tree[node * 2]] > arr[tree[node * 2 + 1]]) {
        tree[node] = tree[node * 2];
    } else {
        tree[node] = tree[node * 2 + 1];
    }
}

void update(int node, int start, int end, int idx, int val) {
    if (idx > end || idx < start)
        return;
    if (start != end) {
        update(node * 2, start, (start + end) / 2, idx, val);
        update(node * 2 + 1, (start + end) / 2 + 1, end, idx, val);
        if (arr[tree[node * 2]] > arr[tree[node * 2 + 1]]) {
            tree[node] = tree[node * 2];
        } else {
            tree[node] = tree[node * 2 + 1];
        }
    }
}

int query(int node, int start, int end, int left, int right) {
    if (left > end || start > right)
        return -1;
    if (left <= start && end <= right)
        return tree[node];
    int left_result = query(node * 2, start, (start + end) / 2, left, right);
    int right_result =
        query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);

    if (left_result == -1)
        return right_result;
    else if (right_result == -1)
        return left_result;
    else {
        if (arr[left_result] > arr[right_result])
            return left_result;
        else
            return right_result;
    }
}
int n, q, kind;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    init(1, 1, n);
    cin >> q;
    while (q--) {
        cin >> kind;
        if (kind == 1) {
            int i, v;
            cin >> i >> v;
            arr[i] = v;
            update(1, 1, n, i, v);

        } else {
            int l, r;
            cin >> l >> r;
            int k = query(1, 1, n, l, r);
            int left_result = arr[query(1, 1, n, l, k - 1)];
            int right_result = arr[query(1, 1, n, k + 1, r)];
            cout << arr[k] + max(left_result, right_result) << '\n';
        }
    }
}