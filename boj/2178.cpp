#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, m;
char arr[100][100];
int a[100][100];
bool chk[100][100];
queue<pair<int, int>> q;
const int inf = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    q.push({0, 0});
    chk[0][0] = true;
    int ans = inf;
    a[0][0] = 1;
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        if (x == n - 1 && y == m - 1) {
            ans = min(ans, a[x][y]);
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (chk[nx][ny])
                continue;
            if (arr[nx][ny] == '0')
                continue;
            chk[nx][ny] = true;
            a[nx][ny] = a[x][y] + 1;
            q.push({nx, ny});
        }
    }
    cout << ans << '\n';
}