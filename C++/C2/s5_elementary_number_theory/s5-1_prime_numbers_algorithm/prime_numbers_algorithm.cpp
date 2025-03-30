#include<bits/stdc++.h>
using namespace std;
int main()
{
	/*
	因数

	假如a*b=c（a、b、c都是整数），那么我们称a和B就是C的因素

	输入一个数c，你能c的所有因数吗？

	*/

	/*
	找到所有因数：
	int c;
	cin>>c;
	for(int i=1;i<=c;i++){
		if(c%i==0){
			cout<<i<<" ";
		}
	}
	*/

	/*
	质数

	一个数如果除了1和它本身以外不再有其他因数，那么这个数就是一个质数，也叫素数
	例如 2、3、5、7、11、13、17......
	*/

	int c,s=0;
	cin>>c;
	for(int i=2; i*i<c; ++i)
	{
		if(c%i==0)
		{
			s++;
			break;
		}

	}
	if(s==0)
	{
		cout<<"yes";
	}
	else
	{
		cout<<"no";
	}
}
