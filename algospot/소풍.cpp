#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;

vector<int> fr[10];
int n, m;
int go(int idx, vector<bool> &chk) {
    if (chk[idx])
        go(idx + 1, chk);
    for (auto &x : fr[idx]) {
        if()
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    while (t--) {

        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            fr[a].push_back(b);
            fr[b].push_back(a);
        }
    }
}