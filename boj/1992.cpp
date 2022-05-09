#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

vector<string> board;
string answer = "";
int n;
void solve(int sx, int sy, int sz) {
    if(sz == 0) return;

    bool ok = true;
    char pv = board[sx][sy];
    for (int i = sx; i < sx + sz; i++) {
        for (int j = sy; j < sy + sz; j++) {
            if (board[i][j] != pv) {
                ok = false;
                break;
            }
        }
        if (!ok)
            break;
    }
    if (ok) {
        answer += board[sx][sy];
    } else {
        answer += '(';
        solve(sx, sy, sz / 2);
        solve(sx, sy + sz / 2, sz / 2);
        solve(sx + sz / 2, sy, sz / 2);
        solve(sx + sz / 2, sy + sz / 2, sz / 2);
        answer += ')';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    board.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    solve(0, 0, n);
    cout << answer << '\n';
}