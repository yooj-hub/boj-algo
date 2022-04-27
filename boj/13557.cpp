#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;

int n, q, x1, y1, x2, y2, l, r;
ll ret;

ll tree[2 << 18];
ll tree2[2 << 18];
ll s[2 << 17];
ll arr[2 << 17];

ll init(int node, int start, int end) {
    if (start == end) {
        return tree[node] = arr[start];
    }
    int mid = (start + end) / 2;
    return tree[node] = init(node * 2, start, (start + end) / 2) +
                        init(node * 2 + 1, (start + end) / 2 + 1, end);
    ;
}

ll init2(int node, int start, int end) {
    if (start == end) {
        return tree2[node] = arr[start];
    }
    ll left = init(node * 2, start, (start + end) / 2);
    ll right = init(node * 2 + 1, (start + end) / 2 + 1, end);
    return tree2[node] = max(left, left + right);
}

ll query1(int node, int start, int end, int left, int right) {
    if (start > right || left > end)
        return 0LL;
    if (left <= start && end <= right) {
        return tree1[node];
    }
    return query1(node * 2, start, (start + end) / 2, left, right) +
           query1(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

ll query2(int node, int start, int end, int left, int right) {
    if (start > right || left > end)
        return 0LL;
    if (left <= start && end <= right) {
        return tree2[node];
    }
    return query2(node * 2, start, (start + end) / 2, left, right) +
           query2(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        s[i] = s[i - 1] + a[i];
    }
    cin >> q;
    while (q--) {
        cin >> x1 >> y1 >> x2 >> y2;
    }
}