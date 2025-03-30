#include <bits/stdc++.h>
#define N 1010
using namespace std;

int T, m, n, K, x, y, d;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mm[N][N];
bool vis[N][N];

bool ok(int u, int v) // 判断位置(u,v)是否合法
{
    if (u < 1 || u > m || v < 1 || v > n)
        return 0;
    if (mm[u][v] != '.')
        return 0;
    return 1;
}

int main()
{
    cin >> T;
    while (T--)
    {
        memset(vis, 0, sizeof(vis));
        scanf("%d%d%d", &m, &n, &K);
        scanf("%d%d%d", &x, &y, &d);
        for (int i = 1; i <= m; i++)
            scanf("%s", mm[i] + 1);
        vis[x][y] = 1;
        while (K--)
        {
            int nx, ny;
            nx = x + dir[d][0];
            ny = y + dir[d][1];
            if (!ok(nx, ny))
            {
                d = (d + 1) % 4;
                continue;
            }
            x = nx, y = ny;
            vis[x][y] = 1;
        }
        int ans = 0;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (vis[i][j])
                    ans++;
        printf("%d\n", ans);
    }
}
