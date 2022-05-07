#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;
int d[5001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {

        if (i == 0) {
            if (s[i] - '0' == 0) break;
                d[i] = 1;
        } else if (i >= 1) {
            int one = s[i] - '0';
            int two = one + (s[i - 1] - '0') * 10;
            if (one != 0)
                d[i] = d[i - 1];
            if (10<=two&&two <= 26) {
                if (i - 2 < 0)
                    d[i] += 1;
                else {
                    d[i] += d[i - 2];
                }
            }
        }
        d[i] %= 1000000;
    }
    cout << d[s.size() - 1];

}