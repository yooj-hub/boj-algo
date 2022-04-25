#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 1025
using namespace std;

ll arr[MX][MX];
ll tree[MX][MX];
int n, m;

void update(int x, int y, int val) {
    for (int i = x; i <= n; i += i & -i) {
        for (int j = y; j <= n; j += j & -j) {
            tree[i][j] += val;
        }
    }
}

ll sum(int x, int y) {
    ll ans = 0;
    for (int i = x; i > 0; i -= i & -i) {
        for (int j = y; j > 0; j -= j & -j) {
            ans += tree[i][j];
        }
    }
    return ans;
}

ll query(int x1, int y1, int x2, int y2) {
    return sum(x2, y2) + sum(x1 - 1, y1 - 1) - sum(x2, y1 - 1) -
           sum(x1 - 1, y2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            update(i, j, arr[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        int w;
        cin >> w;
        if (w == 1) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << query(x1,y1,x2,y2)<<'\n';
                 
        } else {
            int x, y;
            ll c;
            cin >> x >> y >> c;
            ll diff = c - arr[x][y];
            arr[x][y] = c;

            update(x, y, diff);
        }
    }
}