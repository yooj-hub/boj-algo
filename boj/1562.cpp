#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
const int mod = 1e9;
ll n, d[101][1024][10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i < 10; i++) {
        d[1][(1 << i)][i] = 1;
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<10; j++){
            for(int k=0; k<1024; k++){
                if(d[i][k][j] == 0) continue;
                if((k & (1<<j)) == 0) continue;

                if(j+1<10){
                    d[i+1][k|(1<<(j+1))][j+1] = (d[i+1][k|(1<<(j+1))][j+1] + d[i][k][j])%mod;
                }
                if(j-1>=0){
                    d[i+1][k|(1<<(j-1))][j-1] = (d[i+1][k|(1<<(j-1))][j-1] + d[i][k][j])%mod;
                }

            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 10; i++) {
        ans = (ans + d[n][1023][i]) % mod;
    }
    cout << ans << '\n';
}