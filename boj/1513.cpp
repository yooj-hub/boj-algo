#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, c;
    int d[51][51][51];
    int a[51][51];
    memset(a, 0, sizeof(a));
    memset(d, 0, sizeof(d));
    cin >> n >> m >> c;
    for (int i = 1; i <= c; i++) {
        int x, y;
        cin >> x >> y;
        a[x][y] = i;
    }
    d[0][1][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 0) {
                for (int k = 0; k <= c; k++) {
                    d[i][j][k] = d[i - 1][j][k] + d[i][j - 1][k];
                }
            } else {
                d[i][j][a[i][j]] = 0;
                for(int k=0; k<a[i][j]; k++){
                    d[i - 1][j][k] + d[i][j - 1][a[i][j] - 1];
                }
            }
        }
    }
    for (int i = 0; i <= c; i++) {
        cout << d[n][m][i] << ' ';
    }
}