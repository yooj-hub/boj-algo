#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

int n, m;
int s = 0;
int e = 201;
int cap[202][202];
int flow[202][202];
vector<int> g[202];
int bias = 100;
int answer = 0;
int par[202];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        g[i + bias].push_back(e);
        g[e].push_back(i + bias);
        cin >> cap[i + bias][e];
    }
    for (int i = 1; i <= m; i++) {
        g[s].push_back(i);
        g[i].push_back(s);

        cin >> cap[s][i];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            g[i].push_back(j + bias);
            g[j + bias].push_back(i);
            cin >> cap[i][j + bias];
        }
    }
    while (true) {
        memset(par, -1, sizeof(par));

        queue<int>q;
        q.push(s);
        
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto nxt : g[cur]){
                if(par[nxt] == -1 && cap[cur][nxt] - flow[cur][nxt]>0){
                    par[nxt] = cur;
                    q.push(nxt);
                    if(nxt == e) break;
                }
            }
        }
        if(par[e] == -1) break;
        int cost = 1e9+7;
        for(int i=e; i!=s; i= par[i]){
            cost = min(cost, cap[par[i]][i]-flow[par[i]][i]);
        }
        for(int i=e; i!=s; i= par[i]){
            flow[par[i]][i] +=cost;
            flow[i][par[i]] -=cost;
        }
        answer+=cost;
    }
    cout << answer;
}