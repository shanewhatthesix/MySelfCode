#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> positions(n);
    
    // 输入果子的位置
    for (int i = 0; i < n; ++i) {
        cin >> positions[i];
    }

    // 对位置进行排序
    sort(positions.begin(), positions.end());

    // 前缀和数组
    vector<long long> prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + positions[i - 1];
    }

    // dp[i][j]表示将前i堆果子合并成j堆的最小体力消耗
    vector<vector<long long> > dp(n + 1, vector<long long>(m + 1, LLONG_MAX));
    
    // 初始化：0堆果子合并成0堆，消耗为0
    dp[0][0] = 0;

    // 动态规划计算
    for (int j = 1; j <= m; ++j) { // 遍历最大堆数
        for (int i = 1; i <= n; ++i) { // 遍历堆数
            for (int k = 0; k < i; ++k) {
                // 计算合并k到i堆的体力消耗
                long long cost = (positions[i - 1] * (i - k) - (prefix_sum[i] - prefix_sum[k]));
                if (dp[k][j - 1] != LLONG_MAX) { // 确保之前的值有效
                    dp[i][j] = min(dp[i][j], dp[k][j - 1] + cost);
                }
            }
        }
    }

    // 找到最小的体力消耗，考虑将所有果子合并为不超过m堆
    long long result = LLONG_MAX;
    for (int j = 1; j <= m; ++j) {
        result = min(result, dp[n][j]);
    }

    cout << result/2 << endl;

    return 0;
}

