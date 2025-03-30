#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;  // 输入总楼层数N，起始楼层A，目标楼层B
    
    vector<int> K(N + 1);  // 存储每层楼的Ki值
    for (int i = 1; i <= N; i++) {
        cin >> K[i];
    }
    
    // 记录到达每层楼需要的最少按键次数，初始化为-1表示未访问
    vector<int> visited(N + 1, -1);
    
    queue<int> q;  // BFS使用的队列 
    q.push(A);     // 将起始楼层加入队列 
    visited[A] = 0;  // 起始楼层的按键次数为0
    
    while (!q.empty()) {
        int current = q.front();  // 当前楼层 
        q.pop();
        
        // 如果到达目标楼层，输出结果并结束程序 
        if (current == B) {
            cout << visited[current] << endl;
            return 0;
        }
        
        // 尝试向上
        if (current + K[current] <= N) {  // 确保不超过最高层 
            int up = current + K[current];
            if (visited[up] == -1) {  // 如果该层未访问过 
                visited[up] = visited[current] + 1;
                q.push(up);
            }
        }
        
        // 尝试向下
        if (current - K[current] >= 1) {  // 确保不低于第一层
            int down = current - K[current];
            if (visited[down] == -1) {  // 如果该层未访问过
                visited[down] = visited[current] + 1;
                q.push(down);
            }
        }
    }
    
    // 如果队列空了还没找到目标楼层，说明无法到达
    cout << -1 << endl;
    return 0;
}

