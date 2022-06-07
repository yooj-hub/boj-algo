#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

int n;
vector<pair<int, int>> sbs;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    sbs.resize(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        sbs[i] = make_pair(a, b);
    }
    int answer = 0;

    sort(all(sbs), [&](pair<int, int> a, pair<int, int> b) -> bool {
        if (a.first == b.first) {
            return a.second < b.second;
        } else {
            if (a.first == 0) {
                return false;
            }
            if (b.first == 0) {
                return true;
            }
            double left = (double)a.second / a.first;
            double right = (double)b.second / b.first;
            return left < right;
        }
    });
    for (int i = 0; i < n; i++) {
        answer = (answer + (answer * sbs[i].first + sbs[i].second)) % 40000;
    }
    cout << answer;
}