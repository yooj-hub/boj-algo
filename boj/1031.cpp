#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int n, m;
int bias = 100;
int e = 401;
int s = 0;
int a[51];
int b[51];
vector<int> g[402];
int cap[402][402];
int flow[402][402];
const int inf = 1e9 + 7;
int result[51][51];
int par[402];

void change_flow(int st, int en){
    memset(par, -1, sizeof(par));
    queue<int> q;
    q.push(st);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto nxt : g[cur]){
            if(cur < st || (cur == st && nxt < en)) continue;
            if(cap[cur][nxt] - flow[cur][nxt] > 0 && par[nxt] == -1){
                q.push(nxt);
                par[nxt] = cur;
                if(nxt == en) break;
            }
        }
    }
    if(par[en] == -1) return;
    flow[st][en] = flow[en][st] = 0;
    for(int i=en; i!=st; i=par[i]){
        flow[par[i]][i]++;
        flow[i][par[i]]--;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        g[i].push_back(s);
        g[s].push_back(i);
        g[i].push_back(i + bias);
        g[i + bias].push_back(i);
        cin >> cap[i][i + bias];
        cap[s][i] = cap[i][i + bias];
    }
    for (int j = 1; j <= m; j++) {
        g[j + bias * 2].push_back(j + bias * 3);
        g[j + bias * 3].push_back(j + bias * 2);
        g[j + bias * 3].push_back(e);
        g[e].push_back(j + bias * 3);
        cin >> cap[j + bias * 2][j + bias * 3];
        cap[j + bias * 3][e] = cap[j + bias * 2][j + bias * 3];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = m + bias * 2; j >= 1 + bias * 2; j--) {
            g[i+bias].push_back(j);
            g[j].push_back(i+bias);
            cap[i+bias][j] = 1;
        }
    }

    while (true) {
        memset(par, -1, sizeof(par));
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto nxt : g[cur]) {
                if (par[nxt] == -1 && cap[cur][nxt] - flow[cur][nxt] > 0) {
                    par[nxt] = cur;
                    q.push(nxt);
                    if (nxt == e)
                        break;
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
    }
    for(int i=1+bias; i<=n+bias; i++){
        for(int j= 1+bias*2; j<=m+bias*2;j++){
            if(flow[i][j] != 1) continue;
            change_flow(i,j);
        }
    }
    for(int i=1+bias; i<=n+bias; i++){
        for(int j= 1+bias*2; j<=m+bias*2;j++){
            result[i-bias][j-bias*2] = flow[i][j];
        }
    }


    bool ok = true;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= m; j++) {
            if (result[i][j])
                cnt++;
        }
        if (cap[s][i] != cnt)
            ok = false;
    }
    for (int j = 1; j <= m; j++) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (result[i][j])
                cnt++;
        }
        if (cap[j + bias * 3][e] != cnt)
            ok = false;
    }
    if (ok) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << result[i][j];
            }
            cout << '\n';
        }
    } else {
        cout << "-1";
    }
}