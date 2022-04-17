#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        while (!(b == 0 && c == 0)) {
            int cnt = 0;
            while (b>=1 && b >= c) {
                cout << "R";
                cnt++;
                b--;
                if (cnt == 3) {
                    break;
                }
            }
            if (c) {
                cout << "B";
                c--;
            }
        }

        cout << '\n';
    }
}