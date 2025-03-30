#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;  // 声明变量n，用于存储测试用例的数量
    cin >> n;  // 输入测试用例的数量
    int idx = -1;  // 用于存储最大比例的索引，初始化为-1
    double maxx = -1;  // 用于存储最大比例值，初始化为-1

    // 遍历每一个测试用例
    for (int i = 1; i <= n; i++) {
        int a, b;  // 用于存储每个测试用例中的a和b
        cin >> a >> b;  // 输入a和b的值

        // 如果b/a的比值大于当前的最大比值
        if (b * 1.0 / a > maxx) {
            maxx = b * 1.0 / a;  // 更新最大比值
            idx = i;  // 更新最大比值所在的测试用例的索引
            
        }
    }

    cout << idx;  // 输出最大比值所在测试用例的索引
    return 0;
}
