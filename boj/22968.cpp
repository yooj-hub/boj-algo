#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;

int d[44];
const int inf = 1e9+7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    d[0] = 0;
    d[1] = 1;
    for (int i = 2; i < 43; i++) {
        d[i] = d[i - 1] + d[i - 2] + 1;
    }
    d[43] = inf;
    int t;
    cin >> t;
    while (t--) {
        int a;
        cin >> a;
        int ans = 0;
        for(int i=1; i<=43; i++){
            if(d[i-1]<= a && a<=d[i]){
                ans = i-1;
            }
        }
        cout << ans <<'\n';
    }
}