#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 1010

using namespace std;

vector<int> g[MX];
bool chk[MX];
int from, to, n, m, start;

void dfs(int current) {
    chk[current] = true;
    cout << current << ' ';
    for (auto &nxt : g[current])
        if (!chk[nxt]) {
            
            dfs(nxt);
        }
}
void bfs(int current) {
    queue<int> q;
    cout << current << ' ';
    q.push(current);
    chk[current] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto &nxt : g[cur])
            if (!chk[nxt]) {
                cout << nxt << ' ';
                q.push(nxt);
                chk[nxt] = true;
            }
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> start;
    while (m--) {
        cin >> from >> to;
        g[from].push_back(to);
        g[to].push_back(from);
    }
    for (int i = 1; i <= n; i++) {
        sort(all(g[i]));
    }
    dfs(start);

    memset(chk, false, sizeof(chk));
    cout << '\n';
    bfs(start);
}