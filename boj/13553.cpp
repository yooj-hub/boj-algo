#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 220202
using namespace std;

int sq = 400;
struct Query {
    int idx, s, e;
    bool operator<(Query &other) {
        if (s / sq != other.s / sq)
            return s < other.s;
        return e < other.e;
    }
};
int n, q, k;
ll arr[110101];
ll tree[MX + 1];
ll ans[110101];
ll res = 0;


void update(int idx, ll diff) {
    while (idx <= MX) {
        tree[idx] += diff;
        idx += idx & (-idx);
    }
}
ll sum(int idx) {
    ll ret = 0LL;
    if(idx<1) return 0;
    if(idx>100000) idx = 100000;
    while (idx) {
        ret += tree[idx];
        idx -= idx & (-idx);
    }
    return ret;
}
ll query(int left, int right) { return sum(right) - sum(left - 1); }

vector<Query> queries;

void Plus(int idx) {
    int left, right;
    left = arr[idx] - k;
    right = arr[idx] + k;
    res += query(left, right);
    update(arr[idx], 1);
}

void Minus(int idx) {
    int left, right;
    left = arr[idx] - k;
    right = arr[idx] + k;
    update(arr[idx], -1);
    res -= query(left, right);
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }


    cin >> q;
    for (int i = 0; i < q; i++) {
        int s, e;
        cin >> s >> e;
        queries.push_back({i, s, e});
    }
    sort(all(queries));

    int s = queries[0].s;
    int e = queries[0].e;
    for (int i = s; i <= e; i++) {
        Plus(i);
    }

    ans[queries[0].idx] = res;
    for (int i = 1; i < q; i++) {
        while (s > queries[i].s)
            Plus(--s);
        while (e < queries[i].e)
            Plus(++e);
        while (s < queries[i].s)
            Minus(s++);
        while (e > queries[i].e)
            Minus(e--);
        ans[queries[i].idx] = res;
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
}