#include<bits/stdc++.h>
using namespace std;
int main() {

	/*1.
	�����ַ���
	insert(size_t pos,const string& str)
	pos��ʾҪ�����λ�ã�Ҳ�����±ꣻstr��ʾҪ������ַ���
	string s1_1,s1_2,s1_3;
	s1="0123456789";
	s3="aaa";
	s1.insert(5,s3);
	cout<<s1<<endl;
	�����01234aaa56789
	*/

	/*2.
	ɾ���ַ���
	erase() ��������ɾ�� string �е�һ�����ַ���������һ��ԭ��Ϊ��
	erase (size_t pos = 0, size_t len = npos);
	pos ��ʾҪɾ�������ַ�������ʼ�±꣬len ��ʾҪɾ�����ַ����ĳ��ȡ������ָ��len�Ļ�����ôֱ��ɾ����pos���ַ����������������ַ�
	string s1,s2,s3;
	s1=s2=s3="1234567890";
	s2.erase(5);
	s3.erase(5,3);
	cout<<s1<<" "<<s2<<" "<<s3;
	�����1234567890 12345 1234590
	*/

	/*3.
	��ȡ���ַ���
	substr() �������ڴ� string �ַ�������ȡ���ַ���������ԭ��Ϊ��
	substr (size_t pos = 0 , size_t len = npos);
	pos ΪҪ��ȡ�����ַ�������ʼ�±꣬len ΪҪ��ȡ�����ַ����ĳ��ȡ�
	string s1="first second third";
	string s2;
	s2=s1.substr(6,6);
	cout<<s1<<endl<<s2;
	�����
	first second third
	second*/
	
	/*4.
	�ַ������ң�����
	�������ַ���.find(�����ַ�,���Ҹ���)
	�ַ������ң�����
	�������ַ���.rfind(�����ַ�,���Ҹ���)
	*/
}
