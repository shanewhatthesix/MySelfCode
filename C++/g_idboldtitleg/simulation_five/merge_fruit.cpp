#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> positions(n);
    
    // ������ӵ�λ��
    for (int i = 0; i < n; ++i) {
        cin >> positions[i];
    }

    // ��λ�ý�������
    sort(positions.begin(), positions.end());

    // ǰ׺������
    vector<long long> prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + positions[i - 1];
    }

    // dp[i][j]��ʾ��ǰi�ѹ��Ӻϲ���j�ѵ���С��������
    vector<vector<long long> > dp(n + 1, vector<long long>(m + 1, LLONG_MAX));
    
    // ��ʼ����0�ѹ��Ӻϲ���0�ѣ�����Ϊ0
    dp[0][0] = 0;

    // ��̬�滮����
    for (int j = 1; j <= m; ++j) { // ����������
        for (int i = 1; i <= n; ++i) { // ��������
            for (int k = 0; k < i; ++k) {
                // ����ϲ�k��i�ѵ���������
                long long cost = (positions[i - 1] * (i - k) - (prefix_sum[i] - prefix_sum[k]));
                if (dp[k][j - 1] != LLONG_MAX) { // ȷ��֮ǰ��ֵ��Ч
                    dp[i][j] = min(dp[i][j], dp[k][j - 1] + cost);
                }
            }
        }
    }

    // �ҵ���С���������ģ����ǽ����й��Ӻϲ�Ϊ������m��
    long long result = LLONG_MAX;
    for (int j = 1; j <= m; ++j) {
        result = min(result, dp[n][j]);
    }

    cout << result/2 << endl;

    return 0;
}

