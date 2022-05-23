#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int n;
ll k;
ll d[12];
vector<int> res;

void go(int idx, ll k){
    if(idx == 0) return;
    if(k <= d[idx-1]){
        res.push_back(1);
        go(idx-1, k);
    }else if(k <= d[idx-1] + d[idx-2]){
        res.push_back(2);
        go(idx-2, k-d[idx-1]);
    }else if(k<= d[idx-1] + d[idx-2] + d[idx-3]){
        res.push_back(3);
        go(idx-3, k-d[idx-1] -d[idx-2]);
    }else{
        res.push_back(-1);
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> k;
    d[0] = 1;
    d[1] = 1;
    d[2] = 2;
    for(int i=3; i<=n; i++){
        d[i] = d[i-1] + d[i-2]+d[i-3];
    }
    go(n,k);
    for(int i=0; i<res.size(); i++){
        if(i != res.size()-1)
        cout << res[i]<<'+';
        else{
            cout << res[i];
        }
    }
    
}