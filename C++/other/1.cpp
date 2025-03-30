#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, F;
    cin >> n >> F;
    
    vector<int> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    // dp[i][j] 表示第i天，当前疲劳度为j时的最大收益
    vector<vector<long long>> dp(n + 1, vector<long long>(F + 1, -1e9));
    
    // 初始状态：第0天，疲劳度为0
    dp[0][0] = 0;
    
    // 遍历每一天
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= F; j++) {
            if(dp[i][j] == -1e9) continue;
            
            // 选择1：休息
            // 休息会让疲劳度-1，但不能小于0
            int next_fatigue = max(0, j - 1);
            dp[i + 1][next_fatigue] = max(dp[i + 1][next_fatigue], dp[i][j]);
            
            // 选择2：工作
            // 只有当疲劳度允许时才能工作
            if(j < F) {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + p[i]);
            }
        }
    }
    
    // 输出最后一天疲劳度为0时的最大收益
    cout << dp[n][0] << endl;
    
    return 0;
}