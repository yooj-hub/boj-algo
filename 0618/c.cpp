#include<bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

int t,n,m;
int a[1001][1001];
int b[1001][1001];
map<tuple<int,int,int>,bool> mp;

bool go(int x, int y, int val){
    if(mp.find({x,y,val})!= mp.end()) return mp[{x,y,val}];
    bool &ans = mp[{x,y,val}];
    ans = false;
    if(x == n && y== m){
        if(val == 0) return ans = true;
        else return ans = false;
    }
    if(x != n){
        ans |= go(x+1, y, val + a[x+1][y]);
    }
    if(ans) return ans;
    if(y !=m){
        ans |= go(x, y+1, val + a[x][y+1]);
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while(t--){
        cin >> n >> m;
        mp.clear();
        for(int i=1; i<=n; i ++){
            for(int j=1; j<=m; j++){
                cin >> a[i][j];
            }
        }
        cout<<(go(1,1, a[1][1])? "YES\n":"NO\n");

    }
    
}