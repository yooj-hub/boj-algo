#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010
using namespace std;
int arr[MX];
int cnt[202020];
int sn;

struct Query {
    int idx, s, e;

    bool operator<(Query &x) {
        if (s / sn != x.s / sn)
            return s < x.s;
        return e < x.e;
    }
};
int s, e;
int n, k;

void Plus_r(int x) {
    res +=cnt[k ^ arr[x]];
    if ((k ^ arr[x]) == arr[s - 1]) {
        res++;
    }
    cnt[arr[x]]++;
}

void Plus_l(int x) {
    cnt[arr[x]]++;W
    res += cnt[k^arr[x-1]];

}

void Minus_r(int x) {}

void Minus_l(int x) {}
int res;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    sn = sqrt(n);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) {
        arr[i] ^= arr[i - 1];
    }

    int q;
    cin >> q;
    vector<Query> quries;
    for (int i = 0; i < q; i++) {
        int st, en;
        cin >> st >> en;
        quries.push_back({i, st, en});
    }
    sort(all(quries));
    s = quries[0].s;
    e = quries[0].e;
    cnt[arr[s]]++;
    if ((arr[s] ^= arr[s - 1]) == k)
        res++;
    for (int i = s + 1; i < e; i++) {
        Plus_r(i);
    }
}