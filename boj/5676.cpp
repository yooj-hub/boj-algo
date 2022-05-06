#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;
vector<int> arr;
vector<int> tree;
int n, k;

void init_arr() {
    arr.clear();
    arr.resize(n + 1);
    tree.clear();
    tree.resize((n + 1) * 4);
}

int init(int node, int start, int end) {
    if (start == end) {
        if (arr[start] > 0)
            tree[node] = 1;
        else if (arr[start] == 0)
            tree[node] = 0;
        else
            tree[node] = -1;
        return tree[node];
    }
    return tree[node] = init(node * 2, start, (start + end) / 2) *
                        init(node * 2 + 1, (start + end) / 2 + 1, end);
}

void update(int node, int start, int end, int idx, int diff) {
    if (idx < start || idx > end)
        return;
    if (start == end) {
        if (diff == 0)
            tree[node] = 0;
        else if (diff < 0)
            tree[node] = -1;
        else
            tree[node] = 1;
    }
    if (start != end) {
        update(node * 2, start, (start + end) / 2, idx, diff);
        update(node * 2 + 1, (start + end) / 2 + 1, end, idx, diff);
        tree[node] = tree[node * 2] * tree[node * 2 + 1];
    }
}

int query(int node, int start, int end, int left, int right) {
    if (start > right || left > end)
        return 1;
    if (left <= start && end <= right)
        return tree[node];
    return query(node * 2, start, (start + end) / 2, left, right) *
           query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

char query(int left, int right) {
    int res = query(1, 1, n, left, right);
    if (res == 0)
        return '0';
    else if (res < 0)
        return '-';
    else
        return '+';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (1) {
        cin >> n >> k;
        if (cin.eof() == true) {
            break;
        }
        init_arr();
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        init(1, 1, n);
        for (int i = 0; i < k; i++) {
            char op;
            cin >> op;
            if (op == 'C') {
                int idx, diff;
                cin >> idx >> diff;
                update(1, 1, n, idx, diff);

            } else {
                int left, right;
                cin >> left >> right;
                cout << query(left, right);
            }
        }
        cout << '\n';
    }
}