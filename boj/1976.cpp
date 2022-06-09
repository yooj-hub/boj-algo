#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

int n, m, t;
int parent[201];

int find_parent(int x) {
    if (x == parent[x])
        return x;
    return parent[x] = find_parent(parent[x]);
}
void union_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if (parent[a] != parent[b])
        parent[a] = b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> t;
            if (i == j)
                continue;
            if (t)
                union_parent(i, j);
        }
    }
    int pv = -1;
    bool ok = true;
    for (int i = 1; i <= m; i++) {
        cin >> t;
        if (pv == -1) {
            pv = find_parent(t);
        } else {
            if (pv != find_parent(t))
                ok = false;
        }
    }
    if (ok)
        cout << "YES";
    else
        cout << "NO";
}