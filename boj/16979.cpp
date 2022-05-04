#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010
using namespace std;
const int sq = 400;
struct Query {
    int idx, s, e;
    bool operator<(Query &other) {
        if (s / sq != other.s / sq)
            return s < other.s;
        return e < other.e;
    }
};

int n, q;
int arr[MX];
int tree[MX];
vector<Query> queris;
vector<int> tmp;
ll ans[MX];
void update(int idx, int diff) {
    while (idx < MX) {
        tree[idx] += diff;
        idx += idx & (-idx);
    }
}

ll sum(int idx) {
    ll ret = 0;
    while (idx) {
        ret += tree[idx];
        idx -= idx & (-idx);
    }
    return ret;
}

ll sum_query(int left, int right) { return sum(right) - sum(left - 1); }
ll res = 0LL;
void plus_right(int idx) {
    res += sum_query(arr[idx] + 1, MX - 1);
    update(arr[idx], 1);
}
void plus_left(int idx) {
    res += sum_query(1, arr[idx] - 1);
    update(arr[idx], 1);
}
void minus_right(int idx) {
    update(arr[idx], -1);
    res -= sum_query(arr[idx] + 1, MX - 1);
}
void minus_left(int idx) {
    update(arr[idx], -1);
    res -= sum_query(1, arr[idx] - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        tmp.push_back(arr[i]);
    }
    sort(all(tmp));
    for (int i = 1; i <= n; i++) {
        arr[i] = (lower_bound(all(tmp), arr[i]) - tmp.begin()) + 1;
    }
    for (int i = 0; i < q; i++) {
        int s, e;
        cin >> s >> e;
        queris.push_back({i, s, e});
    }
    sort(all(queris));
    int s = queris[0].s;
    int e = queris[0].e;
    for (int i = s; i <= e; i++) {
        plus_right(i);
    }
    ans[queris[0].idx] = res;
    for (int i = 1; i < q; i++) {
        while (s > queris[i].s)
            plus_left(--s);

        while (e < queris[i].e)
            plus_right(++e);

        while (s < queris[i].s)
            minus_left(s++);

        while (e > queris[i].e)
            minus_right(e--);

        ans[queris[i].idx] = res;
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
}