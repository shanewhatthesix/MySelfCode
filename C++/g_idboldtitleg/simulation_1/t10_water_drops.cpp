#include<bits/stdc++.h>
using namespace std;

void calculateDrops(long long n) {
    // �������洢ÿ��Ʒ�׵�ˮ������
    vector<long long> drops(11, 0); // drops[i] ��ʾ i Ʒˮ�ε�����
    drops[1] = n; // ��ʼһƷˮ������

    // ��1Ʒˮ�ο�ʼ�ϳ�
    for (int i = 1; i < 10; i++) { // ��1Ʒ��9Ʒ
        long long toCombine = drops[i] / 9; // �ɺϳɵĸ�Ʒˮ������
        drops[i + 1] += toCombine; // ������һ��Ʒ�׵�ˮ������
        drops[i] %= 9; // ʣ���ˮ������
    }

    // ����������10Ʒ��1Ʒ
    for (int i = 10; i >= 1; i--) {
        if (drops[i] > 0) {
            cout << i << ":" << drops[i] << endl/*" "*/;
        }
    }
    // cout << endl;
}

int main() {
    long long n;
    cin >> n; // ����һƷˮ������
    calculateDrops(n); // ����ϳɽ��
    return 0;
}

