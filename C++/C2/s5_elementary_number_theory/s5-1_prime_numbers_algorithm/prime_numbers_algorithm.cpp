#include<bits/stdc++.h>
using namespace std;
int main()
{
	/*
	����

	����a*b=c��a��b��c��������������ô���ǳ�a��B����C������

	����һ����c������c������������

	*/

	/*
	�ҵ�����������
	int c;
	cin>>c;
	for(int i=1;i<=c;i++){
		if(c%i==0){
			cout<<i<<" ";
		}
	}
	*/

	/*
	����

	һ�����������1�����������ⲻ����������������ô���������һ��������Ҳ������
	���� 2��3��5��7��11��13��17......
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
