#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;
int d[31];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    d[0] = 1;
    d[1] = 0;
    d[2] = 3;
    for (int i = 3; i <= n; i++) {
        d[i] =d[i - 2] * 3;
        for(int j= i-4; j>=0; j-=2){
            d[i] += d[j] *2;
        }

    }
    cout << d[n] << '\n';
}