#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int t;
int d[51];
int n;
bool chk[51];
set<int> s;
vector<int> seq;
const int inf = 1e9+7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--) {
        memset(d, 0, sizeof(d));
        memset(chk, false, sizeof(chk));
        seq.clear();
        cin >> n;
        int mn = inf;
        int mn_idx=-1 ;
        for (int i = 1; i <= n; i++) {
            cin >> d[i];
            if(d[i] < mn){
                mn = d[i];
                mn_idx = i;
            }
        }
        bool ok = true;
        int pos = 1;
        if(n&1){
            cout << "Mike\n";
        }else{
            if(mn_idx&1){
                cout << "Joe\n";
            }else{
                cout << "Mike\n";
            }

        }

    }
}
