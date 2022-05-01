#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, m, x, y, z, st[100010], ed[100010], tree[100010], c, tree2[100010], f;
vector<vector<int>> vt;
void upd(int x, int val, int *t) {
    for (int i = x; i <= n; i += i & -i)
        t[i] += val;
}
int query(int x, int *t) {
    int ret = 0;
    for (int i = x; i > 0; i -= i & -i)
        ret += t[i];
    return ret;
}
void upd(int x, int y, int val, int *t) { upd(x, val, t), upd(y + 1, -val, t); }
int dfs(int here) {
    ed[here] = st[here] = ++c;
    for (auto next : vt[here])
        ed[here] = max(dfs(next), ed[here]);
    return ed[here];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vt.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (i != 1)
            vt[x].push_back(i);
    }
    dfs(1);
    for (int i = 0; i < m; i++) {
        cin >> x;
        if (x == 1) {
            cin >> y >> z;
            if (f)
                upd(st[y], z, tree);
            else
                upd(st[y], ed[y], z, tree2);
        } else if (x == 3)
            f ^= 1;
        else {
            cin >> y;
            cout << query(ed[y], tree) - query(st[y] - 1, tree) +
                        query(st[y], tree2)
                 << "\n";
        }
    }
    return 0;
}
