#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

// 边的结构
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
    
    // 使用DFS计算从起点出发的总时间
    void dfs(int u, int parent, vector<bool>& visited, long long& total_time) {
        visited[u] = true;
        
        // 在当前牧场谈话
        total_time += talkTime[u];
        
        // 访问所有未访问的邻居
        for(const auto& [v, w] : graph[u]) {
            if(!visited[v]) {
                total_time += 2 * w;  // 来回路程
                dfs(v, u, visited, total_time);
            }
        }
    }

public:
    Solution(int n) : N(n), talkTime(n), graph(n) {}
    
    void addTalkTime(int i, int time) {
        talkTime[i] = time;
    }
    
    // 构建最小生成树并返回最小总时间
    long long solve(vector<Edge>& edges) {
        // 使用Kruskal算法构建最小生成树
        sort(edges.begin(), edges.end());
        UnionFind uf(N);
        
        // 清空图
        for(int i = 0; i < N; i++)
            graph[i].clear();
            
        // 构建最小生成树
        for(const Edge& e : edges) {
            int u = e.from - 1;
            int v = e.to - 1;
            if(!uf.connected(u, v)) {
                uf.unite(u, v);
                graph[u].push_back({v, e.weight});
                graph[v].push_back({u, e.weight});
            }
        }
        
        // 尝试每个牧场作为起点
        long long min_total_time = LLONG_MAX;
        for(int start = 0; start < N; start++) {
            vector<bool> visited(N, false);
            long long total_time = 0;
            
            // 计算从此起点出发的总时间
            dfs(start, -1, visited, total_time);
            
            // 加上在起点的额外一次谈话时间（因为要回到起点）
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
    
    // 读入每个牧场的谈话时间
    for(int i = 0; i < N; i++) {
        int time;
        cin >> time;
        sol.addTalkTime(i, time);
    }
    
    // 读入道路信息
    vector<Edge> edges;
    for(int i = 0; i < P; i++) {
        int from, to, len;
        cin >> from >> to >> len;
        edges.emplace_back(from, to, len);
    }
    
    cout << sol.solve(edges) << endl;
    
    return 0;
}
