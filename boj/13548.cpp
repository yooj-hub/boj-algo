#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define MX 101010
using namespace std;

int sqrtN;
struct Query {
    int idx, s, e;

    bool operator<(Query &x) {
        if (s / sqrtN != x.s / sqrtN)
            return s < x.s;
        else
            return e < x.e;
    }
};
int cnt[MX];
int ans[MX];
int table[MX];
int v[MX];
vector<Query> query;
int res;
void pl(int x) {
    if (cnt[x] != 0)
        table[cnt[x]]--;
    cnt[x]++;
    table[cnt[x]]++;
    res = max(res, cnt[x]);
}

void mi(int x) {
    table[cnt[x]]--;
    if (cnt[x] == res && !table[cnt[x]])
        res--;
    cnt[x]--;
    table[cnt[x]]++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    sqrtN = sqrt(n);
    
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int st, en;
        cin >> st >> en;
        query.push_back({i, st, en});
    }

    sort(all(query));

    int s = 0;
    int e = 0;
    res=0;

    for (int i = 0; i < m; i++) {
        while (s < query[i].s)
            mi(v[s++]);
        while (s > query[i].s)
            pl(v[--s]);
        while (e < query[i].e)
            pl(v[++e]);
        while (e > query[i].e)
            mi(v[e--]);
        ans[query[i].idx] = res;
    }
    for (int i = 0; i < m; i++) {
        cout << ans[i] << '\n';
    }
}