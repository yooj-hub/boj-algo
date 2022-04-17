#include<bits/stdc++.h>

using namespace std;
vector<int> dfs_order;
vector<int> first;
vector<int> level;
vector<int> a[100001];

void init(vector<int> &tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = start;
    } else {
        init(tree, node * 2, start, (start + end) / 2);
        init(tree, node * 2 + 1, (start + end) / 2 + 1, end);

        if (level[tree[node * 2]] < level[tree[node * 2 + 1]]) {
            tree[node] = tree[node * 2];
        } else {
            tree[node] = tree[node * 2 + 1];
        }
    }
}

int query(vector<int> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) return -1;
    if (left <= start && end <= right) return tree[node];

    int m1 = query(tree, node * 2, start, (start + end) / 2, left, right);
    int m2 = query(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);

    if (m1 == -1) return m2;
    if (m2 == -1) return m1;
    if (level[m1] < level[m2]) return m1;
    return m2;


}

void dfs(int node, int parent, int depth) {
    dfs_order.push_back(node);
    level.push_back(depth);
    for (int child : a[node]) {
        if (child == parent) continue;
        dfs(child, node, depth + 1);
        dfs_order.push_back(node);
        level.push_back(depth);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(u);
        a[v].push_back(v);

    }
    first.resize(n + 1, -1);
    dfs(1, 0, 0);
    for (int i = 0; i < dfs_order.size(); i++) {
        int node = dfs_order[i];
        if (first[node] == -1) {
            first[node] = i;
        }
    }
    n = dfs_order.size();
    int h = (int) ceil(log2(n));
    int tree_size = (1<<h+1);
    vector<int> tree(tree_size);
    init(tree,1,0,n-1);
    int m;
    cin >> m;
    while(m--){
        int u,v;
        cin >> u >> v;
        int i = first[u];
        int j = first[v];
        if(i>j) swap(i,j);
        int lca = query(tree,1,0,n-1,i,j);
        cout << dfs_order[lca] << '\n';
    }
    return 0;
}