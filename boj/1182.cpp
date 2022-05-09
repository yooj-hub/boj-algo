#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

int n, s;
vector<int> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> s;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = 0;
    for (int i = 1; i < (1 << n); i++) {
        int sum = 0;
        for (int k = 0; k < n; k++) {
            if (i & (1 << k)) {
                sum += arr[k];
            }
        }
        if (sum == s) {
            ans++;
        }
    }
    cout << ans << '\n';
}