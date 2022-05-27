#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
deque<pair<int, int>> dq;
int n, s, x;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        while (!dq.empty() && dq.front().second < i - s + 1)
            dq.pop_front();
        while (!dq.empty() && dq.back().first >= x)
            dq.pop_back();
        dq.emplace_back(x, i);
        cout << dq.front().first << '\n';
    }
}