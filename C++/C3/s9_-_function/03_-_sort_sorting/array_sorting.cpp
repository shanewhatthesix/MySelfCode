#include<bits/stdc++.h>
using namespace std;

/*
*----------------------*
| 3 | 27 | 7 | 12 | 35 |
*----------------------*
·		   |
*----------------------*
| 3 | 7 | 12 | 27 | 35 |
*----------------------*
*/

// sort 不是算法，而是函数。
// 语法：sort（数组起点，数组终点，排序函数可以省略）



/*
int main(){
	int x;//定义个数
	cin>>x;//输入个数
	int a[x];//定义数组

	for(int i=0;i<x;++i){
		cin>>a[i];//输入数组
	}

	sort(a,a+x);//使用函数排序
	
	for(int i=0;i<x;++i){
		cout<<a[i]<<" ";//输出排序后的数组
	}
	
	return 0;
}
*/

bool cmp(int a,int b){
	if(a>b) {return true/*返回为正确时将此数字放在前面*/;}
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



