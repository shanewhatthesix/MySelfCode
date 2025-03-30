#include <iostream>
using namespace std;

string numberToChinese(int num) {
    // 定义数字与汉字的映射关系
    const string units[] = {"", "拾", "佰", "仟"};
    const string digits[] = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};

    string chineseStr;
    bool zeroFlag = false; // 标记前一个数字是否为零

    // 将数字转为字符串，确保是四位数
    int thousands = num / 1000;
    int hundreds = (num % 1000) / 100;
    int tens = (num % 100) / 10;
    int units_digit = num % 10;

    // 处理千位
    if (thousands != 0) {
        chineseStr += digits[thousands] + units[3];
        zeroFlag = false;
    }

    // 处理百位
    if (hundreds != 0) {
        if (zeroFlag) {
            chineseStr += digits[0]; // 加入零
            zeroFlag = false;
        }
        chineseStr += digits[hundreds] + units[2];
    } else {
        zeroFlag = true;
    }

    // 处理十位
    if (tens != 0) {
        if (zeroFlag) {
            chineseStr += digits[0]; // 加入零
            zeroFlag = false;
        }
        chineseStr += digits[tens] + units[1];
    } else {
        zeroFlag = true;
    }

    // 处理个位
    if (units_digit != 0) {
        if (zeroFlag) {
            chineseStr += digits[0]; // 加入零
        }
        chineseStr += digits[units_digit] + units[0];
    }

    return chineseStr;
}

int main() {
    int N;
    cin >> N;

    if (N < 1000 || N > 9999) {
        cout << "输入的整数不在范围内！" << std::endl;
        return 1; // 返回非零值表示错误
    }

    string result = numberToChinese(N);
    cout << result << std::endl;

    return 0;
}

