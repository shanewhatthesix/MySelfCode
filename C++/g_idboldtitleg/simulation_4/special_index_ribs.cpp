#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 使用埃拉托斯特尼筛法生成质数
vector<bool> generatePrimes(int maxNum) {
    vector<bool> isPrime(maxNum + 1, true);
    isPrime[0] = isPrime[1] = false; // 0 和 1 不是质数

    for (int i = 2; i * i <= maxNum; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= maxNum; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

// 检查一个数是否是特殊质数
bool isSpecialPrime(int num, const vector<bool>& isPrime) {
    int temp = num;
    while (temp > 0) {
        if (!isPrime[temp]) {
            return false; // 如果某个后缀不是质数，返回 false
        }
        temp /= 10; // 去掉最后一位数字
    }
    return true; // 所有后缀都是质数
}

// 生成所有长度为 n 的特殊质数
void findSpecialPrimes(int n) {
    // 计算最大值
    int maxNum = pow(10, n) - 1; // 10^n - 1
    vector<bool> isPrime = generatePrimes(maxNum); // 生成所有质数

    // 输出长度为 n 的特殊质数
    for (int i = pow(10, n - 1); i <= maxNum; i++) {
        if (isPrime[i] && isSpecialPrime(i, isPrime)) { // 先判断是否为质数，再检查是否为特殊质数
            cout << i << endl;
        }
    }
}

int main() {
    int n;
    cin >> n; // 输入肋骨的数量
    findSpecialPrimes(n); // 查找特殊质数
    return 0;
}

