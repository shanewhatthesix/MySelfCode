#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 1e8 + 10;  // 定义一个常量 N，表示最大可能的数值
int n, q;  // 输入的 n 和 q，n 是上限值，q 是查询的数量
bool book[N];  // 用来标记每个数是否是素数的数组

// 获取小于等于n的所有素数
vector<int> get_primes(int n) {
    vector<int> v;
    // 从2开始，检查每个数是否是素数
    for (int i = 2; i <= n; i++) {
        if (!book[i]) v.push_back(i);  // 如果当前数是素数，加入到v中
        for (int j = 0; v[j] <= n / i; j++) {
            book[v[j] * i] = true;  // 标记所有v[j]的倍数为非素数
            if (i % v[j] == 0) break;  // 只要有一个小于等于sqrt(n)的素数整除i，停止
        }
    }
    return v;  // 返回素数数组
}

// 判断一个数是否是素数
bool is_prime(int n) {
    if (n < 2) return false;  // 小于2的数不是素数
    for (int i = 2; i <= n / i; i++) {  // 从2到sqrt(n)判断是否有约数
        if (n % i == 0) return false;  // 如果n能被i整除，则不是素数
    }
    return true;  // 如果没有找到约数，返回true，表示是素数
}

// 检查数字的每一位是否为素数
bool check(int n) {
    while (n) {  // 对n的每一位进行检查
        if (!is_prime(n)) return false;  // 如果任意一位不是素数，则返回false
        n /= 10;  // 去掉当前的最后一位
    }
    return true;  // 所有位都为素数
}

int main() {
    cin >> n;  // 输入最大数值n
    auto primes = get_primes(n);  // 获取小于等于n的所有素数
    int res = 0;  // 结果变量，用来存储符合条件的素数个数
    for (auto x : primes) {  // 遍历所有素数
        if (check(x))  // 如果该素数的每一位都为素数
            res++;  // 增加结果计数
    }
    cout << res;  // 输出结果
    return 0;  // 程序结束
}
