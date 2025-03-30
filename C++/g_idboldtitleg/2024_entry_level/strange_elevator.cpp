#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;  // ������¥����N����ʼ¥��A��Ŀ��¥��B
    
    vector<int> K(N + 1);  // �洢ÿ��¥��Kiֵ
    for (int i = 1; i <= N; i++) {
        cin >> K[i];
    }
    
    // ��¼����ÿ��¥��Ҫ�����ٰ�����������ʼ��Ϊ-1��ʾδ����
    vector<int> visited(N + 1, -1);
    
    queue<int> q;  // BFSʹ�õĶ��� 
    q.push(A);     // ����ʼ¥�������� 
    visited[A] = 0;  // ��ʼ¥��İ�������Ϊ0
    
    while (!q.empty()) {
        int current = q.front();  // ��ǰ¥�� 
        q.pop();
        
        // �������Ŀ��¥�㣬���������������� 
        if (current == B) {
            cout << visited[current] << endl;
            return 0;
        }
        
        // ��������
        if (current + K[current] <= N) {  // ȷ����������߲� 
            int up = current + K[current];
            if (visited[up] == -1) {  // ����ò�δ���ʹ� 
                visited[up] = visited[current] + 1;
                q.push(up);
            }
        }
        
        // ��������
        if (current - K[current] >= 1) {  // ȷ�������ڵ�һ��
            int down = current - K[current];
            if (visited[down] == -1) {  // ����ò�δ���ʹ�
                visited[down] = visited[current] + 1;
                q.push(down);
            }
        }
    }
    
    // ������п��˻�û�ҵ�Ŀ��¥�㣬˵���޷�����
    cout << -1 << endl;
    return 0;
}

