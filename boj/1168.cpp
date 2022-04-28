#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;

int n, k;
int tree[1 << 18];
int init(int node, int start, int end)
{
    if (start == end)
        return tree[node] = 1;
    int mid = (start + end) / 2;
    return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

void update(int node, int start, int end, int idx)
{
    if (idx < start || idx > end)
        return;
    tree[node]--;

    if (start ^ end)
    {
        update(node * 2, start, (start + end) / 2, idx);
        update(node * 2 + 1, (start + end) / 2 + 1, end, idx);
    }
}

int query(int node, int start, int end, int idx)
{
    if (start == end)
        return start;
    if (idx <= tree[2 * node])
        return query(2 * node, start, (start + end) / 2, idx);
    else
        return query(2 * node + 1, (start + end) / 2 + 1, end, idx - tree[2 * node]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    init(1, 1, n);
    int idx = 1;
    cout << "<";
    for (int i = 0; i < n; i++)
    {
        int sz = n - i;
        idx += k - 1;
        if (idx % sz == 0)
            idx = sz;
        else if (idx > sz)
            idx %= sz;

        int num = query(1, 1, n, idx);
        update(1, 1, n, num);
        if (i == n - 1)
            cout << num;
        else
            cout << num << ", ";
    }
    cout << ">";
}