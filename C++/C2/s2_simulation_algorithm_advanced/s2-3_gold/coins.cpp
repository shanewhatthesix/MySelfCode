#include<bits/stdc++.h>
using namespace std;
int main()
{
	/*
	6
	
	1  2  3  4  5  6  7
	1  2  2  3  3  3  4
	1  3  5  8  11 14 18
	
	*/
	int n;
	cin>>n;//�����N�졣
	int daily=1;//�趨��һ��Ĺ���
	int c=0;//ͳ�Ʒ���ͬ���ʵ����������ж��Ƿ�Ӧ���ǹ��ʡ�
	int s=0;//ͳ��Ŀǰ�ܹ����˶��ٹ��ʣ�
	for(int i=1;i<=n;++i){
		s+=daily;//Ϊs���ϵ���Ĺ��ʡ�
		c++;// ��һ�졣
		if(c==daily){//�ж��Ƿ�Ӧ�üӹ����ˡ�
			daily++;//�ӹ��ʡ�
			c=0;//������c���㡣
		}
	}
	cout<<s;// �����N�췢�˶��ٹ���
	return 0;
}

