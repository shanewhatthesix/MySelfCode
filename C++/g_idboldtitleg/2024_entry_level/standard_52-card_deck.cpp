#include <bits/stdc++.h>
using namespace std;

int n, ans, cnt[56 + 5], res;

int turn_1(char u)
{
    if (u == 'D')
        return 0;
    if (u == 'C')
        return 1;
    if (u == 'H')
        return 2;
    if (u == 'S')
        return 3;
}

int turn_2(char u)
{
    if (u == 'A')
        return 1;
    if (u == 'T')
        return 10;
    if (u == 'J')
        return 11;
    if (u == 'Q')
        return 12;
    if (u == 'K')
        return 13;
    return u - '0';
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        res = turn_1(s[0]) * 13 + turn_2(s[1]);
        cnt[res]++;
    }
    for (int i = 1; i <= 52; i++)
        if (!cnt[i])
            ans++;
    cout << ans;
    return 0;
}
