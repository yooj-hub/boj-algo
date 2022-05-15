#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int t, m, v;
vector<pair<int, int>> tree;
int d[10001][2];
const int inf = 30000;
int go(int idx, int val) {
    if (d[idx][val] != -1) {
        return d[idx][val];
    }
    if (idx > (m - 1) / 2) {
        if (val == tree[idx].first)
            return d[idx][val] = 0;
        else
            return d[idx][val] = inf;
    }
    int &ret = d[idx][val];
    int left_1 = go(idx * 2, 1);
    int left_0 = go(idx * 2, 0);
    int right_1 = go(idx * 2 + 1, 1);
    int right_0 = go(idx * 2 + 1, 0);
    int and_result = 0;
    int or_result = 0;

    if (val == 1) {
        and_result = left_1 + right_1;
    } else {
        and_result =
            min({left_0 + right_0, left_0 + right_1, left_1 + right_0});
    }
    if (val == 1) {
        or_result = min({left_1 + right_0, left_1 + right_1, left_0 + right_1});
    } else {
        or_result = left_0 + right_0;
    }

    if (tree[idx].second == 1) {
        if (tree[idx].first == 1) {
            ret = min(and_result, or_result + 1);
        } else {
            ret = min(or_result, and_result + 1);
        }
    } else {
        if (tree[idx].first == 1)
            ret = and_result;
        else
            ret = or_result;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        tree.clear();
        cin >> m >> v;
        tree.resize(m + 1);
        memset(d, -1, sizeof(d));
        for (int i = 1; i <= (m - 1) / 2; i++) {
            int a, b;
            cin >> a >> b;
            tree[i] = {a, b};
        }
        for (int i = (m - 1) / 2 + 1; i <= m; i++) {
            int a;
            cin >> a;
            tree[i] = {a, -1};
        }
        int res = go(1, v);
        cout << "Case #" << cs << ": ";
        if (res >= inf) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << res << '\n';
        }
    }
}