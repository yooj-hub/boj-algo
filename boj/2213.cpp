#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;
int d[10101][2];
vector<int> w;
vector<int> g[10101];
vector<int> res;

void go(int a, int par) {
    for (auto &x : g[a]) {
        if (par == x)
            continue;
        else
            go(x, a);
    }
    d[a][0] = 0;
    d[a][1] = w[a];
    for (auto &x : g[a]) {
        if (x == par)
            continue;

        d[a][0] += max(d[x][0], d[x][1]);
        d[a][1] += d[x][0];
    }
}

void trace(int a, int b, int par) {
    if (b == 1) {
        res.push_back(a);
        for (auto &x : g[a]) {
            if (x == par)
                continue;
            trace(x, 0, a);
        }
    } else {
        for (auto &x : g[a]) {
            if (x == par)
                continue;
            if (d[x][0] < d[x][1]) {
                trace(x, 1, a);
            } else {
                trace(x, 0, a);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    w.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int from, to;
        cin >> from >> to;
        g[from].push_back(to);
        g[to].push_back(from);
    }
    go(1,0);
    if(d[1][0] < d[1][1]){
        trace(1,1,0);
    }else{
        trace(1,0,1);
    }

    sort(all(res));
    cout << max(d[1][0] , d[1][1])<<'\n';
    for(int i=0; i<res.size(); i++){
        cout << res[i]<<' ';
    }

}