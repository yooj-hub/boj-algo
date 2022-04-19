#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;
const int sz = 11;
int a[sz] = {3, 6, 2, 5, 3, 1, 8, 9, 7, 3, 5};
int d[11][11];

void init() {
    for (int i = 0; i < sz; i++) {
        d[i][0] = a[i];
    }
    for (int j = 1; j < 4; j++) {
        for (int i = 0; i < sz; i++) {
            if (i + (1 << j) - 1 < sz) {
                d[i][j] = min(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);
            } else {
                break;
            }
        }
    }
}

int query(int start, int end) {
    int ans = a[start];
    int k = 16;
    while (start <= end && k >= 0) {
        if (start + (1 << k) - 1 <= end) {
            ans = min(ans, d[start][k]);
            start += (1 << k);
        }
        k -= 1;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    cout << query(0, 10);
    cout << query(6, 9);
}