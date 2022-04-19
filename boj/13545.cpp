#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010
using namespace std;
const int sn = 400;
const int sz = MX/400 + 1;
int arr[MX];
int s[MX];
int bucket[sz];
int cnt[MX];

struct Query {
    int idx, s, e;
    bool operator<(Query &x) {
        if (s / sn != x.s / sn)
            return s < x.s;
        return e < x.e;
    }
};
vector<Query> queries;
int start,end;
void Plus(int idx, int dir){
    
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for(int i=1; i<=n;i++){
        s[i] = s[i-1]+arr[i];
    }
    int q;
    cin >> q;
    for(int i=0; i<q;i++){
        cin >> s >>e;
        queries.push_back({i,s,e});
    }
    sort(all(queries));

}