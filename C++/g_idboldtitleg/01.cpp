#include <bits/stdc++.h>

using namespace std;

// ������ʹ��BFSѰ�Ҵ�A��B����С����
int bfs(int N, int A, int B, const vector<int>& K){
    // ���A��B�Ƿ�����Ч��Χ��
    if(A < 1 || A > N || B < 1 || B > N){
        return -1;
    }

    // ��ʼ�����У��洢¥��Ͳ���
    queue<pair<int, int>> q;
    q.push({A, 0});

    // ��ʼ�����ʼ�¼����
    vector<bool> visited(N + 1, false);
    visited[A] = true;

    while(!q.empty()){
        // ��ȡ��ǰ¥��Ͳ���
        auto [current, steps] = q.front();
        q.pop();

        // �����ǰ¥����Ŀ��¥�㣬���ز���
        if(current == B){
            return steps;
        }

        // ���������ƶ�
        int up = current + K[current];
        if(up <= N && !visited[up]){
            q.push({up, steps + 1});
            visited[up] = true;
        }

        // ���������ƶ�
        int down = current - K[current];
        if(down >= 1 && !visited[down]){
            q.push({down, steps + 1});
            visited[down] = true;
        }
    }

    // ����޷�����Ŀ��¥�㣬����-1
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
