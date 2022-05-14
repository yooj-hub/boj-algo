#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int arr[100];
int n, target;
ll d[101][21];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        cin >> arr[i];
    }
    cin >> target;
    for (int i = 1; i <= n - 1; i++) {
        if (i == 1)
            d[i][arr[i]] = 1;
        else
            for (int j = 0; j <= 20; j++) {
                if (j + arr[i] <= 20) {
                    d[i][j + arr[i]] += d[i-1][j];
                }
                if (0 <= j - arr[i]) {
                    d[i][j - arr[i]] += d[i-1][j];
                }
            }
    }
    cout << d[n - 1][target];
}