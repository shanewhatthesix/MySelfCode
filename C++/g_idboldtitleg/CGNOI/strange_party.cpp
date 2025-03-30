#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    // 读取每个人的重要程度k
    vector<int> k(n);
    for(int i = 0; i < n; i++) {
        cin >> k[i];
    }
    
    // 读取礼物价格
    vector<int> c(m);
    for(int i = 0; i < m; i++) {
        cin >> c[i];
    }
    
    // 使用set来维护可用礼物的索引
    set<pair<int,int>> available;  // {礼物价格, 礼物索引}
    for(int i = 0; i < m; i++) {
        available.insert({c[i], i});
    }
    
    // 按照k值从大到小排序处理每个人
    vector<pair<int, int>> people;  // {k值, 原始索引}
    for(int i = 0; i < n; i++) {
        people.push_back({k[i], i});
    }
    sort(people.rbegin(), people.rend());
    
    long long total_cost = 0;
    
    // 处理每个人
    for(auto [ki, idx] : people) {
        // 红包的花费
        int envelope_cost = c[ki-1];
        
        // 找到可用礼物中最便宜的，且索引小于ki的礼物
        auto it = available.lower_bound({0, -1});
        int best_gift_cost = envelope_cost;
        int best_gift_idx = -1;
        
        // 只考虑前ki个礼物中的最便宜的
        while(it != available.end() && it->second < ki) {
            if(it->first < best_gift_cost) {
                best_gift_cost = it->first;
                best_gift_idx = it->second;
                break;  // 找到第一个就可以停止了，因为set是有序的
            }
            it++;
        }
        
        if(best_gift_idx != -1) {
            // 如果找到了更便宜的礼物，就给礼物
            available.erase({c[best_gift_idx], best_gift_idx});  // 从可用集合中移除
            total_cost += best_gift_cost;
        } else {
            // 否则给红包
            total_cost += envelope_cost;
        }
    }
    
    cout << total_cost << endl;
    return 0;
}
