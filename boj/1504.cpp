#include <bits/stdc++.h>
#define ll long long int
#define MX 801
using namespace std;

vector<pair<int, int>> g[MX];
const int inf = 1e9 + 7;
int n;

ll spfa(int start, int end) {
    ll d[MX];
    bool qin[MX];
    memset(d, inf, sizeof(d));
    memset(qin, false, sizeof(qin));
    d[start] = 0;
    qin[start] = true;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        qin[v] = false;
        for (auto nxt : g[v]) {
            if (d[nxt.second] > d[v] + nxt.first) {
                d[nxt.second] = d[v] + nxt.first;
                if (qin[nxt.second])
                    continue;
                qin[nxt.second] = true;
                q.push(nxt.second);
            }
        }
    }
    return d[end];
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int m;
    cin >> n >> m;
    while (m--) {
        int from, to, cost;
        cin >> from >> to >> cost;
        g[from].emplace_back(cost, to);
        g[to].emplace_back(cost, from);
    }
    int v1, v2;
    cin >> v1 >> v2;
    ll l1 = spfa(1, v1) + spfa(v1, v2) + spfa(v2, n);
    ll l2 = spfa(1, v2) + spfa(v2, v1) + spfa(v1, n);
    ll answer = min(l1, l2);
    if (answer > inf)
        cout << -1;
    else
        cout << answer;
}