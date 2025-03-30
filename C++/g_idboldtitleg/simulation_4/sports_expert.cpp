#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 自定义比较函数
bool compare(int a, int b) {
    return abs(a) < abs(b);
}

int countAccessibleMarkers(long long T, int n, vector<int>& positions) {
    // 使用自定义比较函数进行排序
    sort(positions.begin(), positions.end(), compare);

    // cout << "排序后的路标位置: ";
    for (int i = 0; i < n; i++) {
        // cout << positions[i] << " ";
    }
    cout << endl;

    int accessibleCount = 0;
    int currentPosition = 0; // xx老师当前的位置，初始为0

    // 遍历每个路标
    for (int i = 0; i < n; i++) {
        int pos = positions[i];
        long long distance = abs(pos - currentPosition); // 从当前路标到下一个路标的距离
        // cout << "当前路标: " << pos << ", 距离: " << distance << ", 剩余时间: " << T << endl;

        if (T >= distance) { // 如果还有足够的时间到达这个路标
            T -= distance; // 减去所需的时间
            currentPosition = pos; // 更新当前路标位置
            accessibleCount++; // 访问的路标数量加1
            // cout << "访问路标 " << pos << "，新的剩余时间: " << T << ", 当前可访问路标数量: " << accessibleCount << endl;
        } else {
            // cout << "无法访问路标 " << pos << "，时间不足，停止访问。" << endl;
            break; // 没有足够的时间了，停止访问
        }
    }

    return accessibleCount;
}

int main() {
    long long T;
    int n;

    // 输入时间 T 和路标数量 n
    cin >> T >> n;

    vector<int> positions(n);

    // 输入每个路标的位置
    for (int i = 0; i < n; i++) {
        cin >> positions[i];
    }

    // 计算可访问的路标数量并输出
    int result = countAccessibleMarkers(T, n, positions);
    cout/* << "最终可访问的路标数量: " */<< result/* << endl*/;

    return 0;
}

