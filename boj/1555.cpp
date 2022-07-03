#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
set<int> d[1 << 6];
int arr[6];
int n;

const int inf = 1e9 + 7;

bool isPrime(int x) {
    if (x < 2)
        return false;
    if(x == 2) return true;
    if(x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i+=2) {
        if (!(x % i))
            return false;
    }
    return true;
}

set<int> solve(int mask) {
    set<int> &ans = d[mask];
    if (ans.size() > 0)
        return ans;
    if (mask == 0)
        return ans;
    
    for (int i = 0; i < (1 << n); i++) {
        int first = mask & i;
        int second = mask & (~first);
        if (first == 0 || second == 0)
            continue;
        solve(first);
        solve(second);
        for (int x : d[first]) {
            for (int y : d[second]) {
                if (x != 0) {
                    ans.insert(y / x);
                }
                if (y != 0) {
                    ans.insert(x / y);
                }
                ans.insert(x + y);
                ans.insert(x - y);
                ans.insert(y - x);
                ans.insert(x * y);
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        d[1<<i].insert(arr[i]);
    }
    solve((1 << n) - 1);
    int mx = -inf;
    int mn = inf;
    for(int x : d[(1<<n)-1]){
        if(isPrime(x)){
            mx = max(mx, x);
            mn = min(mn, x);
        }
    }
    if(mx == -inf){
        cout << -1;
    }else{
        cout << mn <<'\n';
        cout << mx <<'\n';
    }
    
}