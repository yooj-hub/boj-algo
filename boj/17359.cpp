#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int n;
const int inf = 1e9 + 7;
vector<string> s;
bool chk[10];
int ans = inf;

void dfs(int idx, char end, int val) {
    if (idx == n) {
        ans = min(ans, val);

        return;
    }
    for (int i = 0; i < n; i++) {
        if (chk[i])
            continue;
        chk[i] = true;
        int tmp = 0;
        
        if (end != s[i][0] && end != '2')
            tmp++;

        for (int j = 1; j < s[i].size(); j++) {
            if (s[i][j] != s[i][j - 1])
                tmp++;
        }
        dfs(idx + 1, s[i][s[i].size() - 1], val + tmp);
        chk[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    s.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    dfs(0, '2', 0);

    cout << ans << '\n';
}