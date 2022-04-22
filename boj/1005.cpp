#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int degree[1001];
        vector<int> g[1001];
        memset(degree, 0, sizeof(degree));
        vector<int> times(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> times[i];
        }
        for (int i = 0; i < k; i++) {
            int from, to;
            cin >> from >> to;
            g[to].push_back(from);
        }
        int target;
        cin >> target;
        queue<int> qq;
        qq.push(target);
        bool chk[1001][1001];
        memset(chk, false, sizeof(chk));
        while (!qq.empty()) {
            int current = qq.front();
            qq.pop();
            for (auto &nxt : g[current]) {
                if (chk[nxt][current])
                    continue;
                chk[nxt][current] = true;

                degree[nxt]++;
                qq.push(nxt);
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.push({times[target], target});
        int answer = times[target];
        while (!q.empty()) {
            int current_time, current;
            tie(current_time, current) = q.top();
            answer = max(current_time, answer);
            q.pop();
            for (auto &nxt : g[current]) {
                degree[nxt]--;
                if (degree[nxt] == 0) {
                    q.push({current_time + times[nxt], nxt});
                }
            }
        }
        cout << answer << "\n";
    }
}