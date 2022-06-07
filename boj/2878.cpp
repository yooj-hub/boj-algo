#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010
#define INT __int128_t
using namespace std;

__int128_t pw(int k) {
    __int128_t ret = 1;
    __int128_t base = 2;
    while (k) {
        if (k & 1)
            ret *= base;
        base *= base;
        k>>=1;
    }
    return ret;
}

vector<INT> arr;
unsigned long long m, n, tot;
INT MOD = pw(64);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> m >> n;
    int mx = -1;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        arr.push_back(t);
        tot += arr[i];
    }
    if(tot < m){
        cout << 0 <<'\n';
        return 0;
    }
    tot -=m;
    sort(all(arr));
    INT answer = 0;
    for (int i = 0; i < n; i++) {
        INT tmp = min(arr[i], tot/(__int128_t)(n-i));
        answer += tmp * tmp;
        tot -= tmp;
    }
    unsigned long long ans = answer % MOD;
    cout << ans;
}