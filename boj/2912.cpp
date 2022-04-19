#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 303030
using namespace std;
int n, c;
int arr[MX];
int cnt[10101];
int answer[10101];
const int sn = 111;
const int sz = 10101 / sn + 1;
int bucket[sz];
struct Query {
    int idx, s, e;
    bool operator<(Query &x) {
        if (s / sn != x.s / sn)
            return s < x.s;
        return e < x.e;
    }
};
vector<Query> query;
void Plus(int x) {
    if (bucket[arr[x] / sn] != 0)
        bucket[arr[x] / sn]--;
    cnt[arr[x]]++;
    bucket[arr[x] / sn]++;
}

void Minus(int x) {
    bucket[arr[x] / sn]--;
    cnt[arr[x]]--;
    bucket[arr[x] / sn]++;
}

int solve(int x) {
    for (int i = sz - 1; i >= 0; i--) {
        if (bucket[i] == 0)
            continue;
        for (int j = sn - 1; j >= 0; j--) {
            if (cnt[i * sn + j] * 2 > x)
                return i * sn + j;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int s, e;
        cin >> s >> e;
        query.push_back({i, s, e});
    }
    sort(all(query));
    int s = query[0].s;
    int e = query[0].e;

    for (int i = s; i <= e; i++) {
        Plus(i);
    }
    answer[query[0].idx] = solve(e - s + 1);
    for (int i = 1; i < q; i++) {
        while (s > query[i].s)
            Plus(--s);
        while (e < query[i].e)
            Plus(++e);
        while (s < query[i].s)
            Minus(s++);
        while (e > query[i].e)
            Minus(e--);

        answer[query[i].idx] = solve(e - s + 1);
    }
    for (int i = 0; i < q; i++) {
        if (answer[i] == -1) {
            cout << "no\n";
        } else {
            cout << "yes " << answer[i] << '\n';
        }
    }
}