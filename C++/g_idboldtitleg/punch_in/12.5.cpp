#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> need;
vector<vector<int>> foods;
vector<int> best_solution;
int min_foods = INT_MAX;

// 检查是否满足所有微量元素需求
bool check_satisfy(vector<int>& current_total) {
    for (int i = 0; i < n; i++) {
        if (current_total[i] < need[i]) {
            return false;
        }
    }
    return true;
}

// 回溯搜索最优解
void dfs(int index, vector<int>& current_total, vector<int>& current_solution) {
    // 如果已经搜索完所有食材
    if (index == m) {
        // 检查是否满足需求
        if (check_satisfy(current_total)) {
            // 更新最优解
            if (current_solution.size() < min_foods || 
                (current_solution.size() == min_foods && 
                 current_solution < best_solution)) {
                min_foods = current_solution.size();
                best_solution = current_solution;
            }
        }
        return;
    }

    // 不选择当前食材
    dfs(index + 1, current_total, current_solution);

    // 选择当前食材
    vector<int> new_total = current_total;
    for (int j = 0; j < n; j++) {
        new_total[j] += foods[index][j];
    }
    current_solution.push_back(index + 1);
    dfs(index + 1, new_total, current_solution);
    current_solution.pop_back();
}

int main() {
    // 读取输入
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

    // 初始化当前总量和当前解
    vector<int> current_total(n, 0);
    vector<int> current_solution;

    // 开始搜索
    dfs(0, current_total, current_solution);

    // 输出结果
    cout << min_foods;
    for (int food : best_solution) {
        cout << " " << food;
    }
    cout << endl;

    return 0;
}
