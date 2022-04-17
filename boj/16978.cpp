#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 100001
using namespace std;

ll a[MX];
ll tree[MX * 4];
ll ans[MX];

ll init(int node, int start, int end) {
    if (start == end)
        return tree[node] = a[start];
    int mid = (start + end) / 2;
    return tree[node] =
               init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

ll query(int node, int start, int end, int left, int right) {
    if (end < left || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) +
           query(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int idx, ll diff) {
    if (idx < start || idx > end)
        return;
    tree[node] += diff;
    if (start ^ end) {
        update(node * 2, start, (start + end) / 2, idx, diff);
        update(node * 2 + 1, (start + end) / 2 + 1, end, idx, diff);
    }
}

struct Query2{
    int idx, seq, s, e;

    bool operator<(Query2& x){
        return seq<x.seq;
    }
    
};

struct Query{
    int idx;
    ll diff;

};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i=1; i<=n;i++){
        cin >> a[i];
    }
    init(1,1,n);
    vector<Query2> q2;
    vector<Query> q1;
    int m;
    cin >> m;
    int z = 0;
    for(int i=0; i<m;i++){
        int k;
        cin >> k;
        if(k==1){
            int idx, t;
            cin >> idx >> t;
            ll diff = t-a[idx];
            a[idx] = t;
            q1.push_back({idx, diff});
        }else{
            int seq, s,e;
            cin >> seq >> s >>e;
            q2.push_back({z++,seq, s,e});
        }
    }
    sort(all(q2));
    bool chk[101010];
    int com = 0;
    for(int i=0; i<q2.size();i++){
        while(q2[i].seq != com){
            update(1,1,n,q1[com].idx, q1[com].diff);
            com++;
        }
        ans[q2[i].idx] =  query(1,1,n,q2[i].s, q2[i].e);
    }
    for(int i=0; i<q2.size();i++){
        cout << ans[i]<<'\n';
    }


}