#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 301010

using namespace std;
pair<int, int> a[MX];
int d[MX];
int n, s;

// val을 만족하는 최대 인덱스를 찾는 함수
int solve(int start, int end, int val) {
    int ret = -1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (a[mid].first > val) {
            end = mid - 1;
        } else {
            start = mid + 1;
            ret = mid;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> s;
    a[0] = {0, 0};
    for (int i = 1; i <= n; i++) {
        int q, b;
        cin >> q >> b;
        a[i] = {q, b};
    }
    sort(a, a + (n + 1));
    // dp 
    for (int i = 1; i <= n; i++) {
        pair<int, int> tmp;
        if (a[i].first < s)
            continue;
        int idx = solve(0, i - 1, a[i].first-s);
        d[i] = max(d[idx] + a[i].second, d[i - 1]);
    }
    cout << d[n] << '\n';
}