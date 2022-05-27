#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int s, e;
vector<int> arr;
int n, k;
int current;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    current = arr[0];
    int ans = 0;
    while (e < n) {
        if (current == k) {
            ans++;
            current -= arr[s++];
        } else if (current < k) {
            current += arr[++e];
        } else if (current > k) {
            current -= arr[s++];
        }
    }
    cout << ans<<'\n';
}