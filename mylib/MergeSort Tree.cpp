#include<bits/stdc++.h>

using namespace std;
int n, m;

vector<int> tree[400001];

void update(int node, int start, int end, int index, int diff) {
    if (index < start || end < index) return;
    tree[node].push_back(diff);
    if (start ^ end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index, diff);
        update(node * 2 + 1, mid + 1, end, index, diff);
    }
}

int query(int node, int start, int end, int left, int right, int k) {
    if (right < start || left > end) return 0;
    if (left <= start && end <= right) return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), k);
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right, k) + query(node * 2 + 1, mid + 1, end, left, right, k);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        update(1, 1, n, i, t);
    }
    for (int i = 0; i <= n * 4; i++) {
        sort(tree[i].begin(), tree[i].end());
    }
    cin >> m;
    while (m--) {
        int i, j, k;
        cin >> i >> j >> k;
        cout << query(1, 1, n, i, j, k) << '\n';
    }


}
