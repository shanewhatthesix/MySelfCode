#include <iostream>
#include <string>

using namespace std;

int main() {
    int K;
    string S;

    // ����ƫ����K
    cin >> K;
    // �����������ַ���S
    cin >> S;

    string result; // ���ڴ洢�������ַ���

    // �����ַ���S�е�ÿ���ַ�
    for (int i = 0; i < S.length(); i++) {
        char c = S[i]; // ��ȡ��ǰ�ַ�
        // ����ƫ�ƺ���ַ�
        char new_char = (c - 'a' + K) % 26 + 'a';
        result += new_char; // �����ַ���ӵ������
    }

    // ����������ַ���
    cout << result << endl;

    return 0;
}

