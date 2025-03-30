#include <iostream>
using namespace std;

// 判断是否为闰年
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 获取每月的天数
int getDaysInMonth(int year, int month) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return days[month - 1];
}

// 计算从1998年1月1日到指定日期的总天数
int getTotalDays(int year, int month, int day) {
    int totalDays = 0;
    
    // 计算整年的天数
    for (int y = 1998; y < year; y++) {
        totalDays += isLeapYear(y) ? 366 : 365;
    }
    
    // 加上当年截至上个月的天数
    for (int m = 1; m < month; m++) {
        totalDays += getDaysInMonth(year, m);
    }
    
    // 加上当月的天数
    totalDays += day - 1;
    
    return totalDays;
}

int main() {
    int year;
    cin >> year;
    
    int friday13Count = 0;
    // 1998年1月1日是星期四
    int startDay = 4;  // 1 = 星期一, ..., 7 = 星期日
    
    // 遍历每个月的13号
    for (int month = 1; month <= 12; month++) {
        // 计算从1998年1月1日到当前13号的总天数
        int totalDays = getTotalDays(year, month, 13);
        
        // 计算当前13号是星期几
        // (startDay + totalDays) % 7 得到的范围是0-6
        // 我们要转换为1-7的范围，所以要加7再求余
        int weekday = (startDay + totalDays + 7) % 7;
        if (weekday == 0) weekday = 7;
        
        // 如果是星期五（5）
        if (weekday == 5) {
            friday13Count++;
        }
    }
    
    cout << friday13Count << endl;
    return 0;
}
