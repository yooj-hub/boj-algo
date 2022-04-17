#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define MX 101010
using namespace std;

vector<int> arr;
list<int> dq[MX];
const int sqrtN = 300;
const int sz = MX / sqrtN + 10;
struct Query {
    int idx, s, e;
    bool operator<(Query &x) {
        if (s / sqrtN != x.s / sqrtN)
            return s < x.s;
        return e < x.e;
    }
};

int answer[MX];
int cnt[MX];
int bucket[sz];

void pl(int x, int dir) {
    int now = 0;
    auto &tmp = dq[arr[x]];
    if (!tmp.empty()) {
        now = tmp.back() - tmp.front();
        cnt[now]--;
        bucket[now / sqrtN]--;
    }
    if (!dir)
        tmp.push_front(x);
    else
        tmp.push_back(x);
    now = tmp.back() - tmp.front();
    cnt[now]++;
    bucket[now / sqrtN]++;
}

void mi(int x, int dir) {
    auto &tmp = dq[arr[x]];
    int now = tmp.back() - tmp.front();
    cnt[now]--;
    bucket[now / sqrtN]--;
    if (!dir)
        tmp.pop_front();
    else
        tmp.pop_back();
    if (!tmp.empty()) {
        now = tmp.back() - tmp.front();
        cnt[now]++;
        bucket[now / sqrtN]++;
    }
}

int query() {
    for (int i = sz - 1; i >= 0; i--) {
        if (bucket[i] == 0)
            continue;
        for (int j = sqrtN - 1; j >= 0; j--) {
            if (cnt[i * sqrtN + j] > 0)
                return i * sqrtN + j;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    arr.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int q;
    cin >> q;
    vector<Query> queries;
    for (int i = 0; i < q; i++) {
        int s, e;
        cin >> s >> e;
        queries.push_back({i, s, e});
    }
    sort(all(queries));
    int s, e;
    s = queries[0].s;
    e = queries[0].e;

    for (int i = s; i <= e; i++) {
        pl(i, 1);
    }
    answer[queries[0].idx] = query();
    for (int i = 1; i < q; i++) {
        while (s > queries[i].s)
            pl(--s, 0);
        while (e < queries[i].e)
            pl(++e, 1);
        while (s < queries[i].s)
            mi(s++, 0);
        while (e > queries[i].e)
            mi(e--, 1);
        answer[queries[i].idx] = query();
    }
    for (int i = 0; i < q; i++) {
        cout << answer[i] << '\n';
    }
}