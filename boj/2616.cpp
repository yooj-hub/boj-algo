#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int n, k;
int arr[50001];
int s[50001];
int d[4][50001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        s[i] = s[i - 1] + arr[i];
    }
    cin >> k;
    for (int i = 1; i <= 3; i++) {
        for (int j = k; j <= n; j++) {
            d[i][j] = max(s[j] - s[j - k] + d[i - 1][j - k], d[i][j - 1]);
        }
    }
    cout << d[3][n];
}