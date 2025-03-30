#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

void processJSON(const string& json, int level = 0) {
    if (level > 4) return; // 递归终止条件

    stringstream ss(json);
    char c;
    string key, value;
    vector<pair<string, string> > elements;

    // 解析JSON字符串
    while (ss >> c) {
        if (c == '{') {
            // 处理对象
            while (ss >> c && c != '}') {
                if (c == '"') {
                    ss >> key;
                    ss >> c; // 跳过冒号
                    ss >> c; // 跳过引号
                    getline(ss, value, '"');
                    elements.push_back(pair<string, string>(key, value));
                }
            }
        } else if (c == '[') {
            // 处理数组
            string arrayStr;
            getline(ss, arrayStr, ']');
            processJSON(arrayStr, level + 1);
        }
    }

    // 输出处理结果
    for (vector<pair<string, string> >::const_iterator it = elements.begin(); it != elements.end(); ++it) {
        if (it->first == "id" && !it->second.empty()) {
            for (int i = 0; i < level; ++i) {
                cout << " ";
            }
            cout << it->second << " " << elements.size() - 1 << endl;
        }
    }
}

int main() {
    string input = "[{\"id\": \"Adalia\", \"child\": []}, {\"id\": \"\", \"child\": []}, {\"id\": \"Madonna\", \"child\": []}, {\"id\": \"Bart\", \"child\": []}, {\"id\": \"\", \"child\": []}, {\"id\": \"Zoltan\", \"child\": []}, {\"id\": \"Kip\", \"child\": []}, {\"id\": \"\", \"child\": []}, {\"id\": \"\", \"child\": []}, {\"id\": \"Klaus\", \"child\": []}]";
    processJSON(input);

    return 0;
}

