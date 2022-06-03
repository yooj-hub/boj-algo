#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;
char board[11][11];
int n, m;
int d[10][1 << 10];

bool isset(int state, int i) { return (state & (1 << i)) > 0; }

bool check(int row, int state) {
    if (row < 0)
        return true;
    for (int j = 0; j < m - 1; j++) {
        if (isset(state, j) && isset(state, j + 1)) {
            return false;
        }
    }
    for (int j = 0; j < m; j++) {
        if (board[row][j] == 'x' && isset(state, j)) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> board[i];
        }
        memset(d, 0, sizeof(d));
        int answer = 0;
        for (int l = 0; l < n; l++) {
            for (int k = 0; k < (1 << m); k++) {
                if(!check(l, k)) continue;
                for(int i=0; i<(1<<m); i++){
                    if(!check(l-1, i)) continue;
                    int cnt = 0;
                    bool ok = true;
                    for(int j=0; j<m; j++){
                        if(isset(k, j)){
                            cnt++;
                            if(j-1 >=0 && isset(i, j-1)) ok = false;
                            if(j+1<m && isset(i,j+1)) ok = false;
                        }
                    }
                    if(ok){
                        if(l == 0){
                            d[l][k] = max(d[l][k], cnt);
                        }else{
                            d[l][k] = max(d[l][k], d[l-1][i] + cnt);
                        }
                    }
                }
            }
                
        }
        for(int i=0; i<(1<<m); i++){
            if(answer < d[n-1][i]){
                answer = d[n-1][i];
            }
        }
        cout << answer << '\n';
    }
}