#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int n, m;
int d[300][(1 << 15)];

int go(int num, int state) {
    if (num == n * m && state == 0) {
        return 1;
    }
    if (num >= n * m) {
        return 0;
    }
    int &ans = d[num][state];
    if(ans != -1) return ans;
    ans = 0;
    if(state & 1)ans = go(num+1, (state>>1));
    else{
        ans = go(num+1, (state >>1)|(1<<(m-1)));
        if((num%m) != m-1 && (state &2) == 0){
            ans += go(num+2, (state>>2));
        }
    }
    ans %= 9901;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    memset(d, -1, sizeof(d));
    cout << go(0, 0) << '\n';
}