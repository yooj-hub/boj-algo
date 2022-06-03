#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

int n, m;
int d[300][(1 << 10)];
vector<string> a;
string board[26];
const int inf = 1e9 + 7;
int go(int idx, int state) {
    if (idx == n * m) {
        if (state == 0)
            return 0;
        return -inf;
    }
    if (idx > n * m)
        return -inf;
    int &ans = d[idx][state];
    if (ans != -1)
        return ans;
    int i = idx / m;
    int j = idx % m;
    if (board[i][j] == '1') {
        return ans = go(idx + 1, state >> 1) + 1;
    }
    ans = go(idx+1, state>>1);
    if ((state & 1) == 0) {
        ans = max(ans, go(idx + 1, state >> 1) + 1);
    }
    if (i != n - 1 && j != m - 1 && (state & 1) == 0 && (state & 2) == 0 &&
        board[i][j + 1] == '.' && board[i][j] == '.' &&
        board[i + 1][j] == '.' && board[i + 1][j + 1] == '.') {
        ans = max(ans,
                  go(idx + 2, (state >> 2) | (1 << m - 1) | (1 << m - 2)) + 16);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        a.push_back(x);
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            board[j] += a[i][j];
        }
    }
    swap(n, m);
    memset(d, -1, sizeof(d));
    cout << go(0, 0) << '\n';
}