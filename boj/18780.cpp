#include <iostream>
#include <queue>

using namespace std;

vector<int> in;
vector<int> d;
vector<vector<pair<int, int>>> g;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    queue<int> q;
    int n, m, c, tmp, cur, from, to, cost;

    cin >> n >> m >> c;
    d.resize(n+1);
    g.resize(n+1);
    in.resize(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        d[i] = tmp;
    }
    for (int i = 0; i < c; i++) {
        cin >> from >> to >> cost;
        g[from].push_back({to, cost});
        in[to]++;
    }
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        for (auto & nxt : g[cur]) {
            in[nxt.first]--;
            d[nxt.first] = max(d[nxt.first], d[cur] + nxt.second);
            if (in[nxt.first] == 0)
                q.push(nxt.first);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << d[i] << '\n';
    }
}