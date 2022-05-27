#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int k, n;
priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> pq;
int ans[MX * 3];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> k >> n;
    bool ok = true;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        pq.push({val, i + 1});
    }
    int pv = -1;
    for (int i = 0; i < k; i++) {
        if (pv == pq.top().second) {
            if (pq.size() == 1) {
                ok = false;
                break;
            } else {
                auto tmp = pq.top();
                pq.pop();
                auto nxt = pq.top();
                pq.pop();
                ans[i] = nxt.second;
                nxt.first--;
                pq.push(tmp);
                if (nxt.first)
                    pq.push(nxt);
                pv = nxt.second;
            }
        } else {
            auto tmp = pq.top();
            pq.pop();
            tmp.first--;
            ans[i] = tmp.second;
            if (tmp.first)
                pq.push(tmp);
            pv = tmp.second;
        }
    }
    if(ok)
    for (int i = 0; i < k; i++) {
        cout << ans[i]<<' ';
    }else{
        cout << -1;
    }
}