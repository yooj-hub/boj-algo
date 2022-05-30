#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m, k, x, y, nx, ny, cnt;
char board[1000][1000];
int chk[1000][1000][11];
queue<tuple<int, int, int>> q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    q.push({0, 0, k});
    chk[0][0][k] = true;
    int ans = -1;
    while (!q.empty()) {
        tie(x, y, cnt) = q.front();
        q.pop();
        if (x == n - 1 && y == m - 1) {
            cout << chk[n - 1][m - 1][cnt];
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (board[nx][ny] == '0') {
                if (chk[nx][ny][cnt])
                    continue;
                chk[nx][ny][cnt] = chk[x][y][cnt] + 1;
                q.push({nx, ny, cnt});
            } else {
                if (cnt == 0)
                    continue;
                if (chk[nx][ny][cnt - 1])
                    continue;
                chk[nx][ny][cnt - 1] = chk[x][y][cnt] + 1;
                q.push({nx, ny, cnt - 1});
            }
        }
    }
    cout << -1;
}