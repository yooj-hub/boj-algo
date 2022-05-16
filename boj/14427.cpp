#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

int arr[MX];
int tree[MX * 4];
int n, m;
int get_min_index(int x, int y) {
    if (arr[x] == arr[y]) {
        return min(x, y);
    } else if (arr[x] < arr[y]) {
        return x;
    } else {
        return y;
    }
}

void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = start;
        return;
    }
    int mid = (start + end) / 2;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);
    tree[node] = get_min_index(tree[node * 2], tree[node * 2 + 1]);
}

int update(int node, int start, int end, int idx) {
    if (idx < start || idx > end)
        return tree[node];
    if (start == end)
        return tree[node];

    return tree[node] = get_min_index(
               update(node * 2, start, (start + end) / 2, idx),
               update(node * 2 + 1, (start + end) / 2 + 1, end, idx));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    init(1, 1, n);

    cin >> m;
    while (m--) {
        int op;
        cin >> op;
        if (op == 2) {
            cout << tree[1] << '\n';
        } else {
            int idx, val;
            cin >> idx >> val;
            arr[idx] = val;
            update(1, 1, n, idx);
        }
    }
}