#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

int n, val;
string op;
deque<int> dq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    while (n--) {
        cin >> op;
        if (op == "push_front") {
            cin >> val;
            dq.push_front(val);
        }
        if (op == "push_back") {
            cin >> val;
            dq.push_back(val);
        }
        if (op == "pop_front") {
            if (dq.empty()) {
                cout << "-1\n";
            } else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }

        if (op == "pop_back") {
            if (dq.empty()) {
                cout << "-1\n";
            } else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }

        if (op == "size") {
            cout << dq.size() << '\n';
        }
        if (op == "empty") {
            cout << dq.empty() << '\n';
        }
        if (op == "front") {
            if (dq.empty()) {
                cout << "-1\n";
            } else
                cout << dq.front() << '\n';
        }
        if (op == "back") {
            if (dq.empty()) {
                cout << "-1\n";
            } else
                cout << dq.back() << '\n';
        }
    }
}