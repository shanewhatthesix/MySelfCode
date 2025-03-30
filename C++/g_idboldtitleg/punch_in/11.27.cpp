#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

// 定义方向，上下左右
const int dRow[] = {0, 0, 1, -1};
const int dCol[] = {1, -1, 0, 0};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> danger(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> danger[i][j];
        }
    }

    // 使用优先队列
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    
    // 存储到达每个位置的最小危险系数
    vector<vector<int>> minDanger(n, vector<int>(m, INT_MAX));
    minDanger[0][0] = danger[0][0];
    
    pq.push({danger[0][0], {0, 0}}); // 插入起点

    while (!pq.empty()) {
        auto curr = pq.top();
        int currDanger = curr.first;
        int x = curr.second.first;
        int y = curr.second.second;
        pq.pop();

        // 如果到达终点
        if (x == n - 1 && y == m - 1) {
            cout << currDanger << endl;
            return 0;
        }

        // 检查四个方向
        for (int i = 0; i < 4; ++i) {
            int newX = x + dRow[i];
            int newY = y + dCol[i];
            // 检查边界
            if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
                // 新的危险系数
                int newDanger = currDanger + danger[newX][newY];
                // 如果找到了更小的危险系数，则更新并加入优先队列
                if (newDanger < minDanger[newX][newY]) {
                    minDanger[newX][newY] = newDanger;
                    pq.push({newDanger, {newX, newY}});
                }
            }
        }
    }

    return 0;
}
