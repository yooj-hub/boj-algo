#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int n, m;
map<string, int> mp;
vector<pair<int, string>> res;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        if ((int)t.size() < m)
            continue;
        mp[t]++;
    }
    for (auto iter = mp.begin(); iter != mp.end(); iter++)
        res.push_back({(*iter).second, (*iter).first});
    sort(all(res), [&](pair<int, string>& a, pair<int, string>& b) {
        if (a.first != b.first) {
            return a.first > b.first;
        }
        if (a.second.size() != b.second.size()) {
            return a.second.size() > b.second.size();
        }
        return a.second < b.second;
    });
    for (auto x : res) {
        cout << x.second << '\n';
    }
}