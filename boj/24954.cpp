#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

vector<int> ori_price;
vector<pair<int, int>> sale[10];
int tot_sale[10];
const int inf = 1e9 + 7;
int ans = inf;
int n;
vector<int> seq;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    ori_price.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> ori_price[i];
    }
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        while (t--) {
            int idx, val;
            cin >> idx >> val;
            idx--;
            sale[i].push_back({idx, val});
        }
    }
    seq.resize(n);
    for (int i = 0; i < n; i++) {
        seq[i] = i;
    }

    do {
        int tmp = 0;
        memset(tot_sale, 0, sizeof(tot_sale));
        for (int i = 0; i < seq.size(); i++) {
            tmp += max(ori_price[seq[i]] - tot_sale[seq[i]], 1);
            for (auto &x : sale[seq[i]]) {
                tot_sale[x.first] += x.second;
            }
        }
        ans = min(tmp, ans);
    } while (next_permutation(all(seq)));
    cout << ans << '\n';
}