#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// 清洗单词，去除特殊字符并转换为小写
string cleanWord(const string& word) {
    string cleaned;
    for (size_t i = 0; i < word.size(); ++i) {
        if (isalpha(word[i])) {
            cleaned += tolower(word[i]); // 只保留字母，转换为小写
        }
    }
    return cleaned;
}

int main() {
    string input;
    getline(cin, input); // 读取整行输入

    // 使用 map 来统计单词的出现次数
    map<string, int> wordCount;
    stringstream ss(input);
    string word;

    // 统计单词出现次数
    while (ss >> word) {
        string cleanedWord = cleanWord(word);
        if (!cleanedWord.empty()) {
            wordCount[cleanedWord]++;
        }
    }

    // 找到出现最多的单词
    string mostFrequentWord;
    int maxCount = 0;

    // 使用传统迭代器遍历 map
    for (map<string, int>::iterator it = wordCount.begin(); it != wordCount.end(); ++it) {
        if (it->second > maxCount) {
            maxCount = it->second;
            mostFrequentWord = it->first;
        }
    }

    // 输出结果
    cout << mostFrequentWord << endl;
    cout << maxCount << endl;

    return 0;
}

