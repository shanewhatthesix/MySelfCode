#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <random>
#include <fstream>
#include <windows.h>
#include <set>
#include <codecvt>

std::random_device rnd;
std::mt19937 generator(rnd());

class GenerativeAI {
private:
    std::map<std::string, std::vector<std::string>> wordRel;

public:
    // 从文本文件加载训练数据
    bool load_from_file(const std::string& filename) {
        try {
            std::wifstream file(filename);
            if (!file.is_open()) {
                std::cout << "无法打开文件: " << filename << std::endl;
                return false;
            }
            
            // 设置文件编码为 UTF-8
            file.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
            
            std::wstring line;
            while (std::getline(file, line)) {
                if (!line.empty()) {
                    // 将宽字符串转换为普通字符串
                    std::string utf8_line;
                    utf8_line.assign(line.begin(), line.end());
                    learn_fromstring(utf8_line);
                }
            }

            file.close();
            std::cout << "成功从" << filename << "加载了训练数据" << std::endl;
            return true;
        }
        catch (const std::exception& e) {
            std::cout << "加载文件时出错: " << e.what() << std::endl;
            return false;
        }
    }

    void learn_fromstring(const std::string& sentence) {
        std::istringstream iss(sentence);
        std::string word;
        std::vector<std::string> tokens;
        std::vector<std::string> question_tokens;
        std::vector<std::string> answer_tokens;
        bool is_question = true;
        
        // 按空格分割句子
        while (iss >> word) {
            if (word == "？" || word == "?") {
                is_question = false;
                continue;
            }
            if (is_question) {
                question_tokens.push_back(word);
            } else {
                answer_tokens.push_back(word);
            }
        }

        // 分别处理问题和答案中的词语关系
        for (size_t i = 0; i < question_tokens.size() - 1; ++i) {
            wordRel[question_tokens[i]].push_back(question_tokens[i + 1]);
        }
        for (size_t i = 0; i < answer_tokens.size() - 1; ++i) {
            wordRel[answer_tokens[i]].push_back(answer_tokens[i + 1]);
        }
    }

    std::string sentence_generator(const std::string& startWord, int length) {
        if (wordRel.empty()) return startWord;

        // 随机选择起始词
        std::string currentWord;
        if (startWord.empty() || wordRel.find(startWord) == wordRel.end()) {
            std::vector<std::string> allWords;
            for (const auto& pair : wordRel) {
                // 只选择合适的词作为起始词
                if (pair.first.length() > 1 && 
                    pair.first.find("，") == std::string::npos &&
                    pair.first.find("。") == std::string::npos &&
                    pair.first.find("、") == std::string::npos &&
                    pair.first.find("！") == std::string::npos &&
                    pair.first.find("？") == std::string::npos &&
                    pair.first.find("：") == std::string::npos) {
                    allWords.push_back(pair.first);
                }
            }
            if (allWords.empty()) return "";
            std::uniform_int_distribution<int> wordDist(0, allWords.size() - 1);
            currentWord = allWords[wordDist(generator)];
        } else {
            currentWord = startWord;
        }

        std::string sequence = currentWord;
        std::set<std::string> usedWords;  // 记录已使用的词，避免重复
        usedWords.insert(currentWord);
        
        bool needPunctuation = false;  // 控制标点符号的添加
        
        for (int i = 0; i < length - 1; ++i) {
            if (wordRel.find(currentWord) == wordRel.end()) break;

            std::vector<std::string>& nextWords = wordRel[currentWord];
            if (nextWords.empty()) break;

            // 优先选择未使用的词
            std::vector<std::string> availableWords;
            for (const auto& word : nextWords) {
                if (usedWords.find(word) == usedWords.end()) {
                    if ((needPunctuation && (word == "，" || word == "、")) ||
                        (!needPunctuation && word != "，" && word != "。" && 
                         word != "、" && word != "！" && word != "？" && word != "：")) {
                        availableWords.push_back(word);
                    }
                }
            }

            // 如果没有合适的词，就重新选择
            if (availableWords.empty()) {
                for (const auto& word : nextWords) {
                    if ((needPunctuation && (word == "，" || word == "、")) ||
                        (!needPunctuation && word != "，" && word != "。" && 
                         word != "、" && word != "！" && word != "？" && word != "：")) {
                        availableWords.push_back(word);
                    }
                }
            }

            if (availableWords.empty()) break;

            std::uniform_int_distribution<int> distribution(0, availableWords.size() - 1);
            currentWord = availableWords[distribution(generator)];
            
            // 更新标点符号状态
            needPunctuation = (currentWord != "，" && currentWord != "。" && 
                             currentWord != "、" && currentWord != "！" && 
                             currentWord != "？" && currentWord != "：");
            
            if (needPunctuation) {
                usedWords.insert(currentWord);
            }
            
            sequence += " " + currentWord;
        }

        // 确保句子以合适的标点结束
        if (sequence.back() != '。' && sequence.back() != '！' && 
            sequence.back() != '？') {
            sequence += " 。";
        }

        return sequence;
    }

    void print_word_relations() {
        std::cout << "词语关系：" << std::endl;
        for (const auto& pair : wordRel) {
            std::cout << pair.first << ":";
            for (const auto& word : pair.second) {
                std::cout << " " << word;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};

int main() {
    // 设置控制台支持中文输出
    SetConsoleOutputCP(CP_UTF8);
    
    GenerativeAI ai;

    // 从文件加载训练数据
    if (!ai.load_from_file("training_data.txt")) {
        std::cout << "错误：无法加载训练数据文件" << std::endl;
        return 1;
    }

    // 打印学习到的词语关系
    ai.print_word_relations();

    // 生成新句子
    std::cout << "\n生成的句子：" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << i + 1 << ": " << ai.sentence_generator("", 4 + rnd() % 3) << std::endl;
    }

    system("pause");
    return 0;
}
