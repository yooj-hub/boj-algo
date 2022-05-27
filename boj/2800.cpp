#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

vector<string> ans;
vector<pair<int, int>> candi;
string s;
stack<int> stk;
bool chk[MX];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            stk.push(i);
        }
        if (s[i] == ')') {
            int x = stk.top();
            stk.pop();
            candi.push_back({x, i});
        }
    }
    int cs = candi.size();
    for (int i = 1; i < (1 << cs); i++) {
        memset(chk, false, sizeof(chk));
        
        for (int j = 0; j < cs; j++) {
            if (i & (1 << j)) {
                chk[candi[j].first] = true;
                chk[candi[j].second] = true;
            }
        }
        string tmp = "";
        for (int j = 0; j < s.size(); j++) {
            if (chk[j])
                continue;
            tmp += s[j];
        }
        ans.push_back(tmp);
    }
    sort(all(ans));
    ans.erase(unique(all(ans)), ans.end());
    for (auto &x : ans) {
        cout << x << '\n';
    }
}