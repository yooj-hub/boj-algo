#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

int d[200][1 << 4];
vector<string> a;
vector<string> b;
int r, c;
const int inf = 1e9 + 7;
bool is_black(int i, int j) { return ((i + j) % 2 == 0); }

int go(int idx, int state) {
    if (idx == r * c) {
        if (state == 0)
            return 0;
        return -inf;
    }
    if (idx > r * c)
        return -inf;
    int &ans = d[idx][state];
    if(ans != -1) return ans;
    int i = idx / c;
    int j = idx % c;
    if (a[i][j] == 'X') {
        return ans = go(idx+1, state >> 1);
    }
    ans = go(idx + 1, state >> 1);
    if ((state & 1) == 0) {
        if (is_black(i, j)) {
            if (j + 1 < c && i + 1 < r) {
                if ((state & 2) == 0 && a[i][j + 1] == '.' &&
                    a[i + 1][j] == '.') {
                    ans = max(ans,
                              go(idx + 2, (state >> 2) | (1 << (c - 2))) + 1);
                }
            }

        } else {
            if (j + 1 < c && i + 1 < r) {
                if (((state & 2) == 0) && a[i][j + 1] == '.' &&
                    a[i + 1][j + 1] == '.') {
                    ans =
                        max(ans, go(idx + 2, (state >> 2) | (1 << c - 1)) + 1);
                }
            }
            if (j - 1 >= 0 && i + 1 < r) {
                if ((state & (1 << (c - 1))) == 0 && a[i + 1][j - 1] == '.' &&
                    a[i + 1][j] == '.') {
                    ans = max(ans, go(idx + 1, (state >> 1) | (1 << (c - 1)) |
                                                   (1 << (c - 2))) +
                                       1);
                }
            }
            if (i + 1 < r && j + 1 < c) {
                if (a[i + 1][j] == '.' && a[i + 1][j + 1] == '.') {
                    ans = max(ans, go(idx + 2, (state >> 2) | (1 << (c - 1)) |
                                                   (1 << (c - 2))) +
                                       1);
                }
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> r >> c;
    b.resize(r);
    a.resize(c);
    for (int i = 0; i < r; i++) {
        cin >> b[i];
    }
    for (int j = 0; j < c; j++) {
        for (int i = 0; i < r; i++) {
            a[j] += b[i][j];
        }
    }
    swap(r, c);
    memset(d, -1, sizeof(d));
    cout << go(0, 0);
}