#include<bits/stdc++.h>
using namespace std;
int main(){

	long long n,m,now_num=0,all=0;
	cin>>n>>m;

	for(int i=n;i<=m;++i){
		now_num=i;
		//cout<<now_num<<endl;
		while(now_num>0){
		if(now_num%10==2){
			all+=1;
		}
		now_num/=10;
		}
		
 }
	cout<<all<<endl;

	return 0;
}
