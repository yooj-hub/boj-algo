#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;

int arr[1001];

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return (b, a % b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int mx = 0;
    for (int r = 0; r < 1000000; r++) {
        int a = arr[1] - r;
        int b = arr[2] - r;
        if (a < 0) {
            
            
        }
        if (b < 0) {
            
        }

        int start = gcd(a, b);
        for (int i = 3; i <= n; i++) {
            start = gcd(start, arr[i] - r);
        }
        mx = max(mx, start);
    }
    cout << mx << endl;
}