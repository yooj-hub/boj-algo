#include<bits/stdc++.h>
#define MX 100001
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;

int sqrtN;
struct Query{
    int idx, s,e;

    bool operator < (Query & x){
        if(s/sqrtN != x.s/sqrtN) return s/sqrtN < x.s/sqrtN;
        return e < x.e;
        
    }

};


ll a[MX];
ll ans[MX];
ll cnt[1010101];
vector<Query> query;

ll res = 0LL;

void pl(ll x){
    res -= cnt[x] * cnt[x] * x;
    cnt[x]++;
    res+= cnt[x] * cnt[x] *x;
}

void mi(ll x){
    res-= cnt[x] * cnt[x] * x;
    cnt[x]--;
    res += cnt[x] * cnt[x] * x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,t;
    cin >> n>> t;
    sqrtN = sqrt(n);
    for(int i=1; i<=n;i++){
        cin >> a[i];
    }
    for(int i=0; i<t;i++){
        int s,e;
        cin >> s>> e;
        query.push_back({i,s,e});
    }
    sort(all(query));
    ll s,e;
    s=0;e=0;
    for(int i=0; i<t;i++){
        while(s<query[i].s)mi(a[s++]);
        while(s>query[i].s)pl(a[--s]);
        while(e>query[i].e)mi(a[e--]);
        while(e<query[i].e)pl(a[++e]);
        ans[query[i].idx] = res;
    }
    for(int i=0; i<t;i++){
        cout << ans[i] <<'\n';
    }


    
}