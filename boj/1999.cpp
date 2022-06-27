#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define ll long long int
#define MX 101010

using namespace std;

int n, b, k;

int arr[251][251];
int min_tree[251 * 4][251 * 4];
int max_tree[251 * 4][251 * 4];
int cnt = 0;
int max_init(int nx, int ny, int sx, int sy, int ex, int ey)
{

    if (sx == ex && sy == ey)
    {
        return max_tree[nx][ny] = arr[sx][sy];
    }
    int mx = (sx + ex) >> 1;
    int my = (sy + ey) >> 1;
    int &ret = max_tree[nx][ny];
    if (sx != ex)
    {
        ret = max(
            max_init(nx * 2, ny, sx, sy, mx, ey),
            max_init(nx * 2 + 1, ny, mx + 1, sy, ex, ey));
    }
    if (sy != ey)
    {
        ret = max(max_init(nx, ny * 2, sx, sy, ex, my),
                  max_init(nx, ny * 2 + 1, sx, my + 1, ex, ey));
    }
    return ret;
}

int min_init(int nx, int ny, int sx, int sy, int ex, int ey)
{
    if (sx == ex && sy == ey)
    {
        return min_tree[nx][ny] = arr[sx][sy];
    }
    int mx = (sx + ex) >> 1;
    int my = (sy + ey) >> 1;
    int &ret = min_tree[nx][ny];
    if (sx != ex)
    {
        ret = min(
            min_init(nx * 2, ny, sx, sy, mx, ey),
            min_init(nx * 2 + 1, ny, mx + 1, sy, ex, ey));
    }
    if (sy != ey)
    {
        ret = min(min_init(nx, ny * 2, sx, sy, ex, my),
                  min_init(nx, ny * 2 + 1, sx, my + 1, ex, ey));
    }
    return ret;
}

int max_query(int nx, int ny, int sx, int sy, int ex, int ey, int lx, int ly, int rx, int ry)
{

    if (sx > rx || ex < lx)
        return -1;
    if (sy > ry || ey < ly)
        return -1;
    if (lx <= sx && ex <= rx && ly <= sy && ey <= ry)
        return max_tree[nx][ny];
    int mx = (sx + ex) >> 1;
    int my = (sy + ey) >> 1;
    int ret = -1;
    if (sx != ex)
    {
        ret = max(
            max_query(nx, ny * 2, sx, sy, ex, my, lx, ly, rx, ry),
            max_query(nx, ny * 2 + 1, sx, my + 1, ex, ey, lx, ly, rx, ry));
    }
    if (sy != ey)
    {
        ret = max(
            max_query(nx * 2, ny, sx, sy, mx, ey, lx, ly, rx, ry),
            max_query(nx * 2 + 1, ny, mx + 1, sy, ex, ey, lx, ly, rx, ry));
    }

    return ret;
}

int min_query(int nx, int ny, int sx, int sy, int ex, int ey, int lx, int ly, int rx, int ry)
{
    if (sx > rx || ex < lx)
        return 256;
    if (sy > ry || ey < ly)
        return 256;
    if (lx <= sx && ex <= rx && ly <= sy && ey <= ry)
        return min_tree[nx][ny];
    int mx = (sx + ex) >> 1;
    int my = (sy + ey) >> 1;
    int ret = 256;
    if (sx != ex)
    {
        ret = min(
            min_query(nx, ny * 2, sx, sy, ex, my, lx, ly, rx, ry),
            min_query(nx, ny * 2 + 1, sx, my + 1, ex, ey, lx, ly, rx, ry));
    }
    if (sy != ey)
    {
        ret = min(
            min_query(nx * 2, ny, sx, sy, mx, ey, lx, ly, rx, ry),
            min_query(nx * 2 + 1, ny, mx + 1, sy, ex, ey, lx, ly, rx, ry));
    }

    return ret;
}

int query(int row, int col)
{
    int mx = max_query(1, 1, 1, 1, n, n, row, col, row + b - 1, col + b - 1);
    int mn = min_query(1, 1, 1, 1, n, n, row, col, row + b - 1, col + b - 1);
    return mx - mn;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> b >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }
    max_init(1, 1, 1, 1, n, n);
    min_init(1, 1, 1, 1, n, n);
    cout <<cnt<<endl;
    for (int i = 1; i <= k; i++)
    {
        int row, col;
        cin >> row >> col;
        cout << query(row, col) << '\n';
    }
    cout << 23 << endl;
}