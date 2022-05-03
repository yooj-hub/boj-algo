#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 220202
#define INDEX second
#define COST first
using namespace std;
int n, m;

vector<pair<ll, ll>> g[MX];
vector<ll> path[MX];
vector<ll> res;
int chk[MX];
bool in[MX];
ll d[MX];
ll nt;

bool dfs(int current, int note) {
    if (current == 1) {
        if (note == nt) {
            res.push_back(current);
            return true;
        } else
            return false;
    }
    bool ret = false;
    for (auto &nxt : path[current]) {
        if (chk[nxt]) {
            ret = dfs(nxt, note + 1);
            if (ret) {
                res.push_back(current);
                break;
            }
        } else {
            ret = dfs(nxt, note);
            if (ret) {
                res.push_back(current);
                break;
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        g[from].push_back({cost, to});
        g[to].push_back({cost, from});
    }
    d[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        int current, dist;
        tie(dist, current) = pq.top();
        pq.pop();
        if (d[current] < dist)
            continue;
        for (auto nxt : g[current]) {
            if (!in[nxt.INDEX] || d[nxt.INDEX] > d[current] + nxt.COST) {
                d[nxt.INDEX] = d[current] + nxt.COST;
                pq.push({d[nxt.INDEX], nxt.INDEX});
                path[nxt.INDEX].clear();
                path[nxt.INDEX].push_back(current);
                in[nxt.INDEX] = true;
            } else if (d[nxt.INDEX] == d[current] + nxt.COST) {
                path[nxt.INDEX].push_back(current);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        if (t) {
            chk[i] = true;
            nt++;
        }
    }

    if (chk[n]) {
        if (dfs(n, 1)) {
            cout << res.size() << '\n';
            for (int i = 0; i < res.size(); i++) {
                cout << res[i] << ' ';
            }
        } else {
            cout << "-1\n";
        }
    } else {
        if (dfs(n, 0)) {
            cout << res.size() << '\n';
            for (int i = 0; i < res.size(); i++) {
                cout << res[i] << ' ';
            }
        } else {
            cout << "-1\n";
        }
    }
}