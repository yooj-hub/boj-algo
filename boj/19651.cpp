#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
ll arr[MX];
ll tree[MX * 4];
ll lazy[MX * 4];
ll lazy2[MX * 4];
int cnt[202020];

ll init(int node, int start, int end) {
    if (start == end) {
        return tree[node] = arr[start];
    }
    int mid = (start + end) / 2;
    return tree[node] =
               init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * (end - start) / 2 * lazy[node];
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (lazy2[node] != 0) {
        tree[node] += (end - start + 1) * lazy2[node];
        if (start != end) {
            lazy2[node * 2] += lazy2[node];
            lazy2[node * 2 + 1] += lazy2[node];
        }
        lazy2[node] = 0;
    }
}

void update_range(int node, int start, int end, int left, int right, int v1,
                  int v2) {
    update_lazy(node, start, end);
    if (left > end || right < start)
        return;
    if (left <= start && end <= right) {
        lazy[node] = v2;
        lazy2[node] = v1;
        update_lazy(node, start, end);
        return;
    }
    update_range(node * 2, start, (start + end) / 2, left, right, v1, v2);
    update_range(node * 2 + 1, (start + end) / 2 + 1, end, left, right, v1, v2);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int node, int start, int end, int left, int right, ll val) {
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right) {
        if (start == end)
            if (tree[node] == val) {
                return start;
            } else {
                return 0;
            }
    }
    ll left_result =
        query(node * 2, start, (start + end) / 2, left, right, val);
    ll right_result =
        query(node * 2, (start + end) / 2 + 1, end, left, right, val);
    if (left_result == 0)
        return right_result;
    if (right_result == 0)
        return left_result;
    return min(left_result, right_result);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}