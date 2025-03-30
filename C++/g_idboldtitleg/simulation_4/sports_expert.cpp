#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// �Զ���ȽϺ���
bool compare(int a, int b) {
    return abs(a) < abs(b);
}

int countAccessibleMarkers(long long T, int n, vector<int>& positions) {
    // ʹ���Զ���ȽϺ�����������
    sort(positions.begin(), positions.end(), compare);

    // cout << "������·��λ��: ";
    for (int i = 0; i < n; i++) {
        // cout << positions[i] << " ";
    }
    cout << endl;

    int accessibleCount = 0;
    int currentPosition = 0; // xx��ʦ��ǰ��λ�ã���ʼΪ0

    // ����ÿ��·��
    for (int i = 0; i < n; i++) {
        int pos = positions[i];
        long long distance = abs(pos - currentPosition); // �ӵ�ǰ·�굽��һ��·��ľ���
        // cout << "��ǰ·��: " << pos << ", ����: " << distance << ", ʣ��ʱ��: " << T << endl;

        if (T >= distance) { // ��������㹻��ʱ�䵽�����·��
            T -= distance; // ��ȥ�����ʱ��
            currentPosition = pos; // ���µ�ǰ·��λ��
            accessibleCount++; // ���ʵ�·��������1
            // cout << "����·�� " << pos << "���µ�ʣ��ʱ��: " << T << ", ��ǰ�ɷ���·������: " << accessibleCount << endl;
        } else {
            // cout << "�޷�����·�� " << pos << "��ʱ�䲻�㣬ֹͣ���ʡ�" << endl;
            break; // û���㹻��ʱ���ˣ�ֹͣ����
        }
    }

    return accessibleCount;
}

int main() {
    long long T;
    int n;

    // ����ʱ�� T ��·������ n
    cin >> T >> n;

    vector<int> positions(n);

    // ����ÿ��·���λ��
    for (int i = 0; i < n; i++) {
        cin >> positions[i];
    }

    // ����ɷ��ʵ�·�����������
    int result = countAccessibleMarkers(T, n, positions);
    cout/* << "���տɷ��ʵ�·������: " */<< result/* << endl*/;

    return 0;
}

