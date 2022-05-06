#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;
ll comb[31][31];

void make_comb() {

    for (int i = 1; i <= 30; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == j || j == 0)
                comb[i][j] = 1;
            else
                comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    make_comb();
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << comb[b][a] << '\n';
    }
}