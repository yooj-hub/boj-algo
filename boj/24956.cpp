#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 201010

using namespace std;
ll n;
const ll inf = 1e9 + 7;
string s;
int w[MX];
int h[MX];
int e[MX];
int b[MX];
int ans = 0;
int w_cnt, h_cht, e_cnt;
int d[MX];
int mx;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'W')
            w[i] = ++w_cnt;
        else if (s[i] == 'H')
            h[i] = ++h_cht;
        else if (s[i] == 'E')
            ++e_cnt;
    }
    mx = e_cnt;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'E')
            e[i] = e_cnt--;
    }

}