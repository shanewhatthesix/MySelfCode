#include<bits/stdc++.h>
using namespace std;
long long int x[10050];
int n;

long long int max_min(int a){
    // a==1 返回最大值, a==-1 返回最小值
    long long int maxn=x[1], minn=x[1];
    for(int i=1; i<=n; i++){
        if(x[i]>maxn){
            maxn=x[i];
        }
        if(x[i]<minn){
            minn=x[i];
        }
    }
    if(a==1){
        return maxn;
    } else {
        return minn;
    }
}

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> x[i];
    }

    long long int maxVal = max_min(1); // 计算最大值
    long long int minVal = max_min(-1); // 计算最小值

    for(int i=1; i<=n; i++){
        x[i] = (x[i] - minVal) * maxVal; // 对每个元素执行操作
        x[i] = x[i] % 1000000007; // 取模操作
    }

    for(int i=1; i<=n; i++){
        cout << x[i] << " ";
    }
    cout << endl; // 输出换行
    return 0;
}

