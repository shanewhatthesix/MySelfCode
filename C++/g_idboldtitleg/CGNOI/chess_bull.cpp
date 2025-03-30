#include <bits/stdc++.h>
using namespace std;

// ����ţ��8�������ƶ�����
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
                    start = Point(x, y);//��¼������ 
                }
                if (farm[y][x] == 'H') {
                    target = Point(x, y);//��¼����λ�� 
                }
            }
        }
    }

public:
    int findMinSteps() {
        cin >> cols >> rows;
        
        // ��ʼ��ũ����ͼ�ͷ�������
        farm.resize(rows, vector<char>(cols));
        visited.resize(rows, vector<bool>(cols, false));
        
        // �����ͼ
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> farm[i][j];
            }
        }
        
        findStartAndTarget();
        
        // ʹ��BFSѰ�����·��
        queue<Point> q;
        q.push(start);
        visited[start.y][start.x] = true;
        
        while (!q.empty()) {
            Point current = q.front();
            q.pop();
            
            // �������Ŀ���
            if (current.x == target.x && current.y == target.y) {
                return current.steps;
            }
            
            // �������п��ܵ��ƶ�
            for (int i = 0; i < 8; i++) {
                int newX = current.x + dx[i];
                int newY = current.y + dy[i];
                
                if (isValid(newX, newY)) {
                    visited[newY][newX] = true;
                    q.push(Point(newX, newY, current.steps + 1));
                }
            }
        }
        
        return -1; // ����޷�����Ŀ��
    }
};

int main() {
    Solution solution;
    cout << solution.findMinSteps() << endl;
    return 0;
}
