#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 202020

using namespace std;
int n, k, p;
int arr[MX];
bitset<MX> chk;

bool is_heap() {
    for (int i = 1; i <= n; i++) {
        int left = i * 2;
        int right = i * 2 + 1;
        if (left <= n) {
            if (arr[left] < arr[i])
                return false;
        }

        if (right <= n)
            if (arr[i] > arr[right])
                return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k >> p;
    int q = 1;
    int sz = p;
    while (sz > 1) {
        q++;
        sz /= 2;
    }
    if (q > k) {
        cout << -1;
    } else {
        int current = q - 1;
        while (p) {
            if (chk[k] == 0) {
                arr[p] = k;
                chk[k] = 1;
            } else {
                arr[p] = current;
                chk[current--] = 1;
            }
            p /= 2;
        }
        current = 1;
        for (int i = 1; i <= n; i++) {
            while (chk[current]==1) {
                current++;
            }
            if (arr[i] == 0) {
                cout << current << '\n';
                chk[current] = 1;
            } else {
                cout << arr[i] << '\n';
            }
        }
    }
}