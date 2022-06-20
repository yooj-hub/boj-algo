#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

int n, q, l,r;
ll t;
ll arr[MX];
ll sum_tree[MX * 4];
ll sum_lazy[MX * 4];
ll tree[MX * 4];



ll sum_init(int node, int start, int end) {
    if (start == end)
        return sum_tree[node] = arr[start];
    int mid = (start + end) >> 1;
    return sum_tree[node] = sum_init(node * 2, start, mid) +
                            sum_init(node * 2 + 1, mid + 1, end);
}

void update_lazy(int node, int start, int end) {
    if (sum_lazy[node] == 0)
        return;
    sum_tree[node] += sum_lazy[node] * (end - start + 1);
    if (start != end) {
        sum_lazy[node * 2] += sum_lazy[node];
        sum_lazy[node * 2 + 1] += sum_lazy[node];
    }
    sum_lazy[node] = 0;
    return;
}

void update_range(int node, int start, int end, int left, int right, ll val) {
    update_lazy(node, start, end);
    if (start > right || left > end)
        return;
    if (left <= start && end <= right) {
        sum_lazy[node] += val;
        update_lazy(node, start, end);
        return;
    }
    update_range(node * 2, start, (start + end) / 2, left, right, val);
    update_range(node * 2 + 1, (start + end) / 2 + 1, end, left, right, val);
    sum_tree[node] = sum_tree[node * 2] + sum_tree[node * 2 + 1];
}

ll sum_query(int node, int start, int end, int left, int right) {
    update_lazy(node, start, end);
    if (start > right || left > end) {
        return 0LL;
    }
    if (left <= start && end <= right)
        return sum_tree[node];
    return sum_query(node * 2, start, (start + end) / 2, left, right) +
           sum_query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

ll init(int node, int start, int end) {
    if (start == end)
        return tree[node] = arr[start] - arr[start-1];
    int mid = (start + end) >> 1;
    return tree[node] = __gcd(init(node * 2, start, mid),
                              init(node * 2 + 1, mid + 1, end));
}



void update(int node, int start, int end, int idx, int val) {
    if (start > idx || end < idx)
        return;
    tree[node] += val;
    if (start == end)
        return;
    update(node * 2, start, (start + end) / 2, idx, val);
    update(node * 2 + 1, (start + end) / 2 + 1, end, idx, val);
}

ll query(int node, int start, int end, int left, int right) {
    if (start > right || left > end)
        return 0LL;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return __gcd(query(node * 2, start, mid, left, right),
                 query(node * 2+1, mid + 1, end, left, right));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    sum_init(1, 1, n);
    init(1, 1, n);
    cin >> q;
    while (q--) {
        cin >> t;
        if (t == 0) {
            cin >> l >> r;
            ll first = sum_query(1,1,n,l,l);
            // cout << "first : " <<first<<endl;
            // cout << "query : " <<query(1,1,n,l+1,r)<<endl;
            if(l == r){
                cout << first<<'\n';
            }else{
                cout << abs(__gcd(first, query(1,1,n,l+1,r)))<<'\n';
            }
        }else{
            cin >> l >> r;
            update_range(1,1,n,l,r,t);
            update(1,1,n,l,t);
            update(1,1,n,r+1,-t);
        }
    }
}