#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

int t, n;
priority_queue<ll, vector<ll>, greater<>> pq;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        while (n--) {
            int x;
            cin >> x;
            pq.push(x);
        }
        ll answer = 0LL;
        while (!pq.empty()) {
            if (pq.size() == 1) {
                pq.pop();
                break;
            }
            ll first = pq.top();
            pq.pop();
            ll second = pq.top();
            pq.pop();
            answer = answer + first + second;
            pq.push(first + second);
        }
        cout << answer << '\n';
    }
}