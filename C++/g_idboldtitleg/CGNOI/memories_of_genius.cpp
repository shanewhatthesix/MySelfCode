#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int n;
    
    // 构建线段树
    void build(const vector<int>& arr, int node, int start, int end) {
        if(start == end) {
            tree[node] = arr[start];
            return;
        }
        
        int mid = (start + end) / 2;
        int leftNode = 2 * node + 1;
        int rightNode = 2 * node + 2;
        
        build(arr, leftNode, start, mid);
        build(arr, rightNode, mid + 1, end);
        
        // 父节点存储子节点的最大值
        tree[node] = max(tree[leftNode], tree[rightNode]);
    }
    
    // 查询区间最大值
    int query(int node, int start, int end, int left, int right) {
        // 如果查询区间在当前区间外
        if(right < start || left > end) {
            return INT_MIN;
        }
        
        // 如果当前区间完全包含在查询区间内
        if(left <= start && end <= right) {
            return tree[node];
        }
        
        // 分别查询左右子树
        int mid = (start + end) / 2;
        int leftMax = query(2 * node + 1, start, mid, left, right);
        int rightMax = query(2 * node + 2, mid + 1, end, left, right);
        
        return max(leftMax, rightMax);
    }
    
public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        // 计算线段树所需的数组大小
        int height = ceil(log2(n));
        int maxSize = 2 * pow(2, height) - 1;
        tree.resize(maxSize);
        
        build(arr, 0, 0, n - 1);
    }
    
    int queryMax(int left, int right) {
        // 将查询范围转换为0-based索引
        return query(0, 0, n - 1, left - 1, right - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // 读入N和数组
    int N;
    cin >> N;
    vector<int> numbers(N);
    for(int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    
    // 构建线段树
    SegmentTree segTree(numbers);
    
    // 处理查询
    int M;
    cin >> M;
    while(M--) {
        int A, B;
        cin >> A >> B;
        cout << segTree.queryMax(A, B) << "\n";
    }
    
    return 0;
}
