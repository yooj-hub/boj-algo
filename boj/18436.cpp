#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 110101
using namespace std;

int odd[MX];
int even[MX];
int arr[MX];
int n;

void add(int idx, int val) {
    if (val & 1) {
        while (idx <= n) {
            odd[idx]++;
            idx += idx & (-idx);
        }
    } else {
        while (idx <= n) {
            even[idx]++;
            idx += idx & (-idx);
        }
    }
}

void update(int idx, int val) {
    if ((arr[idx] & 1) == (val & 1))
        return;
    arr[idx] = val;
    if (val & 1) {
        int tmp = idx;
        while (tmp <= n) {
            even[tmp]--;
            tmp += tmp & (-tmp);
        }
        tmp = idx;
        while (tmp <= n) {
            odd[tmp]++;
            tmp += tmp & (-tmp);
        }
    } else {
        int tmp = idx;
        while (tmp <= n) {
            even[tmp]++;
            tmp += tmp & (-tmp);
        }
        tmp = idx;
        while (tmp <= n) {
            odd[tmp]--;
            tmp += tmp & (-tmp);
        }
    }
}

int sum(int idx, bool isOdd) {
    int ret = 0;
    if (isOdd) {
        while (idx) {
            ret += odd[idx];
            idx -= idx & (-idx);
        }

    } else {
        while (idx) {
            ret += even[idx];
            idx -= idx & (-idx);
        }
    }
    return ret;
}

void query(int kind, int left, int right) {
    if (kind == 1) {
        update(left, right);
    } else if (kind == 2) {
        cout << sum(right, false) - sum(left - 1, false) << '\n';
    } else {
        cout << sum(right, true) - sum(left - 1, true) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        add(i, arr[i]);
    }
    int q;
    cin >> q;
    while (q--) {
        int kind, left, right;
        cin >> kind >> left >> right;
        query(kind, left, right);
    }
}