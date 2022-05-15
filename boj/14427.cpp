#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int n;
int arr[MX];
int tree[MX];
void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = start;
        return;
    }
    int mid = (start + end) / 2;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);
    if (arr[tree[node * 2]] < arr[tree[node * 2 + 1]])
        tree[node] = tree[node * 2];
    else if (arr[tree[node * 2]] == arr[tree[node * 2 + 1]])
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    else
        tree[node] = tree[node * 2 + 1];
}

int update(int node, int start, int end, int idx, int val) {
    if (idx < start || idx > end)
        return tree[node];
    if (start == end)
        return tree[start];
    if (arr[tree[node]] >= val)
        tree[node] = min(idx, tree[node]);
    int left_result = update(node * 2, start, (start + end) / 2, idx, val);
    int right_result =
        update(node * 2 + 1, (start + end) / 2 + 1, end, idx, val);
    if (arr[left_result] > arr[right_result])
        return right_result;
    else if (arr[left_result] == arr[right_result])
        return min(left_result, right_result);
    return left_result;
}

int query(int node, int start, int end, int left, int right) {
    if (left > end || start > right)
        return -1;
    if (left <= start && end <= right) {
        return tree[node];
    }
    int left_result = query(node * 2, start, (start + end) / 2, left, right);
    int right_result =
        query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    if (left_result == -1)
        return right_result;
    if (right_result == -1)
        return left_result;
    if (arr[left_result] > arr[right_result])
        return right_result;
    else if (arr[left_result] == arr[right_result])
        return min(left_result, right_result);
    return left_result;
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

    int q;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int idx;
            int val;
            cin >> idx >> val;
            arr[idx] = val;
            update(1, 1, n, idx, val);

        } else {
            cout << tree[1] << '\n';
        }
    }
}