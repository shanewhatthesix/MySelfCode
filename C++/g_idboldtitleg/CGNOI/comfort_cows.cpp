#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

// �ߵĽṹ
struct Edge {
    int from, to, weight;
    Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
    bool operator<(const Edge& other) const {
        return weight > other.weight;
    }
};

class UnionFind {
private:
    vector<int> parent;
public:
    UnionFind(int n) : parent(n) {
        for(int i = 0; i < n; i++) 
            parent[i] = i;
    }
    
    int find(int x) {
        if(parent[x] != x) 
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }
    
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
private:
    int N;
    vector<int> talkTime;
    vector<vector<pair<int, int>>> graph;
    
    // ʹ��DFS���������������ʱ��
    void dfs(int u, int parent, vector<bool>& visited, long long& total_time) {
        visited[u] = true;
        
        // �ڵ�ǰ����̸��
        total_time += talkTime[u];
        
        // ��������δ���ʵ��ھ�
        for(const auto& [v, w] : graph[u]) {
            if(!visited[v]) {
                total_time += 2 * w;  // ����·��
                dfs(v, u, visited, total_time);
            }
        }
    }

public:
    Solution(int n) : N(n), talkTime(n), graph(n) {}
    
    void addTalkTime(int i, int time) {
        talkTime[i] = time;
    }
    
    // ������С��������������С��ʱ��
    long long solve(vector<Edge>& edges) {
        // ʹ��Kruskal�㷨������С������
        sort(edges.begin(), edges.end());
        UnionFind uf(N);
        
        // ���ͼ
        for(int i = 0; i < N; i++)
            graph[i].clear();
            
        // ������С������
        for(const Edge& e : edges) {
            int u = e.from - 1;
            int v = e.to - 1;
            if(!uf.connected(u, v)) {
                uf.unite(u, v);
                graph[u].push_back({v, e.weight});
                graph[v].push_back({u, e.weight});
            }
        }
        
        // ����ÿ��������Ϊ���
        long long min_total_time = LLONG_MAX;
        for(int start = 0; start < N; start++) {
            vector<bool> visited(N, false);
            long long total_time = 0;
            
            // ����Ӵ�����������ʱ��
            dfs(start, -1, visited, total_time);
            
            // ���������Ķ���һ��̸��ʱ�䣨��ΪҪ�ص���㣩
            total_time += talkTime[start];
            
            min_total_time = min(min_total_time, total_time);
        }
        
        return min_total_time;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, P;
    cin >> N >> P;
    
    Solution sol(N);
    
    // ����ÿ��������̸��ʱ��
    for(int i = 0; i < N; i++) {
        int time;
        cin >> time;
        sol.addTalkTime(i, time);
    }
    
    // �����·��Ϣ
    vector<Edge> edges;
    for(int i = 0; i < P; i++) {
        int from, to, len;
        cin >> from >> to >> len;
        edges.emplace_back(from, to, len);
    }
    
    cout << sol.solve(edges) << endl;
    
    return 0;
}
