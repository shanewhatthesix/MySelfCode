#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[100001]; // 存储树的邻接表
int in_time[100001], out_time[100001];
int timer = 0; // 计时器，用于记录时间戳

// DFS遍历树，并记录每个节点的in_time和out_time
void dfs(int node, int parent) {
    in_time[node] = ++timer; // 进入节点时的时间戳
    for (int child : tree[node]) {
        if (child != parent) { // 防止回到父节点
            dfs(child, node);
        }
    }
    out_time[node] = ++timer; // 退出节点时的时间戳
}

int main() {
    int n;
    cin >> n;

    int root = -1; // 根节点
    for (int i = 1; i <= n; ++i) {
        int a, b;
        cin >> a >> b;
        if (b == -1) {
            root = a; // 找到根节点
        } else {
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
    }

    // 从根节点开始DFS遍历树
    dfs(root, -1);

    int m;
    cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        
        // 判断x与y的祖孙关系
        if (in_time[x] < in_time[y] && out_time[x] > out_time[y]) {
            cout << 1 << endl; // x是y的祖先
        } else if (in_time[y] < in_time[x] && out_time[y] > out_time[x]) {
            cout << 2 << endl; // y是x的祖先
        } else {
            cout << 0 << endl; // 既不是祖先也不是后代
        }
    }

    return 0;
}
