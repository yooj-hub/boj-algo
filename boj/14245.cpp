#include <bits/stdc++.h>
#define ll long long int
#define MX 500001
#define all(x) x.begin(), x.end()

using namespace std;
int arr[MX];
int tree[MX * 4];
int lazy[MX * 4];
int init(int node, int start, int end) {
    if (start == end)
        return tree[node] = arr[start];
    return tree[node] = init(node * 2, start, (start + end) / 2) ^
                        init(node * 2 + 1, (start + end) / 2 + 1, end);
}

void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        if ((end - start + 1) & 1)
            tree[node] ^= lazy[node];
        if (start != end) {
            lazy[node * 2] ^= lazy[node];
            lazy[node * 2 + 1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}

void update_range(int node, int start, int end, int left, int right, int val) {
    update_lazy(node, start, end);
    if (left > end || right < start)
        return;
    if (left <= start && end <= right) {
        if ((end - start + 1) & 1)
            tree[node] ^= val;
        if (start != end) {
            lazy[node * 2] ^= val;
            lazy[node * 2 + 1] ^= val;
        }
        return;
    }
    update_range(node*2, start, (start+end)/2, left,right, val);
    update_range(node*2+1, (start+end)/2+1, end, left, right, val);
    tree[node] = tree[node*2] ^ tree[node*2+1];
}

int query(int node, int start, int end, int idx){
    update_lazy(node, start, end);
    if(idx< start || idx > end) return 0;
    if(start != end){
        return query(node*2, start, (start+end)/2, idx) ^ query(node*2+1, (start+end)/2+1, end, idx);
    }
    return tree[node];

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n;i++){
        cin >> arr[i];
    }
    init(1,0,n-1);
    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        if(x==1){
            int start, end, val;
            cin >> start >> end >> val;
            update_range(1,0,n-1, start, end, val);
        }else{
            int idx;
            cin >> idx;
            cout << query(1,0,n-1,idx)<<'\n';
        }
    }
}