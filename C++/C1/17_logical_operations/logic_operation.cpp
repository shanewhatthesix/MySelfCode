#include<bits/stdc++.h>
using namespace std;
int main()
{
	// �߼���ϵ  �����           ˵��
	//    ��       &&       ���Լ����Ϊ����
	//    ��       ||       ���Լ����Ϊ����
	//    ��       !              ȡ��
	int mark,poem;
	cin>>mark>>poem;
	if (mark>=425 && poem>=300){
		printf("qualified");
	}
	else {
		printf("unqualified");
	}
	
	return 0;
}
