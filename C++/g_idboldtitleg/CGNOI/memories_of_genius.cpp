#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int n;
    
    // �����߶���
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
        
        // ���ڵ�洢�ӽڵ�����ֵ
        tree[node] = max(tree[leftNode], tree[rightNode]);
    }
    
    // ��ѯ�������ֵ
    int query(int node, int start, int end, int left, int right) {
        // �����ѯ�����ڵ�ǰ������
        if(right < start || left > end) {
            return INT_MIN;
        }
        
        // �����ǰ������ȫ�����ڲ�ѯ������
        if(left <= start && end <= right) {
            return tree[node];
        }
        
        // �ֱ��ѯ��������
        int mid = (start + end) / 2;
        int leftMax = query(2 * node + 1, start, mid, left, right);
        int rightMax = query(2 * node + 2, mid + 1, end, left, right);
        
        return max(leftMax, rightMax);
    }
    
public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        // �����߶�������������С
        int height = ceil(log2(n));
        int maxSize = 2 * pow(2, height) - 1;
        tree.resize(maxSize);
        
        build(arr, 0, 0, n - 1);
    }
    
    int queryMax(int left, int right) {
        // ����ѯ��Χת��Ϊ0-based����
        return query(0, 0, n - 1, left - 1, right - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // ����N������
    int N;
    cin >> N;
    vector<int> numbers(N);
    for(int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    
    // �����߶���
    SegmentTree segTree(numbers);
    
    // �����ѯ
    int M;
    cin >> M;
    while(M--) {
        int A, B;
        cin >> A >> B;
        cout << segTree.queryMax(A, B) << "\n";
    }
    
    return 0;
}
