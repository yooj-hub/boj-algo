#include <bits/stdc++.h>

using namespace std;
const int inf = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int x, y;

    int a, b, n, m;

    cin >> n >> m;
    cin >> a >> b >> x >> y;
    a--;
    b--;
    vector<int> r(m+1);
    int d[502][101];
    for (int i = 1; i <= m; i++) {
        cin >> r[i];
        r[i] --;
    }
    for (int i = 0; i < 501; i++) {
        fill(d[i], d[i] + 101, inf);
    }
    for(int i=0; i<n;i++){
        d[0][i] = abs(i-a) * y;
    }
    for(int i=1; i<=m;i++){
        for(int j=0; j<n;j++){
            for(int k=0; k<n;k++){
                // 지우고 내려가기
                if(k==j && (r[i] == k || r[i]+1 == k)){
                    d[i][j] = min(d[i][j], d[i-1][k] + x);
                
                }
                //  좌우로 이동 (사다리 있으면 타고)
                else if((k<= r[i] && r[i] <= j-1) || (j<=r[i] && r[i] <=k-1)){
                    d[i][j] = min(d[i][j], d[i-1][k]+(abs(k-j)-1)* y);
                }
                // 아래로 이동
                else{
                    d[i][j] = min(d[i][j], d[i-1][k] + abs(k-j)*y);
                }

            }

        }
    }
    cout << d[m][b];

    

    
}