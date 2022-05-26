#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int n, val;
string op;
stack<int> stk;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    while (n--) {
        cin >> op;
        if (op == "push") {
            cin >> val;
            stk.push(val);
        } else if (op == "pop") {
            if (stk.empty()) {
                cout << "-1\n";
            } else {
                cout << stk.top() << '\n';
                stk.pop();
            }
        } else if (op == "size") {
            cout << stk.size() << '\n';
        } else if (op == "empty") {
            cout << stk.empty() << '\n';
        } else {
            if (stk.empty())
                cout << "-1\n";
            else
                cout << stk.top() << '\n';
        }
    }
}