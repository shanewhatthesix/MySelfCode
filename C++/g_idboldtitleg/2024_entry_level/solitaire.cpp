#include <bits/stdc++.h>
#define N 200100
#define M 110
using namespace std;

int T, n, K, Q, ok[M][N];
vector<int> num[N];

int main()
{
    cin >> T;
    while (T--)
    {
        memset(ok, -1, sizeof(ok));
        scanf("%d%d%d", &n, &K, &Q);
        for (int i = 1; i <= n; i++)
        {
            num[i].clear();
            int len;
            scanf("%d", &len);
            for (int j = 1; j <= len; j++)
            {
                int t;
                scanf("%d", &t);
                num[i].push_back(t);
            }
        }

        ok[0][1] = 0;
        for (int T = 1; T <= 100; T++)
        {
            for (int i = 1; i <= n; i++)
            {
                int len = 0;
                for (auto t : num[i])
                {
                    len = max(len - 1, 0);
                    if (len)
                    {
                        if (ok[T][t] == -1)
                            ok[T][t] = i;
                        else if (ok[T][t] && ok[T][t] != i)
                            ok[T][t] = 0;
                    }
                    if (ok[T - 1][t] != -1 && ok[T - 1][t] != i)
                        len = K;
                }
            }
        }
        while (Q--)
        {
            int p, q;
            scanf("%d%d", &p, &q);
            puts(ok[p][q] != -1 ? "1" : "0");
        }
    }
}
