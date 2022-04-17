#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;
vector<int> candies;

int d[20001][301];
int n, m;

bool chk[301];
int go(int current, int cnt, int t) {
    if (t < 0)
        return 0;
    if (d[current][cnt] != -1)
        return d[current][cnt];
    int &ans = d[current][cnt];
    ans = 0;
    int idx =
        lower_bound(candies.begin(), candies.end(), current) - candies.begin();
    if (current == candies[idx] && idx + 1 < n) {
        if (!chk[idx + 1]) {
            chk[idx + 1] = true;
            ans += go(candies[idx + 1], cnt + 1,
                      t + abs(candies[idx + 1] - current));
            chk[idx + 1] = false;
        }
    } else {
        if (!chk[idx]) {
            chk[idx] = true;
            ans += go(candies[idx], cnt + 1, t + abs(candies[idx] - current));
            chk[idx] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x += 10000;
        candies.push_back(x);
    }
    sort(candies.begin(), candies.end());
}