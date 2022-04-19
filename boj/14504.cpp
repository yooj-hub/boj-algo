#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010
#define sn 400

using namespace std;
const int sz = MX / sn + 1;
vector<int> bucket[sz];
int arr[MX];
int n;
void init() {
    for (int i = 1; i <= n; i++) {
        bucket[i / sn].push_back(arr[i]);
    }
    for (int i = 0; i <= n / sn; i++) {
        sort(all(bucket[i]));
    }
}

void update(int idx, int val) {
    
    auto it = lower_bound(all(bucket[idx/sn]), arr[idx]);
    *it = val;
    arr[idx] = val;
    sort(all(bucket[idx / sn]));
}

int query(int start, int end, int k) {
    int ret = 0;
    if (start / sn == end / sn) {
        for (int i = start; i <= end; i++) {
            if (arr[i] > k)
                ret++;
        }
    } else {
        while (true) {
            if (arr[start] > k)
                ret++;
            start++;
            if (start % sn == 0)
                break;
        }
        while (true) {
            if (arr[end] > k)
                ret++;
            end--;
            if (end % sn == sn - 1)
                break;
        }
        for (int i = start / sn; i <= end / sn; i++) {
            ret += bucket[i].end() - upper_bound(all(bucket[i]), k);
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    init();

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int from, to, k;
            cin >> from >> to >> k;
            cout << query(from, to, k) << '\n';
        } else {
            int target, val;
            cin >> target >> val;
            update(target, val);
        }
    }
    // for(int i=1; i<=5;i++){
    //     cout << arr[i] << " ";
    // }

    return 0;
}