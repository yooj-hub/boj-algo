#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int n, m;

int arr[301][301];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool chk[301][301];

int get_val(int x, int y) {
    int val = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx <= 0 || ny <= 0 || nx > n || ny > m)
            continue;
        if (arr[nx][ny])
            continue;
        val++;
    }
    return val;
}

bool melt() {
    bool ok = false;
    int nxt[301][301];
    memset(nxt, 0, sizeof(nxt));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == 0)
                continue;
            nxt[i][j] = max(0, arr[i][j] - get_val(i, j));
            ok = true;
        }
    }
    if(ok){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                arr[i][j] = nxt[i][j];
            }
        }
    }
    return ok;
}

void dfs(int x, int y) {
    if (chk[x][y])
        return;
    chk[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx <= 0 || ny <= 0 || nx > n || ny > m)
            continue;
        if (arr[nx][ny])
            dfs(nx, ny);
    }
}

bool grouping_check() {
    memset(chk, false, sizeof(chk));
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] && !chk[i][j]) {
                dfs(i, j);
                cnt++;
            }
        }
    }
    return cnt > 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }
    int answer = 0;
    do {
        if (grouping_check()) {
            cout << answer;
            return 0;
        }
        answer++;
    } while (melt());

    cout << 0;
}