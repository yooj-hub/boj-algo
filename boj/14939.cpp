#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;

int board[10];
int tmp[10];
int n = 10;
void init() {
    for (int i = 0; i < n; i++) {
        tmp[i] = board[i];
    }
}

void push(int x, int y) {
    int pos = n - y - 1;
    tmp[x] ^= (1 << pos);
    if (x - 1 >= 0)
        tmp[x - 1] ^= (1 << pos);
    if (x + 1 < n)
        tmp[x + 1] ^= (1 << pos);
    if (y - 1 >= 0)
        tmp[x] ^= (1 << (pos + 1));
    if (y + 1 < n) {
        tmp[x] ^= (1 << (pos - 1));
    }
}

bool isAnser() {
    for (int i = 0; i < n; i++) {
        if (tmp[i] != 0)
            return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < n; i++) {
        for (int j = n-1; j >=0; j--) {
            char c;
            cin >> c;
            if (c != '#') {
                board[i] |= (1 << j);
            }
        }
    }
    int answer = -1;
    for (int i = 0; i < (1 << n); i++) {
        init();
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                push(0, j);
                cnt++;
            }
        }
        for (int j = 1; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (tmp[j - 1] & (1 << (n-k-1))) {
                    push(j, k);
                    cnt++;
                }
            }
        }
        if (!tmp[n-1] && (answer == -1 || answer > cnt)) {
            answer = cnt;
        }
    }
    cout << answer << '\n';
}