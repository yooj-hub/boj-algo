#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;

const int sz = 11;
const int sqrtN = 3;
int a[sz] = {3, 6, 2, 5, 3, 1, 8, 9, 7, 3, 5};
int bucket[sz / sqrtN + 1];

void init() {
    for (int i = 0; i < sz; i++) {
        if (i % sqrtN == 0) {
            bucket[i / sqrtN] = a[i];
        } else {
            bucket[i / sqrtN] = min(bucket[i / sqrtN], a[i]);
        }
    }
}

int query(int u, int v) {
    if (u > v)
        swap(u, v);
    if (u / sqrtN == v / sqrtN) {
        int ans = a[u];
        for (int i = u; i < v; i++) {
            ans = min(ans, a[i]);
        }
        return ans;
    } else {
        while (true) {
            int ans = a[u];
            while (true) {
                ans = min(ans, a[u]);
                u++;
                if (u % sqrtN == 0)
                    break;
            }
            while (true) {
                ans = min(ans, a[v]);
                v--;
                if (v % sqrtN == sqrtN - 1) {
                    break;
                }
            }
            for (int i = u / sqrtN; i <= v / sqrtN; i++) {
                ans = min(ans, bucket[i]);
            }
            return ans;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    cout << query(0, 10) << endl;
    cout << query(6, 9) << endl;
}