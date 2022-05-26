#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int t, a, b, c, d;
string s;
map<tuple<int, int, int, int>, int> mp;
int solve(int idx, int A, int B, int AB, int BA) {
    int &answer = mp[{A, B, AB, BA}];
    if (answer != 0)
        return answer;
    if (idx == s.size())
        return answer = 1;
    answer = -1;

    if (s[idx] == 'A') {
        if (A >= 1) {
            if (solve(idx + 1, A - 1, B, AB, BA) == 1) {
                answer = 1;
            }
        }

        if (idx + 1 < s.size() && AB >= 1 && s[idx + 1] == 'B') {
            if (solve(idx + 2, A, B, AB - 1, BA) == 1) {
                answer = 1;
            }
        }
    }
    if (s[idx] == 'B') {
        if (B >= 1) {
            if (solve(idx + 1, A, B - 1, AB, BA) == 1) {
                answer = 1;
            }
        }

        if (idx + 1 < s.size() && BA >= 1 && s[idx + 1] == 'A') {
            if (solve(idx + 2, A, B, AB, BA - 1) == 1) {
                answer = 1;
            }
        }
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--) {
        mp.clear();
        cin >> a >> b >> c >> d;
        cin >> s;
        if (solve(0, a, b, c, d) == 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}