#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

ll d[51][51];
int n;
ll k;
vector<char> res;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    d[0][0] = 1;
    for(int i=1; i<=n; i++){
        d[0][i] = 0;
    }
    for(int i=1; i<=n; i++){
        d[i][0] = d[i-1][1];
        for(int j=1; j<=n; j++){
            d[i][j] = d[i-1][j-1];
            if(j+1<=n){
                d[i][j] += d[i-1][j+1];
            }
        }
    }
    if(k >= d[n][0]){
        cout <<-1;
        return 0;
    }
    int open = 0;
    for (int i = n; i >= 1; i--) {
        if (open == 0) {
            cout << '(';
            open++;
        } else {
            if (k < d[i - 1][open + 1]) {
                cout << '(';
                open++;
            } else {
                cout << ')';
                k -= d[i - 1][open + 1];
                open--;
            }
        }
    }
}