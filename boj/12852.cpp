#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 1010101
using namespace std;
int d[MX];
int p[MX];

int go(int n) {
    if (d[n] != -1)
        return d[n];
    int &ret = d[n];
    ret = 1 + go(n - 1);
    p[n] = n - 1;
    if (n % 2 == 0) {
        int tmp = 1 + go(n / 2);
        if (tmp < ret) {
            ret = tmp;
            p[n] = n / 2;
        }
    }
    if (n % 3 == 0) {
        int tmp = 1 + go(n / 3);
        if (tmp < ret) {
            ret = tmp;
            p[n] = n / 3;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(d, -1, sizeof(d));
    memset(p,-1,sizeof(p));
    d[1] = 0;
    int n;
    cin >> n;
    cout << go(n)<<'\n';
    for(int i= n; i!= -1; i=p[i]){
        cout << i <<' ';
    }
}