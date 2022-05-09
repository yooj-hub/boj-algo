#include <bits/stdc++.h>

using namespace std;
int n, x, y;
int ans = 0;
bitset<24> chk;
bitset<13> chk2;
void dfs(int idx) {
    if (idx == n * 2) {
        ++ans;
        return;
    }
    if (chk[idx]) {
        dfs(idx + 1);
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (chk2[i])
            continue;
        if (i + idx + 1 > 2 * n)
            continue;
        if (chk[i + idx + 1])
            continue;
        chk2[i] = 1;
        chk[i + idx + 1] = 1;
        dfs(idx + 1);
        chk2[i] = 0;
        chk[i + idx + 1] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> x >> y;
    int k = y - x - 1;
    x--;
    y--;
    chk2[k] = 1;
    chk[x] = 1;
    chk[y] = 1;
    dfs(0);

    cout << ans;
}