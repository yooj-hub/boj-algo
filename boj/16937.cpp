#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 100
#define X first
#define Y second
using namespace std;

int h, w, n;
int chk[MX][MX];
vector<pair<int, int>> stk;

int get_answer() {
    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (stk[i].X + stk[j].X <= h && max(stk[i].Y, stk[j].Y) <= w) {
                answer = max(answer, stk[i].X * stk[i].Y + stk[j].X * stk[j].Y);
            }
            if (stk[i].X + stk[j].Y <= h && max(stk[i].Y, stk[j].X) <= w) {
                answer = max(answer, stk[i].X * stk[i].Y + stk[j].X * stk[j].Y);
            }
            if (stk[i].Y + stk[j].X <= h && max(stk[i].X, stk[j].Y) <= w) {
                answer = max(answer, stk[i].X * stk[i].Y + stk[j].X * stk[j].Y);
            }
            if (stk[i].Y + stk[j].Y <= h && max(stk[i].X, stk[j].X) <= w) {
                answer = max(answer, stk[i].X * stk[i].Y + stk[j].X * stk[j].Y);
            }

            if (stk[i].X + stk[j].X <= w && max(stk[i].Y, stk[j].Y) <= h) {
                answer = max(answer, stk[i].X * stk[i].Y + stk[j].X * stk[j].Y);
            }
            if (stk[i].X + stk[j].Y <= w && max(stk[i].Y, stk[j].X) <= h) {
                answer = max(answer, stk[i].X * stk[i].Y + stk[j].X * stk[j].Y);
            }
            if (stk[i].Y + stk[j].X <= w && max(stk[i].X, stk[j].Y) <= h) {
                answer = max(answer, stk[i].X * stk[i].Y + stk[j].X * stk[j].Y);
            }
            if (stk[i].Y + stk[j].Y <= w && max(stk[i].X, stk[j].X) <= h) {
                answer = max(answer, stk[i].X * stk[i].Y + stk[j].X * stk[j].Y);
            }
        }
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> h >> w >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        stk.push_back({x, y});
    }
    cout << get_answer() << '\n';
}