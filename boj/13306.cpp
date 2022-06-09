#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 201010

using namespace std;

struct Query {
    int x, f, t;
};

int n, q;
int parent[MX];
int sv[MX];
vector<Query> queries;
vector<pair<int, int>> edges;
int find_parent(int x) {
    if (x == parent[x])
        return x;
    return parent[x] = find_parent(parent[x]);
}

void union_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if (a != b)
        parent[a] = b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    for (int i = 2; i <= n; i++) {
        int t;
        cin >> t;
        sv[i] = t;
    }
    for (int i = 0; i < n - 1 + q; i++) {
        int x, f, t;
        cin >> x;
        if (x == 0) {
            cin >> f;
            queries.push_back({x, f, -1});
        } else {
            cin >> f >> t;
            queries.push_back({x, f, t});
        }
    }
    reverse(all(queries));
    vector<string> answer;
    for (auto cur : queries) {
        if (cur.x == 0) {
            union_parent(cur.f, sv[cur.f]);
        } else {
            if (find_parent(cur.f) == find_parent(cur.t)) {
                answer.push_back("YES\n");
            } else {
                answer.push_back("NO\n");
            }
        }
    }
    reverse(all(answer));
    for (auto s : answer)
        cout << s;
}