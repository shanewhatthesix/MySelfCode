#include<bits/stdc++.h>
using namespace std;

/*
*----------------------*
| 3 | 27 | 7 | 12 | 35 |
*----------------------*
��		   |
*----------------------*
| 3 | 7 | 12 | 27 | 35 |
*----------------------*
*/

// sort �����㷨�����Ǻ�����
// �﷨��sort��������㣬�����յ㣬����������ʡ�ԣ�



/*
int main(){
	int x;//�������
	cin>>x;//�������
	int a[x];//��������

	for(int i=0;i<x;++i){
		cin>>a[i];//��������
	}

	sort(a,a+x);//ʹ�ú�������
	
	for(int i=0;i<x;++i){
		cout<<a[i]<<" ";//�������������
	}
	
	return 0;
}
*/

bool cmp(int a,int b){
	if(a>b) {return true/*����Ϊ��ȷʱ�������ַ���ǰ��*/;}
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



