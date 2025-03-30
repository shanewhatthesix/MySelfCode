#include <bits/stdc++.h>

using namespace std;
int main() {
    string data;
    int f;

    cin >> data >> f; // �����ַ�����Ҫ��ɵ�λ��

    vector<char> digits; // ���ڴ洢�����ַ�

    // ��ȡ�����ַ�
    for (int i = 0; i < data.length(); ++i) {
        if (isdigit(data[i])) {
            digits.push_back(data[i]);
        }
    }

    // �����ȡ�������ַ��Ƿ��㹻
    if (digits.size() < f) {
        cout << "Error: Not enough digits to form " << f << "-digit numbers." << endl;
        return 1;
    }

    // Ϊ��С�� f λ������
    sort(digits.begin(), digits.end());
    // ������С�� f λ��
    string minNum(digits.begin(), digits.begin() + f);

    // Ϊ���� f λ������
    sort(digits.rbegin(), digits.rend());
    // �������� f λ��
    string maxNum(digits.begin(), digits.begin() + f);

    // ������
    cout << minNum << endl;
    cout << maxNum << endl;

    return 0;
}

