#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

vector<pair<int, int>> g;
int n, v,m, t;
bool ok;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v >> t;
        g[i] = {v, t};
    }
    cin >> m;

    for(int c =1; c<=m; c++){
        cin >> v >> t;
        ll cost = -1;
        for(int i=1; i<(1<<n); i++){
            ll tmp = 0;
            ll tc = 0;
            for(int j=0; j<n; j++){
                if(i&(1<<j) ){
                    tmp+= g[j].first;
                    tc += g[j].second;
                }
            }
            if(t>=v/tmp + (v%tmp != 0)){
                if(cost == -1 || cost > tc){
                    cost = tc;
                }
            }

        }
        
        cout <<"Case "<<c <<": "<<(cost == -1 ? "IMPOSSIBLE" : to_string(cost))<<'\n';



    }
}