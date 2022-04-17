#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> a;


const ll mod = 1e9+7;

ll pw(ll x, ll y){
    ll ret = 1;
    while(y){
        if(y&1) ret = ret * x %mod;
        y >>=1;
        x = x* x%mod;
    }
    return ret;
}




int main(){
    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    a.resize(n);
    for(int i=0; i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = 0LL;
    for(int i=0; i<n;i++){

        ll cnt = pw(2,i)-1LL;
        ans += ((a[i]%mod)* cnt%mod);
        ll mncnt = pw(2, n-i-1)-1LL;
        ans -= ((a[i]%mod) * mncnt %mod);
        ans =(ans+mod)%mod;


    }
    cout << ans<<'\n';

}
