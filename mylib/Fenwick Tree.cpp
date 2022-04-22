#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010
using namespace std;

int arr[MX];
int tree[MX];
int n;



int sum(int i) {
    int ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= (i & -1);
    }
    return ans;
}

int update(int i, int num) {
    while (i <= n) {
        tree[i] += num;
        i += (i & -i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}