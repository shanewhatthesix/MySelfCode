#include <iostream>
using namespace std;

string numberToChinese(int num) {
    // ���������뺺�ֵ�ӳ���ϵ
    const string units[] = {"", "ʰ", "��", "Ǫ"};
    const string digits[] = {"��", "Ҽ", "��", "��", "��", "��", "½", "��", "��", "��"};

    string chineseStr;
    bool zeroFlag = false; // ���ǰһ�������Ƿ�Ϊ��

    // ������תΪ�ַ�����ȷ������λ��
    int thousands = num / 1000;
    int hundreds = (num % 1000) / 100;
    int tens = (num % 100) / 10;
    int units_digit = num % 10;

    // ����ǧλ
    if (thousands != 0) {
        chineseStr += digits[thousands] + units[3];
        zeroFlag = false;
    }

    // �����λ
    if (hundreds != 0) {
        if (zeroFlag) {
            chineseStr += digits[0]; // ������
            zeroFlag = false;
        }
        chineseStr += digits[hundreds] + units[2];
    } else {
        zeroFlag = true;
    }

    // ����ʮλ
    if (tens != 0) {
        if (zeroFlag) {
            chineseStr += digits[0]; // ������
            zeroFlag = false;
        }
        chineseStr += digits[tens] + units[1];
    } else {
        zeroFlag = true;
    }

    // �����λ
    if (units_digit != 0) {
        if (zeroFlag) {
            chineseStr += digits[0]; // ������
        }
        chineseStr += digits[units_digit] + units[0];
    }

    return chineseStr;
}

int main() {
    int N;
    cin >> N;

    if (N < 1000 || N > 9999) {
        cout << "������������ڷ�Χ�ڣ�" << std::endl;
        return 1; // ���ط���ֵ��ʾ����
    }

    string result = numberToChinese(N);
    cout << result << std::endl;

    return 0;
}

