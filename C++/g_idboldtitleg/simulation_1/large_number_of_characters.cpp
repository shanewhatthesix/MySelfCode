#include <bits/stdc++.h>

using namespace std;
int main() {
    string data;
    int f;

    cin >> data >> f; // 输入字符串和要组成的位数

    vector<char> digits; // 用于存储数字字符

    // 提取数字字符
    for (int i = 0; i < data.length(); ++i) {
        if (isdigit(data[i])) {
            digits.push_back(data[i]);
        }
    }

    // 检查提取的数字字符是否足够
    if (digits.size() < f) {
        cout << "Error: Not enough digits to form " << f << "-digit numbers." << endl;
        return 1;
    }

    // 为最小的 f 位数排序
    sort(digits.begin(), digits.end());
    // 生成最小的 f 位数
    string minNum(digits.begin(), digits.begin() + f);

    // 为最大的 f 位数排序
    sort(digits.rbegin(), digits.rend());
    // 生成最大的 f 位数
    string maxNum(digits.begin(), digits.begin() + f);

    // 输出结果
    cout << minNum << endl;
    cout << maxNum << endl;

    return 0;
}

