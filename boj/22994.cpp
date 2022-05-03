#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;
vector<string> s;
const int inf = 1e9 + 7;
int ans = inf;
int ax = 0;
int ay = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    s.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    for (int ni = 1; ni <= n; ni++) {
        for (int mi = 1; mi <= m; mi++) {
            if (m % mi)
                continue;
            if (n % ni)
                continue;
            int nn = n / ni;
            int mm = m / mi;
            bool ok = true;
            for (int i = 0; i < n; i += ni) {
                for (int j = 0; j < m; j += mi) {
                    char c = s[i][j];
                    for (int x = 0; x < ni; x++) {
                        for (int y = 0; y< mi; y++) {
                            if (c != s[i + x][j + y])
                                ok = false;
                        }
                    }
                }
            }
            if (ok) {
                if (ans > nn * mm) {
                    ans = nn * mm;
                    ax = nn, ay = mm;
                }
            }
        }
    }
    cout << ax << ' ' << ay << '\n';
    int ni = n/ax;
    int mi = m/ay;
    for(int i=0; i<n; i+= ni){
        for(int j=0; j<m; j+=mi){
            cout << s[i][j];
        }
        cout <<'\n';
    }

}