#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

int n, m;
int a[101];
int b[101];
int c[202][202];
int s = 0;
int e = 201;
int bias = 100;
int cap[202][202];
int flow[202][202];
int dist[202];
int par[202];
vector<int> g[202];
const int inf = 1e9 + 7;
bool inq[202];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cap[s][i] = a[i];
        g[s].push_back(i);
        g[i].push_back(s);
    }
    for (int i = 1; i <= m; i++) {
        int t;
        cin >> t;

        g[i + bias].push_back(e);
        g[e].push_back(i + bias);
        cap[i + bias][e] = t;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cap[i][j + bias] = a[i];
            g[i].push_back(j + bias);
            g[j + bias].push_back(i);
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i + bias][j];
        }
    }
    while (true) {
        memset(par, -1, sizeof(par));
        fill(dist, dist + 202, inf);
        memset(inq, false, sizeof(inq));
        queue<int> q;
        q.push(s);
        dist[s] = 0;
        inq[s] = true;
        while (!q.empty()) {
            int cur = q.front();
            inq[cur] = false;
            q.pop();
            for (auto nxt : g[cur]) {
                if (cap[cur][nxt] - flow[cur][nxt] > 0 &&
                    dist[nxt] > dist[cur] + c[nxt][cur]) {
                    dist[nxt] = dist[cur] + c[nxt][cur];
                    par[nxt] = cur;
                    if (!inq[nxt]) {
                        q.push(nxt);
                        inq[nxt] = true;
                    }
                }
            }
        }
        if (par[e] == -1)
            break;
        int cost = inf;
        for (int i = e; i != s; i = par[i]) {
            cost = min(cost, cap[par[i]][i] - flow[par[i]][i]);
        }
        for (int i = e; i != s; i = par[i]) {
            flow[par[i]][i] += cost;
            flow[i][par[i]] -= cost;
        }
        answer += cost * dist[e];
        cout << dist[e] << ' ' << cost << ' ' << par[e] - 100 << endl;
    }
    cout << answer;
}