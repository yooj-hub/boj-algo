#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;
int board[10];
vector<string> s;

void clear() { s.clear(); }
int n, m;

bool check_pos(int x, int y) {
    if (s[x][y] == 'x')
        return false;
    int pos = m - y - 1;
    if (x - 1 >= 0 && y - 1 >= 0) {
        if (board[x - 1] & (1 << (pos + 1))) {
            return false;
        }
    }
    if (y - 1 >= 0) {
        if (board[x] & (1 << (pos + 1)))
            return false;
    }
    if (y + 1 < m) {
        if (board[x] & (1 << (pos - 1))) {
            return false;
        }
    }
    if (x - 1 >= 0 && y + 1 < m) {
        if (board[x - 1] & (1 << (pos - 1))) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << (1 << 20) << endl;
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        clear();
        for (int i = 0; i < n; i++) {
            string tmp;
            cin >> tmp;
            s.push_back(tmp);
        }
        int answer = -1;
        for (int l = 0; l < n; l++) {
            int cnt = 0;
            for (int k = 0; k < (1 << m); k++) {
                
                for (int i = 0; i < m; i++) {
                    if (k & (1 << i) && check_pos(0, i)) {
                        board[0] |= (1 << (m - i - 1));
                        cnt++;
                    }
                }
                for (int i = 1; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (check_pos(i, j)) {
                            board[i] |= (1 << (m - j - 1));
                            cnt++;
                        }
                    }
                }
                if (answer == -1 || answer < cnt) {
                    answer = cnt;
                }
            }
        }
        cout << answer << '\n';
    }
}