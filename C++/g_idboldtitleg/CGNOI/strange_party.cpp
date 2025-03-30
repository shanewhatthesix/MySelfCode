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
    
    // ��ȡÿ���˵���Ҫ�̶�k
    vector<int> k(n);
    for(int i = 0; i < n; i++) {
        cin >> k[i];
    }
    
    // ��ȡ����۸�
    vector<int> c(m);
    for(int i = 0; i < m; i++) {
        cin >> c[i];
    }
    
    // ʹ��set��ά���������������
    set<pair<int,int>> available;  // {����۸�, ��������}
    for(int i = 0; i < m; i++) {
        available.insert({c[i], i});
    }
    
    // ����kֵ�Ӵ�С������ÿ����
    vector<pair<int, int>> people;  // {kֵ, ԭʼ����}
    for(int i = 0; i < n; i++) {
        people.push_back({k[i], i});
    }
    sort(people.rbegin(), people.rend());
    
    long long total_cost = 0;
    
    // ����ÿ����
    for(auto [ki, idx] : people) {
        // ����Ļ���
        int envelope_cost = c[ki-1];
        
        // �ҵ���������������˵ģ�������С��ki������
        auto it = available.lower_bound({0, -1});
        int best_gift_cost = envelope_cost;
        int best_gift_idx = -1;
        
        // ֻ����ǰki�������е�����˵�
        while(it != available.end() && it->second < ki) {
            if(it->first < best_gift_cost) {
                best_gift_cost = it->first;
                best_gift_idx = it->second;
                break;  // �ҵ���һ���Ϳ���ֹͣ�ˣ���Ϊset�������
            }
            it++;
        }
        
        if(best_gift_idx != -1) {
            // ����ҵ��˸����˵�����͸�����
            available.erase({c[best_gift_idx], best_gift_idx});  // �ӿ��ü������Ƴ�
            total_cost += best_gift_cost;
        } else {
            // ��������
            total_cost += envelope_cost;
        }
    }
    
    cout << total_cost << endl;
    return 0;
}
