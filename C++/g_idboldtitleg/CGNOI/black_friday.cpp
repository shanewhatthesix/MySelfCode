#include <iostream>
using namespace std;

// �ж��Ƿ�Ϊ����
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// ��ȡÿ�µ�����
int getDaysInMonth(int year, int month) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return days[month - 1];
}

// �����1998��1��1�յ�ָ�����ڵ�������
int getTotalDays(int year, int month, int day) {
    int totalDays = 0;
    
    // �������������
    for (int y = 1998; y < year; y++) {
        totalDays += isLeapYear(y) ? 366 : 365;
    }
    
    // ���ϵ�������ϸ��µ�����
    for (int m = 1; m < month; m++) {
        totalDays += getDaysInMonth(year, m);
    }
    
    // ���ϵ��µ�����
    totalDays += day - 1;
    
    return totalDays;
}

int main() {
    int year;
    cin >> year;
    
    int friday13Count = 0;
    // 1998��1��1����������
    int startDay = 4;  // 1 = ����һ, ..., 7 = ������
    
    // ����ÿ���µ�13��
    for (int month = 1; month <= 12; month++) {
        // �����1998��1��1�յ���ǰ13�ŵ�������
        int totalDays = getTotalDays(year, month, 13);
        
        // ���㵱ǰ13�������ڼ�
        // (startDay + totalDays) % 7 �õ��ķ�Χ��0-6
        // ����Ҫת��Ϊ1-7�ķ�Χ������Ҫ��7������
        int weekday = (startDay + totalDays + 7) % 7;
        if (weekday == 0) weekday = 7;
        
        // ����������壨5��
        if (weekday == 5) {
            friday13Count++;
        }
    }
    
    cout << friday13Count << endl;
    return 0;
}
