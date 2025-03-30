#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

// ���巽����������
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

    // ʹ�����ȶ���
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    
    // �洢����ÿ��λ�õ���СΣ��ϵ��
    vector<vector<int>> minDanger(n, vector<int>(m, INT_MAX));
    minDanger[0][0] = danger[0][0];
    
    pq.push({danger[0][0], {0, 0}}); // �������

    while (!pq.empty()) {
        auto curr = pq.top();
        int currDanger = curr.first;
        int x = curr.second.first;
        int y = curr.second.second;
        pq.pop();

        // ��������յ�
        if (x == n - 1 && y == m - 1) {
            cout << currDanger << endl;
            return 0;
        }

        // ����ĸ�����
        for (int i = 0; i < 4; ++i) {
            int newX = x + dRow[i];
            int newY = y + dCol[i];
            // ���߽�
            if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
                // �µ�Σ��ϵ��
                int newDanger = currDanger + danger[newX][newY];
                // ����ҵ��˸�С��Σ��ϵ��������²��������ȶ���
                if (newDanger < minDanger[newX][newY]) {
                    minDanger[newX][newY] = newDanger;
                    pq.push({newDanger, {newX, newY}});
                }
            }
        }
    }

    return 0;
}
