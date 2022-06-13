#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int arr[11][11];
int s[11][11];
bitset<11> chk[11];
int answer;
int n = 10;
const int inf = 1e9 + 7;

bool possible(int x, int y, int sz) {
    if (x + sz - 1 > n || y + sz - 1 > n)
        return false;
    int tmp = s[x - 1][y - 1] - s[x + sz - 1][y - 1] - s[x - 1][y + sz - 1] +
              s[x + sz - 1][y + sz - 1];
    return tmp == sz * sz;
}

void change_chk(int x, int y, int sz, bool val) {
    for (int i = x; i < x + sz; i++) {
        for (int j = y; j < y + sz; j++) {
            chk[i][j] = val;
        }
    }
}

int go(int x, int y, int one, int two, int three, int four, int five, int val) {
    if (x == 11) {
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][j]) {
                    if (!chk[i][j])
                        ok = false;
                }
            }
        }
        if (ok)
            return val;
        return inf;
    }

    int ny = y + 1;
    int nx = x;
    if (ny == 11) {
        ny = 1;
        nx += 1;
    }

    int answer = inf;
    if (!arr[x][y] || chk[x][y])
        answer = go(nx, ny, one, two, three, four, five, val);
    if (chk[x][y] == 0 && arr[x][y]) {
        if (one != 0) {
            if (possible(x, y, 1)) {
                change_chk(x, y, 1, true);
                answer =
                    min(go(nx, ny, one - 1, two, three, four, five, val + 1),
                        answer);
                change_chk(x, y, 1, false);
            }
        }
        if (two != 0) {
            if (possible(x, y, 2)) {
                change_chk(x, y, 2, true);
                answer =
                    min(go(nx, ny, one, two - 1, three, four, five, val + 1),
                        answer);
                change_chk(x, y, 2, false);
            }
        }
        if (three != 0) {
            if (possible(x, y, 3)) {
                change_chk(x, y, 3, true);
                answer =
                    min(go(nx, ny, one, two, three - 1, four, five, val + 1),
                        answer);
                change_chk(x, y, 3, false);
            }
        }
        if (four != 0) {
            if (possible(x, y, 4)) {
                change_chk(x, y, 4, true);
                answer =
                    min(go(nx, ny, one, two, three, four - 1, five, val + 1),
                        answer);
                change_chk(x, y, 4, false);
            }
        }
        if (five != 0) {
            if (possible(x, y, 5)) {
                change_chk(x, y, 5, true);
                answer =
                    min(go(nx, ny, one, two, three, four, five - 1, val + 1),
                        answer);
                change_chk(x, y, 5, false);
            }
        }
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j == 1) {
                s[i][j] = arr[i][j];
            } else {
                s[i][j] = arr[i][j] + s[i][j - 1];
            }
        }
    }
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            if (i != 1) {
                s[i][j] += s[i - 1][j];
            }
        }
    }
    // for(int i=1; i<11; i++){
    //     for(int j=1; j<11; j++){
    //         cout << s[i][j] <<' ';
    //     }
    //     cout <<'\n';

    // }
    // cout << possible(1,1,1);
    int res = go(1, 1, 5, 5, 5, 5, 5, 0);

    cout << ((res == inf) ? -1 : res) << '\n';
}