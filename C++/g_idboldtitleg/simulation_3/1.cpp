#include<bits/stdc++.h>
using namespace std;
long long int x[10050];
int n;

long long int max_min(int a){
    // a==1 �������ֵ, a==-1 ������Сֵ
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

    long long int maxVal = max_min(1); // �������ֵ
    long long int minVal = max_min(-1); // ������Сֵ

    for(int i=1; i<=n; i++){
        x[i] = (x[i] - minVal) * maxVal; // ��ÿ��Ԫ��ִ�в���
        x[i] = x[i] % 1000000007; // ȡģ����
    }

    for(int i=1; i<=n; i++){
        cout << x[i] << " ";
    }
    cout << endl; // �������
    return 0;
}

