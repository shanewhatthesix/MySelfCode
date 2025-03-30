#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,n,all;
	cin>>m>>n;
	for(int i=m;i<=n;++i)
	{
		if(i%2!=0)//判断i是否为奇数 如果是偶数 那么跳过不处理
		{
			all+=i;
		}
	}
	cout<<all;

	return 0;
}
