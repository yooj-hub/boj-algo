#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

int n, t;
vector<int> p;
deque<int> a;
deque<int> b;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        p.clear();
        p.resize(n);
        a.clear();
        b.clear();
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        if (n & 1) {
            cout << "NO\n";
            continue;
        }
        sort(all(p));
        int half = n / 2;
        bool ok = true;
        for (int i = 0; i < n / 2; i++) {
            a.push_back(p[i]);
            b.push_back(p[half + i]);
        }
        int cnt1 = 1;
        int cnt2 = 0;
        int pv = a.back();
        for (int i = a.size() - 2; i >= 0; i--) {
            if (pv == a[i])
                cnt1++;
            else
                break;
        }
        for (int i = 0; i < b.size(); i++) {
            if (pv == b[i])
                cnt2++;
            else
                break;
        }
        if (cnt1 + cnt2 >= half && cnt2 > 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                if ((i & 1) == 0)
                    cout << a[i / 2] << ' ';
                else
                    cout << b[i / 2] << ' ';
            }
            cout << '\n';
        }
    }
}