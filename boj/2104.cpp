#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
ll arr[MX];
ll s[MX];
int min_idx_tree[MX * 4];
int n;

int arg_min(int a, int b) {
    if (a == -1)
        return b;
    if (b == -1)
        return a;
    if (a > b)
        swap(a, b);
    return (arr[a] > arr[b]) ? b : a;
}

void init_min_tree(int node, int start, int end) {
    if (start == end) {
        min_idx_tree[node] = start;
        return;
    }
    init_min_tree(node * 2, start, (start + end) / 2);
    init_min_tree(node * 2 + 1, (start + end) / 2 + 1, end);
    min_idx_tree[node] =
        arg_min(min_idx_tree[node * 2], min_idx_tree[node * 2 + 1]);
}

int query(int node, int start, int end, int left, int right) {
    if (start > right || end < left)
        return -1;
    if (left <= start && end <= right) {
        return min_idx_tree[node];
    }

    int left_result = query(node * 2, start, (start + end) / 2, left, right);
    int right_result =
        query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    return arg_min(left_result, right_result);
}

ll solve(int left, int right) {
    if (left > right)
        return -1;
    if (!(1 <= left && left <= n))
        return -1;
    if (!(1 <= right && right <= n))
        return -1;
    if (left == right)
        return arr[left] * arr[left];
    int min_idx = query(1, 1, n, left, right);
    ll left_result = solve(left, min_idx - 1);
    ll right_result = solve(min_idx + 1, right);
    return max(
        {left_result, right_result, arr[min_idx] * (s[right] - s[left - 1])});
}

void input_init() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        s[i] = s[i - 1] + arr[i];
    }
    init_min_tree(1, 1, n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    input_init();
    cout << solve(1, n);
}