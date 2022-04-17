#include<bits/stdc++.h>

using namespace std;

const int sz = 1e5 + 10;
vector<int> g[sz];
int depth[sz];
int dp[sz][30];
int visit[sz];
int n;

void dfs(int v, int d) {
    visit[v] = 1;
    depth[v] = d;
    for (auto i : g[v]) {
        if (!visit[i]) {
            dp[i][0] = v;
            dfs(i, d + 1);
        }
    }
}

void make_table() {
    for (int j = 1; j < 30; j++) {

        for (int i = 1; i <= n; i++) {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int
    diff = depth[u] - depth[v];
    for (int i = 0; diff; i++) {
        if (diff & 1) u = dp[u][i];
        diff >>= 1;
    }
    if (u == v) return u;
    for (int i = 29; i >= 0; i--) {
        if (dp[u][i] != dp[v][i])u = dp[u][i], v = dp[v][i];
    }
    return dp[u][0];

}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for(int i=0; i<n-1; i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0);
    make_table();

    int m; cin >> m;
    while(m--){
        int a, b; cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
}