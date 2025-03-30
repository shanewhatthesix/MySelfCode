/*
每个合数都可以写成几个质数相乘的形式

把一个合数用质因数相乘的形式表示出来，叫做分解质因数也叫分解质因子

比如 30=2*3*5
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a=2,n;
	cin>>n;
	while(n>1){
		while(n%a==0){
			cout<<a<<" ";
			n/=a;
		}
		a++;
	}
}

