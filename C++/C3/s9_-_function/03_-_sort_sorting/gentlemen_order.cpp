#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
	if(a%10<b%10) {return true/*����Ϊ��ȷʱ�������ַ���ǰ��*/;}
	return false;
}

int main(){
	int x;//�������
	cin>>x;//�������
	int a[x];//��������

	for(int i=0;i<x;++i){
		cin>>a[i];//��������
	}

	sort(a,a+x,cmp);//ʹ�ú�������

	for(int i=0;i<x;++i){
		cout<<a[i]<<" ";//�������������
	}

	return 0;
}


