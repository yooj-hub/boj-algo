#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define ll long long int
#define MX 101010

using namespace std;

int n, m, k;

int d[100][1 << 10][51];
bool c[100][1 << 10][51];
int arr[100];
const int inf = 1e9 + 7;
// state 못두는 곳을 표기
int go(int idx, int state, int x)
{
    if (idx >= n * m && x == 0)
    {
        return 0;
    }
    if (idx >= n * m)
        return -inf;
    int &ans = d[idx][state][x];
    if (c[idx][state][x])
        return ans;
    c[idx][state][x] = true;
    ans = go(idx + 1, state >> 1, x);
    if (state & 1 || x <= 0)
        return ans;

    // 끝이 아닌 경우
    if (idx % m != m - 1)
    {
        ans = max(ans, arr[idx] + go(idx + 2, (state >> 2) | (1 << (m - 2)), x - 1));
    }
    // 끝인 경우
    if (idx % m == m - 1)
    {
            ans = max(ans, arr[idx] + go(idx + 1, (state >> 1) | (1 << (m - 1)), x - 1));
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 1024; j++)
        {
            fill(d[i][j], d[i][j] + 51, -inf);
        }
    }
    cin >> n >> m >> k;
    for (int i = 0; i < n * m; i++)
        cin >> arr[i];

    cout << go(0, 0, k);
}