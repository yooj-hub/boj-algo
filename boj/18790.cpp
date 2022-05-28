#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int n;
int arr[1001];
int d[1001][501];
bool solve(int idx, int val, int cnt) {
    if (val == 0 && cnt == n) {
        return true;
    }
    if (idx == n && (val || cnt != n)) {
        return false;
    }
    if (d[idx][val] != -1) {
        return d[idx][val];
    }
    int &cur = d[idx][val];
    if (solve(idx + 1, (val + arr[idx]) % n, cnt + 1)) {
        cout << arr[idx] << ' ';
        return cur = true;
    }
    if (solve(idx + 1, val, cnt)) {
        return cur = true;
    }
    return cur = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= (2 * n - 1); i++) {
        cin >> arr[i];
    }
    memset(d, -1, sizeof(d));
    if (!solve(1, 0, 0)) {
        cout << -1;
    }
}