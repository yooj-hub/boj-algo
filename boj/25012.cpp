#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#define all(x) x.begin(), x.end()

using namespace std;
vector<int> nodes[500001];
set<int> pv;

long long findMinClicks(int M, int R, std::vector<std::pair<int, int>> P) {
    long long ret = -1;
    for (auto &x : P) {
        nodes[x.first].push_back(x.second);
        pv.insert(x.second);
    }
    for (int i = 0; i < M; i++) {
        sort(nodes[i].begin(), nodes[i].end());
    }
    for (auto iter = pv.begin(); iter != pv.end(); iter++) {
        long long tmp = 0;
        for (int i = 0; i < M; i++) {

            int lower_idx =
                lower_bound(nodes[i].begin(), nodes[i].end(), *iter) -
                nodes[i].begin();
            int prev_idx = max(lower_idx - 1, 0);
            int nxt_idx;
            if(lower_idx +1 == (int)nodes[i].size()){
                nxt_idx = 0;
            }else{
                nxt_idx = lower_idx+1;
            }
            tmp += min({abs(*iter - nodes[i][lower_idx]),
                        abs(*iter - nodes[i][prev_idx]),
                        abs(*iter - nodes[i][nxt_idx]),
                        *iter + R - 1 - nodes[i][lower_idx],
                        *iter + R - 1 - nodes[i][prev_idx],
                        *iter + R - 1 - nodes[i][nxt_idx]});
        }
        if (ret == -1 || ret > tmp)
            ret = tmp;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << findMinClicks(
                4, 20, {{1, 3}, {0, 2}, {2, 6}, {3, 8}, {3, 1}, {2, 0}, {1, 8}})
         << '\n';
}