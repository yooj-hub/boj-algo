#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> parent(10005);

int findParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}


void unionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);

    if(a<b){
        parent[b] = a;
    }else{
        parent[a] = b;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int v,e;
    cin >> v >> e;
    int start, end, cost;
    vector<tuple<int,int,int>> edge;
    for(int i=0; i<e;i++){
        cin >> start >> end >> cost;
        edge.emplace_back(cost, start, end);
    }
    for(int i=0; i<v;i++){
        parent[i] = i;
    }
    sort(edge.begin(), edge.end());
    int answer = 0;
    for(int i=0; i<e;i++){
        int from, to, weight;
        tie(weight,to,from) = edge[i];
        if(findParent(from) == findParent(to)) continue;
        unionParent(from,to);
        answer += weight;
    }
    cout << answer << '\n';


}