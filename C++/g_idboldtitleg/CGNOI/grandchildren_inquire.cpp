#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[100001]; // �洢�����ڽӱ�
int in_time[100001], out_time[100001];
int timer = 0; // ��ʱ�������ڼ�¼ʱ���

// DFS������������¼ÿ���ڵ��in_time��out_time
void dfs(int node, int parent) {
    in_time[node] = ++timer; // ����ڵ�ʱ��ʱ���
    for (int child : tree[node]) {
        if (child != parent) { // ��ֹ�ص����ڵ�
            dfs(child, node);
        }
    }
    out_time[node] = ++timer; // �˳��ڵ�ʱ��ʱ���
}

int main() {
    int n;
    cin >> n;

    int root = -1; // ���ڵ�
    for (int i = 1; i <= n; ++i) {
        int a, b;
        cin >> a >> b;
        if (b == -1) {
            root = a; // �ҵ����ڵ�
        } else {
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
    }

    // �Ӹ��ڵ㿪ʼDFS������
    dfs(root, -1);

    int m;
    cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        
        // �ж�x��y�������ϵ
        if (in_time[x] < in_time[y] && out_time[x] > out_time[y]) {
            cout << 1 << endl; // x��y������
        } else if (in_time[y] < in_time[x] && out_time[y] > out_time[x]) {
            cout << 2 << endl; // y��x������
        } else {
            cout << 0 << endl; // �Ȳ�������Ҳ���Ǻ��
        }
    }

    return 0;
}
