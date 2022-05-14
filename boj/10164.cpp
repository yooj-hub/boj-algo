#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int n, m, k, row, col;
int d[16][16];

int go(int x, int y) {
    if (x < 0 || y < 0)
        return 0;
    if (d[x][y] != -1)
        return d[x][y];
    return d[x][y] = go(x - 1, y) + go(x, y - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(d, -1, sizeof(d));
    d[0][0] = 1;
    cin >> n >> m >> k;
    k--;
    row = k / m;
    col = k % m;
    n--, m--;
    if (k != -1)
        cout << go(row, col) * go(n - row, m - col) << '\n';
    else
        cout << go(n, m) << '\n';

}