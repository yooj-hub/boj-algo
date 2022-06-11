#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

struct Query {
    int x, s;
};
int n, q,t;
vector<int> answer;
vector<Query> quries;
vector<int> tree;
int parent[MX];
unordered_set<int> color_set[MX];


int find_parent(int x) {
    if (x == parent[x])
        return x;
    return parent[x] = find_parent(parent[x]);
}

void union_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if (a == b)
        return;
    if (color_set[a].size() > color_set[b].size())
        swap(a, b);
    parent[a] = b;
    color_set[b].insert(color_set[a].begin(), color_set[a].end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> q;
    tree.resize(n + 1);
    for (int i = 1; i < n; i++) {
        cin >> t;
        tree[i + 1] = t;
    }
    for (int i = 1; i <= n; i++) {
        cin >> t;
        parent[i] = i;
        color_set[i].insert(t);
    }

    for (int i = 0; i < q + n - 1; i++) {
        int a, b;
        cin >> a >> b;
        quries.push_back({a, b});
    }
    for (int i = 1; i <= n; i++) {

    }

    reverse(all(quries));
    for (Query que : quries) {
        if (que.x == 1) {
            union_parent(que.s, tree[que.s]);
        } else {
            answer.push_back(color_set[find_parent(que.s)].size());
        }
    }
    reverse(all(answer));
    for (auto x : answer) {
        cout << x << '\n';
    }
}