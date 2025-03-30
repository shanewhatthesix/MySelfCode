#include<bits/stdc++.h>
using namespace std;
/*

函数详解

函数语法：
返回类型 函数名(参数列表){
    执行语句;
    return 值;

}

*/

bool odd(int a){
	return a%2;
}

int main(){
	
	int a ;
	cin>>a;
	if(odd(a)) cout<<"no";
	else cout<<"yes";
}
