#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 110101

using namespace std;
int arr[MX];
const int sq = 340;
const int sz = (1000001) / sq + 1;
int bucket[sz];
int ans[MX];
list<int> pos[1000001];
int cnt[1000001];
int n, q, k;

struct Query {
    int idx, s, e;
    bool operator<(Query &other) {
        if (s / sq != other.s / sq)
            return s < other.s;
        return e < other.e;
    }
};
vector<Query> queries;

int query() {
    for (int i = sz - 1; i >= 0; i--) {
        if (bucket[i] == 0)
            continue;
        for (int j = sq - 1; j >= 0; j--) {
            if (cnt[i * sq + j] > 0)
                return i * sq + j;
        }
    }
    return 0;
}

void Plus(int idx, int dir) {
    list<int> &current = pos[arr[idx]];
    int now;
    if (!current.empty()) {
        now = current.back() - current.front();
        cnt[now]--;
        bucket[now / sq]--;
    }
    if (dir)
        current.push_back(idx);
    else
        current.push_front(idx);
    now = current.back() - current.front();
    cnt[now]++;
    bucket[now / sq]++;
}

void Minus(int idx, int dir) {
    list<int> &current = pos[arr[idx]];
    int now = current.back() - current.front();
    cnt[now]--;
    bucket[now / sq]--;
    if (dir)
        current.pop_back();
    else
        current.pop_front();
    if (!current.empty()) {
        now = current.back() - current.front();
        cnt[now]++;
        bucket[now / sq]++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] = ((arr[i] % k) + arr[i - 1]) % k;
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int s, e;
        cin >> s >> e;
        queries.push_back({i, s - 1, e});
    }
    sort(all(queries));
    int s = queries[0].s;
    int e = queries[0].e;
    for (int i = s; i <= e; i++) {
        Plus(i, 1);
    }
    ans[queries[0].idx] = query();

    for (int i = 1; i < q; i++) {
        while (s > queries[i].s)
            Plus(--s, 0);
        while (e < queries[i].e)
            Plus(++e, 1);
        while (s < queries[i].s)
            Minus(s++, 0);
        while (e > queries[i].e)
            Minus(e--, 1);
        ans[queries[i].idx] = query();
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
}