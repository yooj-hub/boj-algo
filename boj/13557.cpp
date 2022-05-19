#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

ll lefttree[MX * 4];
ll righttree[MX * 4];
ll sum_max_tree[MX * 4];
ll s[MX];
int arr[MX];
ll tot;
int n, m;
// left_tree
int argmin(int a, int b) {
    if (a == -1)
        return b;
    if (b == -1)
        return a;
    if (a > b)
        swap(a, b);
    return (s[a] > s[b]) ? b : a;
}

int argmax(int a, int b) {
    if (a == -1)
        return b;
    if (b == -1)
        return a;
    if (a > b)
        swap(a, b);
    return (s[a] < s[b]) ? b : a;
}

ll init3(int node, int start, int end) {
    if (start == end)
        return sum_max_tree[node] = s[start];
    return sum_max_tree[node] =
               max(init3(node * 2, start, (start + end) / 2),
                   init3(node * 2 + 1, (start + end) / 2 + 1, end));
}

ll query3(int node, int start, int end, int left, int right) {
    if (start > right || end < left)
        return -2e18;
    if (left <= start && end <= right)
        return sum_max_tree[node];
    return max(query3(node * 2, start, (start + end) / 2, left, right),
               query3(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int init(int node, int start, int end) {
    if (start == end)
        return lefttree[node] = start;
    int mid = (start + end) >> 1;
    return lefttree[node] = argmin(init(node * 2, start, mid),
                                   init(node * 2 + 1, mid + 1, end));
}

int query(int node, int start, int end, int left, int right) {
    if (left > end || right < start)
        return -1;
    if (left <= start && end <= right)
        return lefttree[node];
    int left_result = query(node * 2, start, (start + end) / 2, left, right);
    int right_result =
        query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    return argmin(left_result, right_result);
}

int init2(int node, int start, int end) {
    if (start == end)
        return righttree[node] = start;
    int mid = (start + end) >> 1;
    return righttree[node] = argmax(init2(node * 2, start, mid),
                                    init2(node * 2 + 1, mid + 1, end));
}

int query2(int node, int start, int end, int left, int right) {
    if (left > end || right < start)
        return -1;
    if (left <= start && end <= right)
        return righttree[node];
    int left_result = query2(node * 2, start, (start + end) / 2, left, right);
    int right_result =
        query2(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    return argmax(left_result, right_result);
}

void init() {
    init(1, 0, n);
    init2(1, 0, n);
    init3(1, 1, n);
}

ll solve(int x1, int y1, int x2, int y2) {

    ll cs1, cs2, cs3;
    cs1 = s[query2(1, 0, n, y1, y2)] - s[query(1, 0, n, x1 - 1, min(y1, x2) - 1)];
    cs2 = s[query2(1, 0, n, max(x2, y1), y2)] - s[query(1, 0, n, x1 - 1, x2 - 1)];
    cs3 = query3(1, 1, n, y1, x2);
    cout << cs1 <<cs2<<cs3<<endl;
    return max({cs1, cs2, cs3});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        s[i] = s[i - 1] + arr[i];
    }
    init();
    cin >> m;
    while (m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << solve(x1, y1, x2, y2) << '\n';
    }
}