#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

int n, k, d;
int bias = 200;
int capacity[400][400];
int flow[400][400];
int par[400];
int s = 0;
int e = 399;
int answer;
vector<int> g[400];
const int inf = 1e9+7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k >> d;
    for(int i=1; i<=n; i++){
        capacity[s][i] = k;
        g[s].push_back(i);
        g[i].push_back(s);
    }
    for (int i = 1; i <= d; i++) {
        int t;
        cin >> t;
        capacity[i+bias][e] = t;
        g[i+bias].push_back(e);
        g[e].push_back(i+bias);
    }
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        for(int j=0; j<t; j++){
            int tt;
            cin >> tt;
            tt+= bias;
            capacity[i][tt] = 1;
            g[i].push_back(tt);
            g[tt].push_back(i);
        }
    }
    while(true){
        memset(par, -1, sizeof(par));
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto nxt : g[cur]){
                if(par[nxt] == -1 && capacity[cur][nxt] - flow[cur][nxt]>0){
                    q.push(nxt);
                    par[nxt] = cur;
                    if(nxt == e) break;
                }
            }
        }
        if(par[e] == -1) break;

        int cost = inf;
        for(int i=e; i!=s; i=par[i]){
            cost = min(cost, capacity[par[i]][i] - flow[par[i]][i]);
        }
        for(int i=e; i!=s; i=par[i]){
            flow[par[i]][i] += cost;
            flow[i][par[i]] -= cost;
        }
        answer += cost;
    }
    cout << answer;

}