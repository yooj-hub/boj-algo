#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int n, cnt;
string s;
bool ok;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    while (n--) {
        cnt = 0;
        ok = true;
        cin >> s;
        for (char &x : s) {
            if (x == '(')
                cnt++;
            else
                cnt--;
            if (cnt < 0)
                ok = false;
        }
        if (ok && cnt == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}