#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

ll ans = 0;
int n, t;
int arr[21];
vector<int> g[21];

void init() {
    for (int i = 0; i <= 20; i++) {
        g[i].clear();
        g[i].push_back(-1);
        g[i].push_back(-1);
    }
    ans = 1;
}

void dfs(int idx, int current) {
    if (idx == 1) {
        g[0][0] = arr[idx];
    } else {
        if (current > arr[idx]) {
            if (g[current][0] == -1) {
                g[current][0] = arr[idx];
            } else {
                dfs(idx, g[current][0]);
            }
        } else {
            if (g[current][1] == -1) {
                g[current][1] = arr[idx];
            } else {
                dfs(idx, g[current][1]);
            }
        }
    }
}

void solve(vector<int> tmp) {
    if(tmp.size() == 0) return;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--) {
        init();
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        for(int i=1; i<=n; i++){
            dfs(i, arr[1]);
        }
        vector<int> tmp;
        if(g[arr[1]][0] != -1){
            tmp.push_back(g[arr[1]][0]);
        }
        if(g[arr[1]][1] != -1){
            tmp.push_back(g[arr[1]][1]);
        }
        solve(tmp);

    }
}