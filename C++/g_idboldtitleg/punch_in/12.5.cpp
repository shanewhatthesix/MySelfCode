#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> need;
vector<vector<int>> foods;
vector<int> best_solution;
int min_foods = INT_MAX;

// ����Ƿ���������΢��Ԫ������
bool check_satisfy(vector<int>& current_total) {
    for (int i = 0; i < n; i++) {
        if (current_total[i] < need[i]) {
            return false;
        }
    }
    return true;
}

// �����������Ž�
void dfs(int index, vector<int>& current_total, vector<int>& current_solution) {
    // ����Ѿ�����������ʳ��
    if (index == m) {
        // ����Ƿ���������
        if (check_satisfy(current_total)) {
            // �������Ž�
            if (current_solution.size() < min_foods || 
                (current_solution.size() == min_foods && 
                 current_solution < best_solution)) {
                min_foods = current_solution.size();
                best_solution = current_solution;
            }
        }
        return;
    }

    // ��ѡ��ǰʳ��
    dfs(index + 1, current_total, current_solution);

    // ѡ��ǰʳ��
    vector<int> new_total = current_total;
    for (int j = 0; j < n; j++) {
        new_total[j] += foods[index][j];
    }
    current_solution.push_back(index + 1);
    dfs(index + 1, new_total, current_solution);
    current_solution.pop_back();
}

int main() {
    // ��ȡ����
    cin >> n;
    need.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> need[i];
    }

    cin >> m;
    foods.resize(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> foods[i][j];
        }
    }

    // ��ʼ����ǰ�����͵�ǰ��
    vector<int> current_total(n, 0);
    vector<int> current_solution;

    // ��ʼ����
    dfs(0, current_total, current_solution);

    // ������
    cout << min_foods;
    for (int food : best_solution) {
        cout << " " << food;
    }
    cout << endl;

    return 0;
}
