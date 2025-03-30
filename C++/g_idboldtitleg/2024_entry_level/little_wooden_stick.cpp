#include <bits/stdc++.h>
using namespace std;

int T, n, len;
int cnt[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

bool judge(int u, int v) // 判断用v个火柴棒拼成u个数位是否合法
{
    if (v > u * 7)
        return 0;
    if (v < u * 2)
        return 0;
    return 1;
}

void work(int now, int sum) // 目前在填第now位，火柴棒还有sum个
{
    if (!now)
        return;
    int st = 0;
    if (now == len) // 注意不能有前导零
        st = 1;
    for (int i = st; i <= 9; i++) // 尝试将i填到第now位
    {
        if (judge(now - 1, sum - cnt[i]))
        {
            printf("%d", i);
            work(now - 1, sum - cnt[i]);
            break;
        }
    }
}

int main()
{
    cin >> T;
    while (T--)
    {
        scanf("%d", &n);
        if (n == 1)
        {
            puts("-1");
            continue;
        }
        len = (n + 6) / 7; // 计算最终的数位个数
        work(len, n);
        puts("");
    }
    return 0;
}
