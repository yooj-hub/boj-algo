#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define ll long long int
#define MX 101010

using namespace std;
int n, k;

int arr[1000 * 3];
ll d[3000][1000][(1 << 3)];

const ll inf = 2e10 + 7;
ll go(int idx, int domino, int state)
{
    if (idx == n * 3 && domino == 0 && state == 0)
        return 0LL;
    if (idx >= n * 3)
        return -inf;
    ll &ans = d[idx][domino][state];
    if (ans != -inf)
        return d[idx][domino][state];
    ans = 0;
    // 그냥 진행
    ans = max(ans, go(idx + 1, domino, state >> 1));
    if (state & 1)
    {
        return ans;
    }

    // 가로
    if ((state & 2)==0 && idx % 3 != 2 && domino > 0 && idx+1 < n*3)
    {
        ans = max(ans, go(idx + 2, domino - 1, state >> 2) + arr[idx] + arr[idx + 1]);
    }

    // 세로
    if(domino > 0 && idx+3 < n *3)
        ans = max(ans, go(idx + 1, domino - 1, (state >> 1) | (1 << 2)) + arr[idx] + arr[idx + 3]);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;

    for (int i = 0; i < n * 3; i++)
    {
        cin >> arr[i];
    }
    for(int i=0; i<3000; i++){
        for(int j=0; j<1000; j++){
            fill(d[i][j], d[i][j] + 8, -inf);
        }

    }
    cout << go(0, k, 0);
}