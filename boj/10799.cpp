#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
stack<int> stk;
string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            stk.push(i);
        else {
            if (stk.top() == i - 1) {
                stk.pop();
                ans += stk.size();
            } else {
                stk.pop();
                ans++;
            }
        }
    }
    cout << ans << '\n';
}