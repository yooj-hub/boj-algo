#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;

int board[18][18];
int tmp[18][18];
int n;
void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp[i][j] = board[i][j];
        }
    }
}

void change(int x, int y) { tmp[x][y] = 1 - tmp[x][y]; }

void push(int x, int y) {
    change(x, y);
    if (x + 1 != n)
        change(x + 1, y);
    if (y + 1 != n)
        change(x, y + 1);
    if (x - 1 >= 0)
        change(x - 1, y);
    if (y - 1 >= 0)
        change(x, y - 1);
}

bool isAnser() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (tmp[i][j] == 1)
                return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    int answer = -1;
    for (int j = 0; j < (1 << n); j++) {
        init();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (j & (1<<i)) {
                push(0, i);
                cnt++;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (tmp[i - 1][k] == 1) {
                    push(i, k);
                    cnt++;
                }
            }
        }
        if (isAnser()) {
            if (answer == -1 || cnt < answer) {
                answer = cnt;
            }
        }
    }
    cout << answer <<'\n';
}