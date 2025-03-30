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
	cin>>n;//输入第N天。
	int daily=1;//设定第一天的工资
	int c=0;//统计发相同工资的天数，以判断是否应该涨工资。
	int s=0;//统计目前总共发了多少工资？
	for(int i=1;i<=n;++i){
		s+=daily;//为s加上当天的工资。
		c++;// 加一天。
		if(c==daily){//判断是否应该加工资了。
			daily++;//加工资。
			c=0;//将变量c归零。
		}
	}
	cout<<s;// 输出第N天发了多少工资
	return 0;
}

