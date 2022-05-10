#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int n, t;
int b = 1;
int arr[MX];
int tree[MX * 4];

int update(int node, int start, int end, int idx, int val) {
    if (idx < start || idx > end)
        return tree[node];
    if (start == end)
        return tree[node] = val;
    return tree[node] =
               update(node * 2, start, (start + end) / 2, idx, val) +
               update(node * 2 + 1, (start + end) / 2 + 1, end, idx, val);
}

int query(int node, int start, int end, int val) {
    if (start == end)
        return start;
    if (tree[node * 2] >= val) {
        return query(node * 2, start, (start + end) / 2, val);
    } else {
        return query(node * 2 + 1, (start + end) / 2 + 1, end,
                     val - tree[node * 2]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        update(1, 1, n, i, 1);
    }
    for (int i = 1; i <= n; i++) {
        cin >> t;
        int q = query(1, 1, n, t + 1);
        arr[q] = i;
        update(1, 1, n, q, 0);
    }
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << '\n';
    }
}
