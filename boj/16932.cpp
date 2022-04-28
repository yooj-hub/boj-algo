#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;

int n, m;
int board[1000][1000];
int group[1000000];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void dfs(int x, int y, int gn)
{
    group[gn]++;
    board[x][y] = gn;
    int val = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n)
            continue;
        if (ny < 0 || ny >= m)
            continue;
        if (board[nx][ny] == 1)
            dfs(nx, ny, gn);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    int gn = 2;
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 1)
            {
                dfs(i, j, gn);
                gn++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 0)
            {
                int val = 1;
                set<int> s;
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;
                    if (board[nx][ny] == 0)
                        continue;
                    s.insert(board[nx][ny]);
                }
                for (auto iter = s.begin(); iter != s.end(); iter++)
                {
                    val += group[*iter];
                }
                answer = max(val, answer);
            }
        }
    }
    cout << answer << '\n';
}