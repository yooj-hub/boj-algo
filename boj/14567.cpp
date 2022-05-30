#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

vector<int> g[1001];
int in[1001];
int chk[1001];
int n, m;
queue<int> q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        g[from].push_back(to);
        in[to]++;
    }
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
            chk[i] = 1;
        }
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto & x : g[cur]){
            if(chk[x]) continue;
            in[x]--;
            if(in[x] == 0){
                chk[x] = chk[cur]+1;
                q.push(x);
            }
        }

    }
    for(int i=1; i<=n; i++){
        cout << chk[i] <<' ';
    }
}