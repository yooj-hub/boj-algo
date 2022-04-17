#include<bits/stdc++.h>

#define MX 100001


using namespace std;

int tin[MX];
int tout[MX];
int timer;
int p[MX][20];
int l;
vector<int> a[MX];

void dfs(int v, int parent) {
    tin[v] = ++timer;
    p[v][0] = parent;

    for (int i = 1; i <= l; i++) {
        p[v][i] = p[p[v][i - 1]][i - 1];
    }
    for(int to : a[v]){
        if(to!= parent){
            dfs(to,v);
        }

    }
    tout[v] = ++timer;
}


// u 가 v 의 조상인가
bool upper(int u, int v){
    return (tin[u] <= tin[v] && tout[v] <= tin[u]);
}

int lca(int u, int v){
    if(upper(u,v)) return u;
    if(upper(v,u)) return v;
    for(int i=l; i>=0; i--){
        if(!upper(p[u][i],v)){
            u = p[u][i];
        }
    }
    return p[u][0];

}


int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);


}