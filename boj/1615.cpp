#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;

int n, m;

int tree[8080];
void update(int node, int start,int end, int idx) {
    if(start > idx || end < idx) return;
    tree[node]++;
    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, idx);
        update(node * 2 + 1, mid + 1, end, idx);
    }
}

int query(int node, int start, int end, int left, int right) {
    if (start > right || left > end)
        return 0;
    if (left <= start && end <= right) {
        return tree[node];
    }
    return query(node * 2, start, (start + end) / 2, left, right) +
           query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
vector<pair<int, int>> g;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g.push_back({a, b});
    }
    sort(all(g));
    for (auto &x : g) {
        int from, to;
        tie(from, to) = x;
        ans += query(1, 1, n, to + 1, n);
        update(1, 1, n, to);
    }
    cout << ans << '\n';
}