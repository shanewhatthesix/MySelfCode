#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	cin>>n;
	for(int i=0;n>0;++i){
		cout<<n%10<<endl;//��ȡ����������n�����һλ������
		n/=10;//��N����10,��������ʹ���˵����һλ��
	}
	return 0;
}
