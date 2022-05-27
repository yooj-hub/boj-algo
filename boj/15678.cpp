#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

ll arr[MX * 2];
int n, d;
ll ans = -1e9+7;
deque<pair<ll, int>> dq;
priority_queue<pair<ll, int>, vector<pair<ll, int>>, less<>> pq;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) {
        while (!pq.empty() && pq.top().second < i - d)
            pq.pop();
        if (!pq.empty()) {
            pq.push({pq.top().first + arr[i], i});
        }
        pq.push({arr[i], i});
        ans = max(ans, pq.top().first);
    }
    cout << ans;
}