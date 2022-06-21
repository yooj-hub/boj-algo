#include<bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

int n,m;
ll arr[MX*10];
ll tree[MX*10];

void update(int x, ll val){
    while(x<=n){
        tree[x] += val;
        x += (x &(-x));
    }
}

ll sum(int x){
    ll ret = 0LL;
    while(x){
        ret += tree[x];
        x -= (x&(-x));
    }
    return ret;

}

ll query(int left, int right){
    return sum(right) - sum(left-1);
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int op;
        cin >> op;
        if(op == 0){
            int left, right;
            cin >> left >> right;
            if(right < left) swap(left, right);
            cout << query(left, right)<<'\n';
        }else{
            int idx;
            ll val;
            cin >> idx >> val;
            ll diff = val - arr[idx];
            arr[idx] = val;
            update(idx, diff);
        }
    }

    
}