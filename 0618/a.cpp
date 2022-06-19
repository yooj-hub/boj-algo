#include<bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int t;
int n,m;
int d[41][41];
const int inf = 1e9+7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while(t--){
        cin >> n >> m;
        int row = 0;
        int col = 0;
        int mx = -inf;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cin >> d[i][j];
                if(mx < d[i][j]){
                    mx = d[i][j];
                    row = i;
                    col = j;
                }
            }
        }
        int answer = max(row, n-row+1) * max(col, m-col+1);
        cout << answer <<'\n';
        
        

        
    }
    
}