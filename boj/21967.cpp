#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;
int mn, mx;
int arr[1000001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = 0;
    for (int i = 1; i <= 8; i++) {
        mn = i, mx = i + 2;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (mn <= arr[j] && arr[j] <= mx) {
                cnt++;
            } else {
                
                ans = max(ans, cnt);
                cnt = 0;
            }
        }
        if(cnt != 0){
            ans = max(ans, cnt);
        }
    }
    cout << ans << '\n';
}