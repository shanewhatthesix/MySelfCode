#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,n,all;
	cin>>m>>n;
	for(int i=m;i<=n;++i)
	{
		if(i%2!=0)//�ж�i�Ƿ�Ϊ���� �����ż�� ��ô����������
		{
			all+=i;
		}
	}
	cout<<all;

	return 0;
}
