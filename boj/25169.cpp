#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

ll n;
struct Work {
    ll r, s;
};

vector<Work> works;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        works.push_back({a, b});
    }
    sort(all(works), [](Work &a, Work &b) {
        return a.s *(a.r+1)*(a.r)/2*b.r- b.s*(b.r+1)*(b.r)/2*(a.r)>0;
    });
    ll ans = 0;
    ll tot = 0;
    for (auto w : works) {
        ans += w.s/10LL * (w.r * (w.r+1LL)/2LL*(9LL + tot) +  (2LL*w.r +1LL)* w.r *(w.r+1LL)/6LL);
        tot += w.r;
    }
    cout << ans;
}