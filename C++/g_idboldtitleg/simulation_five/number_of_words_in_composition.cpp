#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// ��ϴ���ʣ�ȥ�������ַ���ת��ΪСд
string cleanWord(const string& word) {
    string cleaned;
    for (size_t i = 0; i < word.size(); ++i) {
        if (isalpha(word[i])) {
            cleaned += tolower(word[i]); // ֻ������ĸ��ת��ΪСд
        }
    }
    return cleaned;
}

int main() {
    string input;
    getline(cin, input); // ��ȡ��������

    // ʹ�� map ��ͳ�Ƶ��ʵĳ��ִ���
    map<string, int> wordCount;
    stringstream ss(input);
    string word;

    // ͳ�Ƶ��ʳ��ִ���
    while (ss >> word) {
        string cleanedWord = cleanWord(word);
        if (!cleanedWord.empty()) {
            wordCount[cleanedWord]++;
        }
    }

    // �ҵ��������ĵ���
    string mostFrequentWord;
    int maxCount = 0;

    // ʹ�ô�ͳ���������� map
    for (map<string, int>::iterator it = wordCount.begin(); it != wordCount.end(); ++it) {
        if (it->second > maxCount) {
            maxCount = it->second;
            mostFrequentWord = it->first;
        }
    }

    // ������
    cout << mostFrequentWord << endl;
    cout << maxCount << endl;

    return 0;
}

