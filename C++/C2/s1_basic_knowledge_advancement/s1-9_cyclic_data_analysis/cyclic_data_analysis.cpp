/*
#include<bits/stdc++.h>
using namespace std;
int main(){
	//看代码时，先把数据代入代码进行理解，将每一步的运行结果写出来看一看
	int c=2009,n=11,p=2,s=0,i,j,t=1;
	for(i=1;i<=n;i++){
		t=t*p%c;
		//cout<<t;
		for(j=1;j<=1;j++){
			s=(s+t)%c;
		}
	}
	cout<<s<<endl;

	return 0;
}
	执行11次:
	t=2;
	s=2;
	
	t=4
	s=6
	
	t=8
	s=14
	
	t=16
	s=30
	
	t=32
	s=62
	
	t=64
	s=126
	
	t=128
	s=254
	
	t=256
	s=510
	
	t=512
	s=1022
	
	t=1024
	s=37
	
	t=39
	s=76
	
	输出:76
	

    执行

*/
