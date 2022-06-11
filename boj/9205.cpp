#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010
#define x first
#define y second

using namespace std;
int t, n;
vector<pair<int, int>> place;
bitset<102> chk;
queue<pair<int, int>> q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--) {
        int a, b;
        cin >> n;
        chk.reset();
        place.clear();
        for (int i = 0; i < n + 2; i++) {
            cin >> a >> b;
            place.push_back({a, b});
        }
        chk[0] = 1;
        q.push({place[0].x, place[0].y});
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (int i = 1; i < place.size(); i++) {
                if (chk[i])
                    continue;
                auto nxt = place[i];
                int val = abs(cur.x - nxt.x) + abs(cur.y - nxt.y);
                if (val > 1000)
                    continue;
                chk[i] = 1;
                q.push(nxt);
            }
        }
        if (chk[n + 1]) {
            cout << "happy\n";
        } else {
            cout << "sad\n";
        }
    }
}