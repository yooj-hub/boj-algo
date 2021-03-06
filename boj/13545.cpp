#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010
using namespace std;
const int sn = 400;
const int sz = (MX*2) / 400 + 1;
int arr[MX];
int bucket[sz];
int cnt[MX * 2];
int ans[MX];
int n, q;

struct Query {
    int idx, s, e;
    bool operator<(Query &x) {
        if (s / sn != x.s / sn)
            return s < x.s;
        return e < x.e;
    }
};
vector<Query> queries;
list<int> dq[MX * 2];

void Plus(int idx, int dir) {
    int now;
    list<int> &current = dq[arr[idx]];
    if (!current.empty()) {
        now = current.back() - current.front();
        cnt[now]--;
        bucket[now / sn]--;
    }
    if (dir) {
        current.push_back(idx);
    } else {
        current.push_front(idx);
    }
    now = current.back() - current.front();
    cnt[now]++;
    bucket[now / sn]++;
}

void Minus(int idx, int dir) {
    int now;
    list<int> &current = dq[arr[idx]];
    now = current.back() - current.front();
    cnt[now]--;
    bucket[now / sn]--;

    if (dir) {
        current.pop_back();
    } else {
        current.pop_front();
    }
    if (!current.empty()) {
        now = current.back() - current.front();
        cnt[now]++;
        bucket[now / sn]++;
    }
}

int qurey() {
    for (int i = sz - 1; i >= 0; i--) {
        if (bucket[i] == 0)
            continue;
        for (int j = sn - 1; j >= 0; j--) {
            if (cnt[j + i * sn] > 0) {
                return j + i * sn;
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    for (int i = 0; i <= n; i++) {
        arr[i] += MX;
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int s, e;
        cin >> s >> e;
        queries.push_back({i, s-1, e});
    }
    sort(all(queries));
    int s = queries[0].s;
    int e = queries[0].e;
    for (int i = s; i <= e; i++) {
        Plus(i, 1);
    }
    ans[queries[0].idx] = qurey();
    for (int i = 1; i < q; i++) {
        while (s > queries[i].s)
            Plus(--s, 0);
        while (e < queries[i].e)
            Plus(++e, 1);
        while (s < queries[i].s)
            Minus(s++, 0);
        while (e > queries[i].e)
            Minus(e--, 1);
        ans[queries[i].idx] = qurey();
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
}