#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int d[1001][1001];
string a, b;
vector<char> ans;

void go(int x, int y) {
    if (d[x][y] == 0)
        return;

    if (d[x][y] == d[x][y - 1])
        go(x, y - 1);
    else if (d[x][y] == d[x - 1][y])
        go(x - 1, y);
    else {
        ans.push_back(a[x]);
        go(x - 1, y - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> a >> b;
    a = '#' + a;
    b = '#' + b;
    for (int i = 1; i < a.size(); i++) {
        for (int j = 1; j < b.size(); j++) {
            if (a[i] == b[j]) {
                d[i][j] = d[i - 1][j - 1] + 1;
            } else {
                if (d[i][j] < d[i][j - 1]) {
                    d[i][j] = d[i][j - 1];
                }
                if (d[i][j] < d[i - 1][j]) {
                    d[i][j] = d[i - 1][j];
                }
            }
        }
    }
    int ret = d[a.size() - 1][b.size() - 1];
    cout << ret << '\n';
    if (ret) {
        go(a.size() - 1, b.size() - 1);
        for (int i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i];
        }
    }
}