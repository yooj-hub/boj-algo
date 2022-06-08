#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
set<int> a;
set<int> b;
int na, nb;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> na >> nb;
    while (na--) {
        int t;
        cin >> t;
        a.insert(t);
    }
    while (nb--) {
        int t;
        cin >> t;
        b.insert(t);
    }
    vector<int> res;
    for (auto iter =a.begin(); iter != a.end(); iter++) {
        if (b.find(*iter) == b.end())
            res.push_back(*iter);
    }
    cout << res.size() << '\n';
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << ' ';
    }
}