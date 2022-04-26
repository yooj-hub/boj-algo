#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010
using namespace std;

ll arr[MX];
ll tree[MX * 4];
int n;

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
    else
        tree[node] = tree[node * 2 + 1];
}

int query(int node, int start, int end, int left, int right) {
    if (start > right || left > end)
        return -1;
    if (left <= start && end <= right)
        return tree[node];
    int left_result = query(node * 2, start, (start + end) / 2, left, right);
    int right_result =
        query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    if (left_result == -1)
        return right_result;
    if (right_result == -1)
        return left_result;
    if (arr[left_result] < arr[right_result])
        return left_result;
    else
        return right_result;
}

ll get_answer(int start, int end) {
    int idx = query(1, 1, n, start, end);
    ll answer = (ll)(end - start + 1) * (arr[idx]);
    if (start <= idx - 1) {
        ll left_result = get_answer(start, idx - 1);
        answer = max(answer, left_result);
    }

    if (end >= idx + 1) {
        ll right_result = get_answer(idx + 1, end);
        answer = max(answer, right_result);
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    init(1, 1, n);
    cout << get_answer(1, n) << '\n';
}