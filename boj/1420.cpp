#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 10101

using namespace std;

int n, m, sx, sy, ex, ey;
char arr[101][101];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
vector<int> g[MX * 2 + 10];
int bias = MX;
map<pair<int, int>, int> fmap;
map<pair<int, int>, int> cmap;
int par[MX * 2 + 10];
int cost, answer;
const int inf = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'K') {
                sx = i, sy = j;
            }
            if (arr[i][j] == 'H') {
                ex = i, ey = j;
            }
        }
    }
    bool ok = true;
    for (int i = 0; i < 4; i++) {
        if (sx + dx[i] == ex && sy + dy[i] == ey)
            ok = false;
    }
    if (!ok) {
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == '#')
                continue;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx >= n || nx < 0 || ny >= m || ny < 0)
                    continue;
                if (arr[nx][ny] == '#')
                    continue;
                g[i * m + j].push_back(nx * m + ny + MX);
                cmap[{i * m + j, nx * m + ny + MX}] = 1;
                fmap[{i * m + j, nx * m + ny + MX}] = 0;
            }
        }
    }
    while (true) {
        memset(par, -1, sizeof(par));
        queue<int> q;
        q.push(sx * m + sy);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto nxt : g[cur]) {
                if (par[nxt] == -1 && cmap[{cur, nxt}] - fmap[{cur,nxt}] > 0) {
                    q.push(nxt);
                    par[nxt] = cur;
                    if (nxt == (ex * m + ey+ bias))
                        break;
                }
            }
        }
        if (par[ex * m + ey + bias] == -1)
            break;
        cost = inf;
        for (int i = (ex * m + ey); i != sx * m + sy; i = par[i]) {
            cost = min(cost, cmap[{par[i], i}] - fmap[{par[i], i}]);
        }
        for (int i = (ex * m + ey); i != sx * m + sy; i = par[i]) {
            fmap[{par[i], i}] += cost;
            fmap[{i, par[i]}] -= cost;
        }
        answer += cost;
    }
    cout << answer;
}