#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s = "WD-34750";
	//�����������,���Ի�ȡ�ַ����е��ַ�
	//��---�±�,�±��0��ʼ
	char c = s[1];//��ȡ�±�Ϊ1���ַ�
	cout<<"c="<<c<<endl;
	
	//�ַ���������,��ASCII����
	cout<<c+2<<endl;
    c+=2;
	cout<<"c="<<c;
	
	//char �����������ʱ������ֵ,����ʾ��ʱ�����ַ�
	//�ı��ַ�:������+[�±�]=���ַ���ASCII���;

	return 0;
}

