#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;  // �������ֻ�������
    vector<int> flowers(n);

    // ����ÿ�仨�ϵ�����
    for (int i = 0; i < n; i++) {
        cin >> flowers[i];
    }

    // �������ֻ�������
    int total_count = n;

    // ���������ܺ�
    int total_sum = 0;
    for (int i = 0; i < n; i++) {
        total_sum += flowers[i];
    }

    // �����������仨�ϵ�����֮�͵����ֵ
    int max_sum = INT_MIN;  // ��ʼ��Ϊ��Сֵ
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            max_sum = max(max_sum, flowers[i] + flowers[j]);
        }
    }

    // ������
    cout << total_count << endl;  // �����������
    cout << total_sum << endl;     // ��������ܺ�
    cout << max_sum << endl;       // ����������仨�ϵ�����֮�͵����ֵ

    return 0;
}

