#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

int n, m;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int arr[1000][1000];
bool chk[1000][1000];
queue<tuple<int, int, int>> q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                q.push({i, j, 0});
                chk[i][j] = true;
            }
        }
    }
    int ans = 0;
    while (!q.empty()) {
        int x, y, t;
        tie(x, y, t) = q.front();
        ans = max(ans, t);
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
            if (chk[nx][ny])
                continue;
            if (arr[nx][ny] == -1)
                continue;
            chk[nx][ny] = true;
            arr[nx][ny] = 1;
            q.push({nx, ny, t + 1});
        }
    }
    bool ok = true;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 0)
                ok = false;
        }
    }
    if (ok) {
        cout << ans;
    } else {
        cout << -1;
    }
}