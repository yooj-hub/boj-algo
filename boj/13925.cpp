#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010
using namespace std;
const int mod = 1e9 + 7;
ll tree[MX * 4];
ll lazy[MX * 4];
int arr[MX];

ll init(int node, int start, int end) {
    if (start == end)
        return tree[node] = arr[start];
    return tree[node] = (init(node * 2, start, (start + end) / 2) % mod +
                         init(node * 2 + 1, (start + end) / 2 + 1, end) % mod) %
                        mod;
}

void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] = (tree[node] + (lazy[node] * (end - start)) % mod) % mod;
        if(start != end){
            lazy[node*2] = lazy[node];
            lazy[node*2+1] = lazy[node];
        }
        lazy[node] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}