#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 1010

using namespace std;

int n, m;
int a[101];
int b[101];
int d[202][202];
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
        cap[i+bias][e] = a[i];
        g[e].push_back(i+bias);
        g[i+bias].push_back(e);
    }
    for (int i = 1; i <= m; i++) {

        cin >> b[i];
        g[i].push_back(s);
        g[s].push_back(i);
        cap[s][i] = b[i];
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cap[i][j + bias] = b[i];
            g[i].push_back(j + bias);
            g[j + bias].push_back(i);
            int t;
            cin >> t;
            d[i][j+bias]=t;
            d[j+bias][i]=-t;
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
                    dist[nxt] > dist[cur] + d[cur][nxt]) {
                    dist[nxt] = dist[cur] + d[cur][nxt];
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
            answer+= cost * d[par[i]][i];
            flow[par[i]][i] += cost;
            flow[i][par[i]] -= cost;
        }
    }
    cout << answer;
}