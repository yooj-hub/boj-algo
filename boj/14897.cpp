#include<bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 1010101
using namespace std;
int a[MX];
int sqrtN;
struct Query{
    int idx, s,e;
    bool operator <(Query& x){
        if(s/sqrtN != x.s/sqrtN) return s < x.s;
        return e< x.e;
    }
};
vector<Query> query;
int res = 0;
int cnt[MX];
int ans[MX];
void pl(int x){
    if(cnt[x] == 0) res++;
    cnt[x]++;
}
void mi(int x){
    cnt[x]--;
    if(cnt[x] == 0) res--;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    sqrtN = sqrt(n);
    map<int,int> ma;
    int k = 1;
    for(int i=1; i<=n;i++){
        int t;
        cin >> t;
        if(ma.find(t) == ma.end()){
            ma[t] = k++;
        }
        a[i] = ma[t];
    }

    int q;
    cin >> q;
    for(int i=0; i<q;i++){
        int s,e;
        cin >> s >> e;
        query.push_back({i,s,e});
    }
    sort(all(query));
    int s,e;
    s = 0; e=0;
    for(int i=0; i<q;i++){
        while(s<query[i].s)mi(a[s++]);
        while(s>query[i].s)pl(a[--s]);
        while(e>query[i].e)mi(a[e--]);
        while(e<query[i].e)pl(a[++e]);
        ans[query[i].idx] = res;
    }
    for(int i=0; i<q;i++){
        cout << ans[i]<<'\n';
    }
    
    


    
}