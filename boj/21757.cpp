#include<bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define ll long long int
#define MX 101010

using namespace std;

int n;
vector<int> arr;
vector<int> s;
vector<ll> ans;
int tmp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    arr.resize(n + 1, 0);
    s.resize(n + 1, 0);
    ans.resize(4, 0LL);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        s[i] = arr[i] + s[i - 1];
    }

    tmp = s[n] / 4;
    if (s[n] % 4) cout << 0;
    else {
        ans[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int cnt = 3; cnt >= 1; cnt--) {
                if (tmp * cnt == s[i]) {
                    ans[cnt] += ans[cnt - 1];
                }

            }
        }
        cout << ans[3];
    }

}