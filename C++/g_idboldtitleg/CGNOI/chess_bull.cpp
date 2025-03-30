#include <bits/stdc++.h>
using namespace std;

// 定义牛的8个可能移动方向
const int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

struct Point {
    int x, y, steps;
    Point(int x = 0, int y = 0, int steps = 0) : x(x), y(y), steps(steps) {}
};

class Solution {
private:
    int cols, rows;
    vector<vector<char>> farm;
    vector<vector<bool>> visited;
    Point start, target;

    bool isValid(int x, int y) {
        return x >= 0 && x < cols && y >= 0 && y < rows && 
               farm[y][x] != '*' && !visited[y][x];
    }

    void findStartAndTarget() {
        for (int y = 0; y < rows; y++) {
            for (int x = 0; x < cols; x++) {
                if (farm[y][x] == 'K') {
                    start = Point(x, y);//记录出发点 
                }
                if (farm[y][x] == 'H') {
                    target = Point(x, y);//记录最终位置 
                }
            }
        }
    }

public:
    int findMinSteps() {
        cin >> cols >> rows;
        
        // 初始化农场地图和访问数组
        farm.resize(rows, vector<char>(cols));
        visited.resize(rows, vector<bool>(cols, false));
        
        // 读入地图
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> farm[i][j];
            }
        }
        
        findStartAndTarget();
        
        // 使用BFS寻找最短路径
        queue<Point> q;
        q.push(start);
        visited[start.y][start.x] = true;
        
        while (!q.empty()) {
            Point current = q.front();
            q.pop();
            
            // 如果到达目标点
            if (current.x == target.x && current.y == target.y) {
                return current.steps;
            }
            
            // 尝试所有可能的移动
            for (int i = 0; i < 8; i++) {
                int newX = current.x + dx[i];
                int newY = current.y + dy[i];
                
                if (isValid(newX, newY)) {
                    visited[newY][newX] = true;
                    q.push(Point(newX, newY, current.steps + 1));
                }
            }
        }
        
        return -1; // 如果无法到达目标
    }
};

int main() {
    Solution solution;
    cout << solution.findMinSteps() << endl;
    return 0;
}
