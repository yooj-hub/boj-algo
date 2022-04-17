
#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;

int sqrtN;

struct Query {
    int idx, s, e;
    bool operator<(Query &x) {
        if (s / sqrtN != x.s / sqrtN)
            return s < x.s;
        return e < x.e;
    }
};

vector<Query> query;
vector<int> v;
int res = 0;
int ans[100001];
int cnt[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n;
    sqrtN = sqrt(n);
    v.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        query.push_back({i, s, e});
    }
    sort(all(query));
    int s = query[0].s;
    int e = query[0].e;
    for (int i = s; i <= e; i++) {
        if(cnt[v[i]]==0) res++;
        cnt[v[i]]++;
    }
    ans[query[0].idx] = res;
    for (int i = 1; i < m; i++) {
        while (s < query[i].s) {
            cnt[v[s]]--;
            if (cnt[v[s]] == 0)
                res--;
            s++;
        }
        while (s > query[i].s) {
            s -= 1;
            if (cnt[v[s]]==0) {
                res += 1;
            }
            cnt[v[s]]++;
        }
        while (e < query[i].e) {
            e += 1;
            if (cnt[v[e]] == 0) {
                res += 1;
            }
            cnt[v[e]]++;
        }
        while (e > query[i].e) {
            cnt[v[e]]--;
            if (cnt[v[e]] == 0)
                res--;
            e--;
        }
        ans[query[i].idx] = res;
    }
    for(int i=0; i<m;i++){
        cout << ans[i] <<'\n';
    }
}
