#include<bits/stdc++.h>
using namespace std;
/*�ýṹ��дһ��ջ

ջ��һ����֯���ݵķ�ʽ������һ��Ͱһ�������ص�������ֻ�ܲ��������������

|   |
| D |
| C |
| B |
| A |
*---*

���������ͼ�У���Ҫ��C��ʲô���ͱ���Ҫ����D����

��Ϊ����CҪ��D����������ջҪ�г�ջ�Ĳ�������Щ��������ô��ȥ���أ��϶�ҲҪ��һ����ջ�Ĳ���

*/

struct Stack{
	char a[1000];
	int top=0;
	//��ջ
	void push(char c){
		top++;
		a[top]=c;
	}
	//��ջ
	char pop(){
		char t=a[top];
		--top;
		return t;
	}
	//��ѯ
	char ztop(){
		return a[top];
	}
};

int main(){
	
	Stack zhan;
	zhan.push('x');
	zhan.push('h');
	cout<<zhan.pop()<<endl;/*�����h*/
	cout<<zhan.ztop();
	
}
