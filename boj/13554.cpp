#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010
using namespace std;

const int sq = 400;
struct Query {
    int idx, s, e, k;
    bool operator<(Query &x) {
        if (s / sq != x.s / sq)
            return s < x.s;
        return e < x.e;
    }
};
int n, q;
ll res;
ll ans[MX];
int a[MX];
int b[MX];
vector<ll> tree_a(MX);
vector<ll> tree_b(MX);

void update(vector<ll> &tree, int idx, int diff) {
    while (idx < MX) {
        tree[idx] += diff;
        idx += idx & (-idx);
    }
}

ll sum(vector<ll> &tree, int idx) {
    ll ret = 0LL;
    while (idx) {
        ret += tree[idx];
        idx -= idx & (-idx);
    }
    return ret;
}

ll sum_query(vector<ll> &tree ,int left, int right){
    return sum(tree, right) - sum(tree, left-1);
}

ll query(int k) {
    ll ret = 0;
    int sz = sqrt(k);
    for (int i = 1; i <= sz; i++) {
        ret += sum_query(tree_a,i,i) * sum_query(tree_b, sz+1, k/i);
    }
    for(int i=1; i<=sz; i++){
        ret += sum_query(tree_a, 1, k/i) * sum_query(tree_b, i,i);
    }

    return ret;
}

vector<Query> quries;

void Plus(int idx) {
    update(tree_a, a[idx], 1);
    update(tree_b, b[idx], 1);
}

void Minus(int idx) {
    update(tree_a, a[idx], -1);
    update(tree_b, b[idx], -1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int s, e, k;
        cin >> s >> e >> k;
        quries.push_back({i, s, e, k});
    }
    sort(all(quries));
    int s, e;
    s = quries[0].s;
    e = quries[0].e;
    for (int i = s; i <= e; i++) {
        Plus(i);
    }
    ans[quries[0].idx] = query(quries[0].k);
    for (int i = 1; i < q; i++) {
        while (s > quries[i].s)
            Plus(--s);
        while (e < quries[i].e)
            Plus(++e);
        while (s < quries[i].s)
            Minus(s++);
        while (e > quries[i].e)
            Minus(e--);
        ans[quries[i].idx] = query(quries[i].k);
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
}