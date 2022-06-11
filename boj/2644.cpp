#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

int n, s, e, m;
vector<int> g[101];
int chk[101];
queue<int> q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> s >> e;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    memset(chk, -1, sizeof(chk));
    chk[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto nxt : g[cur]) {
            if (chk[nxt] != -1)
                continue;
            chk[nxt] = chk[cur] + 1;
            q.push(nxt);
        }
    }
    cout << chk[e];
}