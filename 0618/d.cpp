#include<bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 4040

using namespace std;
    int t;
int n,x,y;
vector<int> g[MX];
const int inf = 1e9+7;
int find_height(int root){
    queue<tuple<int,int,int>> q;
    q.push({root, -1, 0});
    int h = -inf;
    while(!q.empty()){
        int cur, par, ch;
        tie(cur, par, ch) = q.front();
        q.pop();
        h = max(ch, h);
        for(auto nxt : g[cur]){
            if(nxt == par) continue;
            q.push({nxt, cur, ch+1});
        }
    }
    return h;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=1; i<=n-1; i++){
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        if(n==1){
            cout << "0\n";
        }else if(n==2){
            cout << "1\n";
        }else{
            int root = -1;
            int height = inf;
            for(int i=1; i<=n; i++){
                int th = find_height(i);
                if(th < height){
                    root = i;
                    height = th;
                }
            }
            
        }

        

    }
    
}