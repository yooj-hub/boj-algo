#include<bits/stdc++.h>


using namespace std;

vector<int> g[2010];
vector<int> par(2010, -1);
bool chk[2010];
int n, m;

int match(int v) {
    for (auto i : g[v]) {
        if (chk[i]) continue;
        chk[i] = 1;
        if (par[i] == -1 || match(par[i])) {
            par[i] = v;
            return 1;
        }
    }
    return 0;
}


int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        for (int j = 0; j < t; j++) {
            int tt;
            cin >> tt;
            tt += 1000;
            g[i].push_back(tt);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        memset(chk, 0, sizeof(chk));
        if (match(i)) ans++;
    }
    cout << ans;

}