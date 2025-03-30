#include<bits/stdc++.h>
using namespace std;

void calculateDrops(long long n) {
    // 数组来存储每个品阶的水滴数量
    vector<long long> drops(11, 0); // drops[i] 表示 i 品水滴的数量
    drops[1] = n; // 初始一品水滴数量

    // 从1品水滴开始合成
    for (int i = 1; i < 10; i++) { // 从1品到9品
        long long toCombine = drops[i] / 9; // 可合成的高品水滴数量
        drops[i + 1] += toCombine; // 更新下一个品阶的水滴数量
        drops[i] %= 9; // 剩余的水滴数量
    }

    // 输出结果，从10品到1品
    for (int i = 10; i >= 1; i--) {
        if (drops[i] > 0) {
            cout << i << ":" << drops[i] << endl/*" "*/;
        }
    }
    // cout << endl;
}

int main() {
    long long n;
    cin >> n; // 输入一品水滴数量
    calculateDrops(n); // 计算合成结果
    return 0;
}

