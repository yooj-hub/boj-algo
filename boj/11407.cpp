#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int d[202][202];
int cap[202][202];
int flow[202][202];
int n, m, answer, tot;
int s = 0;
int e = 201;
int bias = 100;
int pre[202];
int dist[202];
int inq[202];
vector<int>g[202];
const int inf = 1e9+7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        g[i+bias].push_back(e);
        g[e].push_back(i+bias);
        cin >> cap[i+bias][e];
    }
    for(int j=1; j<=m; j++){
        g[s].push_back(j);
        g[j].push_back(s);
        cin >> cap[s][j];
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            g[i].push_back(j+bias);
            g[j+bias].push_back(i);
            cin >> cap[i][j+bias];
        }
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cin >> d[i][j+bias];
            d[j+bias][i] = -d[i][j+bias];
        }
    }
    while(true){
        memset(pre, -1, sizeof(pre));
        memset(inq, false, sizeof(inq));
        fill(dist, dist+202, inf);
        queue<int>q;
        q.push(s);
        dist[s] = 0;
        inq[s] = true;

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            inq[cur] = false;
            for(auto nxt : g[cur]){
                if(cap[cur][nxt] - flow[cur][nxt] >0 && dist[nxt] > dist[cur] + d[cur][nxt]){
                    dist[nxt] = dist[cur]+d[cur][nxt];
                    pre[nxt] = cur;
                    if(!inq[nxt]){
                        q.push(nxt);
                        inq[nxt] = true;
                    }
                }
            }
        }
        if(pre[e] == -1) break;
        int cost = inf;
        for(int i=e; i!=s; i= pre[i]){
            cost = min(cost, cap[pre[i]][i] - flow[pre[i]][i]);
        }

        for(int i=e; i!=s; i= pre[i]){
            tot += cost * d[pre[i]][i];
            flow[pre[i]][i] += cost;
            flow[i][pre[i]] -= cost;
        }
        answer += cost;
    }
    cout << answer << '\n' << tot;
}