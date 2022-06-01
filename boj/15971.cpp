#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010
#define DISTANCE first
#define INDEX second

using namespace std;
int n, f, t;
vector<pair<int, int>> g[MX];
vector<pair<int, int>> edges;
int dist1[MX];
int dist2[MX];
bool in[MX];
queue<int> q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> f >> t;
    if(f == t){
        cout << 0 <<'\n';
        return 0;
    }
    for (int i = 1; i < n; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        g[from].push_back({cost, to});
        g[to].push_back({cost, from});
        edges.push_back({from, to});
    }
    q.push(f);
    memset(dist1, -1, sizeof(dist1));
    memset(dist2, -1, sizeof(dist1));
    dist1[f] = 0;
    dist2[t] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto &nxt : g[cur]) {
            if (dist1[nxt.INDEX] != -1)
                continue;
            dist1[nxt.INDEX] = dist1[cur] + nxt.DISTANCE;
            q.push(nxt.INDEX);
        }
    }
    q.push(t);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto &nxt : g[cur]) {
            if (dist2[nxt.INDEX] != -1)
                continue;
            dist2[nxt.INDEX] = dist2[cur] + nxt.DISTANCE;
            q.push(nxt.INDEX);
        }
    }
    int ans = 2e9 + 7;
    for (auto x : edges) {
        ans = min({ans, dist1[x.first] + dist2[x.second],
                   dist1[x.second] + dist2[x.first]});
    }
    cout << ans;
}