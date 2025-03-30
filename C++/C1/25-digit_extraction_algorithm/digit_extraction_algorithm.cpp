#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	cin>>n;
	for(int i=0;n>0;++i){
		cout<<n%10<<endl;//提取出输入数字n的最后一位并换行
		n/=10;//将N除以10,用以舍弃使用了的最后一位数
	}
	return 0;
}
