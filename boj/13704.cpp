#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010
using namespace std;

const int sn = 300;

struct Query {
    int idx, s, e;

    bool operator<(Query &x) {
        if (s / sn != x.s / sn)
            return s < x.s;
        return e < x.e;
    }
};

ll arr[MX];
ll cnt[3000000];
ll answer[MX];

ll res;
int s, e;
int n, k;
void Plus_l(int x) {
    cnt[arr[x]]++;
    res += cnt[k ^ arr[x - 1]];
}
void Plus_r(int x) {
    res += cnt[k ^ arr[x]];
    if ((k ^ arr[x]) == arr[s - 1]) {
        res++;
    }
    cnt[arr[x]]++;
}

void Minus_l(int x) {
    res -= cnt[k ^ arr[x - 1]];
    cnt[arr[x]]--;
}

void Minus_r(int x) {
    res -= cnt[k ^ arr[x]];
    if (arr[s - 1] == (k ^ arr[x]))
        res--;
    cnt[arr[x]]--;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
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
    e = quries[0].s;
    cnt[arr[s]]=1;
    if ((arr[s] ^ arr[s - 1]) == k)
        res++;
    while(e < quries[0].e)Plus_r(++e);
    answer[quries[0].idx] = res;
    for (int i = 1; i < q; i++) {
        while (s > quries[i].s)
            Plus_l(--s);
        while (e < quries[i].e)
            Plus_r(++e);
        while (s < quries[i].s)
            Minus_l(s++);
        while (e > quries[i].e)
            Minus_r(e--);
        answer[quries[i].idx] = res;
    }
    for (int i = 0; i < q; i++) {
        cout << answer[i] << '\n';
    }
}