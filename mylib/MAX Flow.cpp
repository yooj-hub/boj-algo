#include <bits/stdc++.h>


using namespace std;

vector<int> g[2010];
int cap[2010][2010];
int flow[2010][2010];
int n, m;
const int inf = 1e9 + 7;
const int s = 0, e = 2001;

int par[2010];
int ans = 0;


int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cap[s][i] = 2;
        g[s].push_back(i);
        g[i].push_back(s);
        int t;
        cin >> t;
        for (int j = 0; j < t; j++) {
            int tt;
            cin >> tt;
            tt += 1000;
            g[i].push_back(tt);
            g[tt].push_back(i);
            cap[i][tt] = 1;
        }
    }

    for (int i = 1001; i <= 1000 + m; i++) {
        g[i].push_back(e);
        g[e].push_back(i);
        cap[i][e] = 1;
    }
    for (int iter = 1;; iter++) {
        memset(par, -1, sizeof(par));
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            for (auto nxt : g[now]) {
                if (par[nxt] == -1 && cap[now][nxt] - flow[now][nxt] > 0) {
                    q.push(nxt);
                    par[nxt] = now;
                    if (nxt == e) break;
                }
            }
        }
        if (par[e] == -1) break;

        int cost = inf;
        for (int i = e; i != s; i = par[i]) {
            cost = min(cost, cap[par[i]][i] - flow[par[i]][i]);
        }

        for (int i = e; i != s; i = par[i]) {
            flow[par[i]][i] += cost;
            flow[i][par[i]] -= cost;
        }
        ans += cost;
    }
    cout << ans;
}