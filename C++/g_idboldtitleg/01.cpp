#include <bits/stdc++.h>

using namespace std;

// 函数：使用BFS寻找从A到B的最小步数
int bfs(int N, int A, int B, const vector<int>& K){
    // 检查A和B是否在有效范围内
    if(A < 1 || A > N || B < 1 || B > N){
        return -1;
    }

    // 初始化队列，存储楼层和步数
    queue<pair<int, int>> q;
    q.push({A, 0});

    // 初始化访问记录数组
    vector<bool> visited(N + 1, false);
    visited[A] = true;

    while(!q.empty()){
        // 获取当前楼层和步数
        auto [current, steps] = q.front();
        q.pop();

        // 如果当前楼层是目标楼层，返回步数
        if(current == B){
            return steps;
        }

        // 尝试向上移动
        int up = current + K[current];
        if(up <= N && !visited[up]){
            q.push({up, steps + 1});
            visited[up] = true;
        }

        // 尝试向下移动
        int down = current - K[current];
        if(down >= 1 && !visited[down]){
            q.push({down, steps + 1});
            visited[down] = true;
        }
    }

    // 如果无法到达目标楼层，返回-1
    return -1;
}

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> K(N + 1);
    for(int i = 1; i <= N; ++i){
        cin >> K[i];
    }

    int result = bfs(N, A, B, K);
    cout << result;
    return 0;
}
