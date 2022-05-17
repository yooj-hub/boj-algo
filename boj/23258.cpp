#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

int d[301][301];
int p[301][301][301];
int n, q, c, s, e;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> p[i][j][0];
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                p[i][j][k] = p[i][j][k - 1];
                if (i == j)
                    continue;
                if (p[i][k][k - 1] == 0 || p[k][j][k - 1] == 0)
                    continue;
                if (p[i][j][k - 1] >= p[i][k][k - 1] + p[k][j][k - 1] ||
                    p[i][j][k - 1] == 0) {
                    p[i][j][k] = p[i][k][k - 1] + p[k][j][k - 1];
                }
            }
        }
    }
    for (int i = 0; i < q; i++) {
        cin >> c >> s >> e;
        if (s==e){
            cout << 0<<'\n';
        }
        else if (p[s][e][c - 1] != 0)
            cout << p[s][e][c - 1] << '\n';
        else
            cout << "-1\n";
    }
}