#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n; // �����������

    int p1, p2;
    cin >> p1 >> p2; // �������ֻ�����ļ۸�

    int s1, s2;
    cin >> s1 >> s2; // �������ֻ����������

    vector<int> energy(n);
    for (int i = 0; i < n; i++) {
        cin >> energy[i]; // ����ÿ�����еķ�����Ļ����ֵ
    }

    long long totalCost = 0;

    // ����ÿ�����У������ܷ���
    for (int i = 0; i < n; i++) {
        // ����ʹ�û���� A �ķ���
        long long costA = (long long)ceil((double)energy[i] / s1) * p1;
        // ����ʹ�û���� B �ķ���
        long long costB = (long long)ceil((double)energy[i] / s2) * p2;

        // ѡ���С�ķ���
        totalCost += min(costA, costB);
    }

    // ����ܷ���
    cout << totalCost << endl;

    return 0;
}

