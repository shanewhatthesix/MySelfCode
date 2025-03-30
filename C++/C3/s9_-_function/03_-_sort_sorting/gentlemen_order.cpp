#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
	if(a%10<b%10) {return true/*返回为正确时将此数字放在前面*/;}
	return false;
}

int main(){
	int x;//定义个数
	cin>>x;//输入个数
	int a[x];//定义数组

	for(int i=0;i<x;++i){
		cin>>a[i];//输入数组
	}

	sort(a,a+x,cmp);//使用函数排序

	for(int i=0;i<x;++i){
		cout<<a[i]<<" ";//输出排序后的数组
	}

	return 0;
}


