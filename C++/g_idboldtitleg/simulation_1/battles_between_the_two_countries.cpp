#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n; // 输入城市数量

    int p1, p2;
    cin >> p1 >> p2; // 输入两种火箭弹的价格

    int s1, s2;
    cin >> s1 >> s2; // 输入两种火箭弹的威力

    vector<int> energy(n);
    for (int i = 0; i < n; i++) {
        cin >> energy[i]; // 输入每个城市的防御天幕能量值
    }

    long long totalCost = 0;

    // 遍历每个城市，计算总费用
    for (int i = 0; i < n; i++) {
        // 计算使用火箭弹 A 的费用
        long long costA = (long long)ceil((double)energy[i] / s1) * p1;
        // 计算使用火箭弹 B 的费用
        long long costB = (long long)ceil((double)energy[i] / s2) * p2;

        // 选择较小的费用
        totalCost += min(costA, costB);
    }

    // 输出总费用
    cout << totalCost << endl;

    return 0;
}

