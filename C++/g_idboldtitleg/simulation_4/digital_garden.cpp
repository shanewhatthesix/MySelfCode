#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;  // 输入数字花的数量
    vector<int> flowers(n);

    // 输入每朵花上的数字
    for (int i = 0; i < n; i++) {
        cin >> flowers[i];
    }

    // 计算数字花的总数
    int total_count = n;

    // 计算数字总和
    int total_sum = 0;
    for (int i = 0; i < n; i++) {
        total_sum += flowers[i];
    }

    // 计算任意两朵花上的数字之和的最大值
    int max_sum = INT_MIN;  // 初始化为最小值
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            max_sum = max(max_sum, flowers[i] + flowers[j]);
        }
    }

    // 输出结果
    cout << total_count << endl;  // 输出花的总数
    cout << total_sum << endl;     // 输出数字总和
    cout << max_sum << endl;       // 输出任意两朵花上的数字之和的最大值

    return 0;
}

