#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 255555
using namespace std;

ll tree[(1 << 18)];
int arr[MX];
int sz = (1<<16);
void update(int node, int start, int end, int idx, int val) {
    if (idx < start || idx > end)
        return;
    tree[node]+=val;
    if (start != end) {
        update(node * 2, start, (start + end) / 2, idx, val);
        update(node * 2 + 1, (start + end) / 2 + 1, end, idx, val);
    }
}

ll query(int node, int start, int end, int k) {
    if (start == end)
        return start;
    if (tree[node * 2] < k)
        return query(node * 2 + 1, (start + end) / 2 + 1, end,
                     k - tree[node * 2]);
    return query(node * 2, start, (start + end) / 2, k);
}

int n, k;
ll ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        update(1,0,sz,arr[i],1);
        if(i<k) continue;
        ans += query(1,0,sz,(k+1)/2);
        update(1,0,sz,arr[i-k+1],-1);
    }
    cout << ans;
}