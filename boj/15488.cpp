#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int n, x, y, k;
double d[51][51][51];
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
long double ans = 1.0;

bool position_check(int row, int col) {
    return !(row <= 0 || col <= 0 || row > n || col > n);
}

int main() {
    scanf("%d %d %d %d", &n, &x, &y, &k);
    d[x][y][0] = 1 / 8.0;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            for (int l = 1; l <= n; l++) {
                if (d[j][l][i - 1] == 0)
                    continue;
                for (int dir = 0; dir < 8; dir++) {
                    int nx = j + dx[dir];
                    int ny = l + dy[dir];
                    if (!position_check(nx, ny)) {
                        ans -= (long double)d[j][l][i - 1];
                        continue;
                    }
                    d[nx][ny][i] += d[j][l][i - 1] / 8;
                }
            }
        }
    }

    printf("%.10Lf", ans);
}