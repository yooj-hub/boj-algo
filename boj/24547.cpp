#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
using namespace std;
int n, q, cmd, target, x;
const int sn = 400;
const int sz = 1 << 17;
ll total = 0LL;
ll diff = 0LL;
vector<ll> tree[sz * 2];

ll tree2[sz * 2];
ll arr[sz];
ll bucket[401];
ll bucket2[401];
void bucket_init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sn; j++) {
            bucket[j] += j * (arr[i] / j);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (arr[i] <= sn)
            for (int j = 1; j <= sn; j++) {
                bucket2[arr[i]] += (j / arr[i]) * arr[i];
            }
    }
}

void init(int node, int start, int end) {
    if (start == end) {
        tree2[node] = bucket2[start];
        return;
    }
    int mid = (start + end) / 2;
    init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end);
    tree2[node] = tree2[node * 2] + tree2[node * 2 + 1];
}

void bucket_update(int prev, int value) {
    for (int j = 1; j <= sn; j++) {
        bucket[j] -= j * (prev / j);
    }
    for (int j = 1; j <= sn; j++) {
        bucket[j] += j * (value / j);
    }
    if (prev <= sn)
        for (int j = 1; j <= sn; j++) {
            bucket2[prev] -= prev * (j / prev);
        }
    if (value <= sn)
        for (int j = 1; j <= sn; j++) {
            bucket2[value] += value * (j / value);
        }
}

void add(int node, int idx, int start, int end, int val) {
    if (start > idx || end < idx)
        return;
    tree[node].push_back(val);
    if (start != end) {
        add(node * 2, idx, start, (start + end) / 2, val);
        add(node * 2 + 1, idx, (start + end) / 2 + 1, end, val);
    }
}

void update(int node, int start, int end, int idx, int prev, int value) {
    if (idx < start || idx > end)
        return;
    if (start == idx && end == idx) {
        tree[node].erase(
            tree[node].begin() +
            (lower_bound(all(tree[node]), prev) - tree[node].begin()));
        tree[node].insert(
            tree[node].begin() +
                (lower_bound(all(tree[node]), value) - tree[node].begin()),
            value);
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, idx, prev, value);
    update(node * 2 + 1, mid + 1, end, idx, prev, value);
    tree[node].erase(tree[node].begin() +
                     (lower_bound(all(tree[node]), prev) - tree[node].begin()));
    tree[node].insert(
        tree[node].begin() +
            (lower_bound(all(tree[node]), value) - tree[node].begin()),
        value);
}

ll query(int node, ll x) {
    ll ret = 0LL;
    for (int i = 1; i < 400; i++) {
        ll start = lower_bound(all(tree[node]), x * i) - tree[node].begin();
        ll end = lower_bound(all(tree[node]), x * (i + 1)) - tree[node].begin();
        ret += (end - start) * x;
    }
    return ret;
}

ll query2(int node, ll x) {
    
    ll ret = 0LL;
    ll start = upper_bound(all(tree[node]), 400) - tree[node].begin();
    for (int i = 0; i < start; i++) {
        ret += bucket2[tree[node][i]];
    }
    for (int i = 1; i < 400; i++) {
        start = lower_bound(all(tree[node]), 400*i) - tree[node].begin();
        ll end = lower_bound(all(tree[node]), 400*(i+1)) - tree[node].begin();
        ret += (end - start) * arr[i];
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        total += arr[i];
        add(1, i, 1, n, arr[i]);
    }
    bucket_init();
    for (int i = 0; i < sz * 2; i++) {
        sort(all(tree[i]));
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> cmd;
        if (cmd == 1) {
            cin >> x;
            if (x <= sn)
                cout << total - bucket[x] << '\n';
            else {
                cout << total - query(1, x) << '\n';
            }
        } else if (cmd == 2) {
            cin >> x;
            cout << n * x - bucket2[x] << '\n';

        } else {
            cin >> target >> x;
            bucket_update(arr[target], x);
            update(1, 1, n, target, arr[target], x);
            ll diff = x - arr[target];
            arr[target] = x;
            total += diff;
        }
    }
    return 0;
}
