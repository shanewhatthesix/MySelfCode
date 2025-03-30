#include <iostream>
#include <string>

using namespace std;

int main() {
    int K;
    string S;

    // 输入偏移量K
    cin >> K;
    // 输入待翻译的字符串S
    cin >> S;

    string result; // 用于存储翻译后的字符串

    // 遍历字符串S中的每个字符
    for (int i = 0; i < S.length(); i++) {
        char c = S[i]; // 获取当前字符
        // 计算偏移后的字符
        char new_char = (c - 'a' + K) % 26 + 'a';
        result += new_char; // 将新字符添加到结果中
    }

    // 输出翻译后的字符串
    cout << result << endl;

    return 0;
}

