#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;

vector<int> g[17];
vector<int> sheep_wolf;
int chk[17];
int dfs(int current, int sheep, int wolf, vector<int> path,int pre) {
    if (sheep_wolf[current])
        wolf++;
    else
        sheep++;
    if (sheep == wolf)
        return sheep;
    for (int x : g[current]) {
        if(x == pre) continue;
        path.push_back(x);
    }
    int ret = sheep;
    for (int i = 0; i < path.size(); i++) {
        if (chk[path[i]])
            continue;
        chk[path[i]] = true;
        ret = max(dfs(path[i], sheep, wolf, path, current), ret);
        chk[path[i]] = false;
    }
    return ret;
}

int solution(vector<int> info, vector<vector<int>> edges) {
    sheep_wolf = info;
    for (int i = 0; i < edges.size(); i++) {
        g[edges[i][0]].push_back(edges[i][1]);
        g[edges[i][1]].push_back(edges[i][0]);
    }
    chk[0] = true;
    vector<int> tmp;
    return dfs(0, 0, 0, tmp,-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << solution({0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1}, {{0, 1},
                                                            {1, 2},
                                                            {1, 4},
                                                            {0, 8},
                                                            {8, 7},
                                                            {9, 10},
                                                            {9, 11},
                                                            {4, 3},
                                                            {6, 5},
                                                            {4, 6},
                                                            {8, 9}})
         << '\n';
}