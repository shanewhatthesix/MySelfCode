#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

void processJSON(const string& json, int level = 0) {
    if (level > 4) return; // �ݹ���ֹ����

    stringstream ss(json);
    char c;
    string key, value;
    vector<pair<string, string> > elements;

    // ����JSON�ַ���
    while (ss >> c) {
        if (c == '{') {
            // �������
            while (ss >> c && c != '}') {
                if (c == '"') {
                    ss >> key;
                    ss >> c; // ����ð��
                    ss >> c; // ��������
                    getline(ss, value, '"');
                    elements.push_back(pair<string, string>(key, value));
                }
            }
        } else if (c == '[') {
            // ��������
            string arrayStr;
            getline(ss, arrayStr, ']');
            processJSON(arrayStr, level + 1);
        }
    }

    // ���������
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

