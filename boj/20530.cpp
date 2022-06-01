#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int n, q;
vector<int> g[MX * 2];
int from, to;
int in[MX * 2];
int cnt = 1;
int is_cycle[MX * 2];
int parent[MX * 2];
queue<int> que;
void go(int cur) {
    parent[cur] = cnt;
    for (auto nxt : g[cur]) {
        if (parent[nxt] == 0 && !is_cycle[nxt]) {
            go(nxt);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> from >> to;
        g[from].push_back(to);
        g[to].push_back(from);
        in[from]++;
        in[to]++;
    }
    for (int i = 1; i <= n; i++) {
        if (in[i] == 1)
            que.push(i);
    }
    memset(is_cycle, true, sizeof(is_cycle));

    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        is_cycle[cur] = false;
        for (auto nxt : g[cur]) {
            in[nxt]--;
            if (is_cycle[nxt] && in[nxt] == 1)
                que.push(nxt);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (is_cycle[i])
            que.push(i);
    }
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        if (!parent[cur])
            go(cur);
        cnt++;
    }
    while (q--) {
        cin >> from >> to;
        if (parent[from] == parent[to]) {
            cout << 1 << '\n';
        } else {
            cout << 2 << '\n';
        }
    }
}