#include <bits/stdc++.h>
using namespace std;

int T, n, len;
int cnt[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

bool judge(int u, int v) // �ж���v������ƴ��u����λ�Ƿ�Ϸ�
{
    if (v > u * 7)
        return 0;
    if (v < u * 2)
        return 0;
    return 1;
}

void work(int now, int sum) // Ŀǰ�����nowλ����������sum��
{
    if (!now)
        return;
    int st = 0;
    if (now == len) // ע�ⲻ����ǰ����
        st = 1;
    for (int i = st; i <= 9; i++) // ���Խ�i���nowλ
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
        len = (n + 6) / 7; // �������յ���λ����
        work(len, n);
        puts("");
    }
    return 0;
}
