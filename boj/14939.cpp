#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;

int a[12][12];
int b[12][12];

void turn(int k) {
    for (int i = 0; i < 10; i++) {
        b[k][i] = 1 - b[k][i];
    }
}

pair<bool, int> solve(){
    int t = 0;
    for(int j=0; j<10;j++){
        int cnt = 1;
        for(int i=1; i<10;i++){
            if(b[i-1][j] == b[i][j]) cnt++;
        }
        if(cnt !=10){
            return {false, 0};
        }
        if(b[0][j] == 0) t++;   
    }
    return {true, t};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            char t;
            cin >> t;
            if (t == 'O')
                a[i][j] = 0;
            else
                a[i][j] = 1;
        }
    }
    int answer = -1;
    for (int i = 0; i < 1024; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                b[j][k] = a[j][k];
            }
        }
        int cnt = 0;

        for (int j = 0; j < 10; j++) {
            if (i & (1 << j)) {
                turn(j);
                cnt++;
            }
        }
        auto tmp = solve();

        if(!tmp.first) continue;
        if (answer == -1 || answer > tmp.second+cnt) {
            answer = tmp.second+cnt;
        }
    }
    cout << answer<<'\n';
}