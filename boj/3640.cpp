#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 2003

using namespace std;

int s = 0;
int e = 2001;
int bias = 1000;
int s2 = 1;
int cap[MX][MX];
int flow[MX][MX];
int d[MX][MX];
int par[MX];
int inq[MX];
int n, m;
vector<int> g[MX];
int dist[MX];
const int inf = 1e9 + 7;
int answer;
void init() {
    for (int i = 0; i < MX; i++) {
        g[i].clear();
    }
    memset(cap, 0, sizeof(cap));
    memset(flow, 0, sizeof(flow));
    memset(d, 0, sizeof(d));
    e = n+bias;
    answer = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (true) {
        cin >> n >> m;
        if (cin.eof()) {
            return 0;
        }
        init();
        g[s].push_back(s2);
        g[s2].push_back(s);
        cap[s][s2] = 2;
        for (int i = 0; i < m; i++) {
            int from, to, cost;
            cin >> from >> to >> cost;
            d[from + bias][to] = cost;
            d[to][from + bias] = -cost;
            cap[from + bias][to] = 1;
            g[from + bias].push_back(to);
            g[to].push_back(from + bias);
        }
        for (int i = 1; i <= n; i++) {
            g[i].push_back(i + bias);
            g[i + bias].push_back(i);
            cap[i][i + bias] = 1;
        }
        cap[1][1+bias] = inf;
        cap[n][n+bias] = inf;
        while (true) {
            memset(inq, false, sizeof(inq));
            memset(par, -1, sizeof(par));
            fill(dist, dist + MX, inf);
            queue<int> q;
            q.push(s);
            inq[s] = true;
            dist[s] = 0;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                inq[cur] = false;
                for (auto nxt : g[cur]) {
                    if (cap[cur][nxt] - flow[cur][nxt] > 0 &&
                        dist[nxt] > dist[cur] + d[cur][nxt]) {
                        dist[nxt] = dist[cur] + d[cur][nxt];
                        par[nxt] = cur;
                        if (!inq[nxt]) {
                            inq[nxt] = true;
                            q.push(nxt);
                        }
                    }
                }
            }
            if (par[e] == -1)
                break;
            int cost = inf;
            for (int i = e; i != s; i = par[i]) {
                //cout << i << endl;
                cost = min(cost, cap[par[i]][i] - flow[par[i]][i]);
            }
            for (int i = e; i != s; i = par[i]) {
                answer += cost * d[par[i]][i];
                flow[par[i]][i] += cost;
                flow[i][par[i]] -= cost;
            }
        }
        cout << answer << '\n';
    }
}