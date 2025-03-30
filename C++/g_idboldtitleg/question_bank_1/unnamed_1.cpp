#include <iostream>
using namespace std;

const int MOD = 1000007;  // 取模常数

int main() {
    int n, m;
    cin >> n >> m;

    // 存储每种花最多可以摆放的盆数
    int a[100], dp[101] = {0};  // dp数组用来存储摆放j盆花的方案数
    dp[0] = 1;  // 摆放0盆花的方案数为1

    // 输入每种花最多摆放的盆数
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 遍历每种花
    for (int i = 0; i < n; i++) {
        // 从后向前遍历dp数组，防止同一花种的多个状态互相干扰
        for (int j = m; j >= 0; j--) {  // 确保先计算已经添加过的方案数
            if (dp[j] > 0) {  // 如果当前有方案数
                // 尝试将当前花从1盆到a[i]盆加入已有方案
                for (int k = 1; k <= a[i] && j + k <= m; k++) {  // 遍历当前花最多可以放的盆数
                    dp[j + k] = (dp[j + k] + dp[j]) % MOD;  // 更新方案数     
                }
            }
        }
    }

    // 输出最终结果，即dp[m]，方案数对1000007取模
    cout << dp[m] << endl;
    return 0;
}
