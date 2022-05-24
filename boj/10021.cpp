#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 2001
#define x first
#define y second

using namespace std;
int n;
int c;
int parent[MX];
int get_distance(pair<int, int> &a, pair<int, int> &b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int find_parent(int cur) {
    if (cur == parent[cur])
        return cur;
    return parent[cur] = find_parent(parent[cur]);
}

void union_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if (a > b) {
        parent[a] = b;
    } else {
        parent[b] = a;
    }
}

vector<pair<int, int>> points;
vector<tuple<int, int, int>> edges;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        points.push_back({a, b});
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dist = get_distance(points[i], points[j]);
            if(dist < c) continue;
            edges.push_back({dist, i, j});
        }
    }
    sort(all(edges));
    for (int i = 0; i < points.size(); i++) {
        parent[i] = i;
    }
    int ans = 0;
    for (auto cur : edges) {
        int dist, p1, p2;
        tie(dist, p1, p2) = cur;
        if (find_parent(p1) == find_parent(p2))
            continue;
        ans += dist;
        union_parent(p1, p2);
    }
    bool ok = true;
    int pv = find_parent(0);
    for (int i = 1; i < n; i++) {
        if (pv != parent[i])
            ok = false;
    }

    if (ok) {
        cout << ans;
    } else {
        cout << -1;
    }
}