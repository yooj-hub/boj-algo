#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;
const int mod = 1000001;
ll d[101][101];
ll comb[101][101];

void make_comb() {
    for (int i = 1; i <= 100; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == j || j == 0) {
                comb[i][j] = 1;
                continue;
            }
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    make_comb();
    int x = k;
    int y = k / 2;
    if (k % 2)
        y++;
    d[x][y] = 1;
    for (int i = y, j = k; i >= 1 && j >= 1; i--, j -= 2) {
        if (j >= 2)
            d[x][y] *= comb[i][1] * comb[j][2];
        else {
            d[x][y] *= comb[i][1] * comb[j][1];
        }
        d[x][y] %= mod;
    }
    d[y][x] = d[x][y];
    
    

    
}