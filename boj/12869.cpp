#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int n;
int d[61][61][61];
const int inf = 1e9 + 7;
int go(int a, int b, int c) {
    if (a < 0)
        a = 0;
    if (b < 0)
        b = 0;
    if (c < 0)
        c = 0;
    if (d[a][b][c] != -1)
        return d[a][b][c];
    int &ret = d[a][b][c];
    ret = min({go(a - 9, b - 3, c - 1), go(a - 9, b - 1, c - 3),
               go(a - 3, b - 9, c - 1), go(a - 3, b - 1, c - 9),
               go(a - 1, b - 9, c - 3), go(a - 1, b - 3, c - 9)}) +
          1;
    return ret;
}
int arr[3];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    memset(d, -1, sizeof(d));
    d[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << go(arr[0], arr[1], arr[2]);
}