#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;
int n, m;
int bias = 400;
int s = 0;
int e = 801;
int cap[802][802];
int flow[802][802];
int d[802][802];
vector<int> g[802];
int answer, tot;
int par[802];
int dist[802];
int inq[802];
const int inf = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        g[s].push_back(i);
        g[i].push_back(s);
        for (int j = 0; j < t; j++)
        {
            int tt, cost;
            cin >> tt >> cost;
            tt += bias;
            d[i][tt] = -cost;
            d[tt][i] = cost;
            g[i].push_back(tt);
            g[tt].push_back(i);
            cap[i][tt] = 1;
        }
        cap[s][i] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        g[i + bias].push_back(e);
        g[e].push_back(i + bias);
        cap[i + bias][e] = 1;
    }
    while (true)
    {
        memset(par, -1, sizeof(par));
        fill(dist, dist + 802, inf);
        memset(inq, false, sizeof(inq));
        inq[s] = true;
        queue<int> q;
        q.push(s);
        dist[s] = 0;

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            inq[cur] = false;
            for (auto nxt : g[cur])
            {
                if (cap[cur][nxt] - flow[cur][nxt] > 0 && dist[nxt] > dist[cur] + d[cur][nxt])
                {
                    dist[nxt] = dist[cur] + d[cur][nxt];
                    par[nxt] = cur;
                    if (!inq[nxt])
                    {
                        inq[nxt] = true;
                        q.push(nxt);
                    }
                }
            }
        }
        if (par[e] == -1)
            break;
        int cost = inf;
        for (int i = e; i != s; i = par[i])
        {
            cost = min(cost, cap[par[i]][i] - flow[par[i]][i]);
        }
        for (int i = e; i != s; i = par[i])
        {
            tot += (cost * d[par[i]][i])*(-1);
            flow[par[i]][i] += cost;
            flow[i][par[i]] -= cost;
        }
        answer += cost;
    }
    cout << answer << '\n'
         << tot;
}