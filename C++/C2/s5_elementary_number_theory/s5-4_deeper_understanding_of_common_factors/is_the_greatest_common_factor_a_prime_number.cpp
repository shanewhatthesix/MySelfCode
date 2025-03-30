#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a,b;
	cin>>a>>b;
	long long y=a%b;
	while(y>0){
		a=b;
		b=y;
		y=a%b;

	}
	int s=0;
	for(int i=2;i*i<=b;++i){
		if(b%i==0){
			s++;
			break;
		}
	}
	
	if(s==0){
		cout<<1;
	}
	else{
		cout<<0;
	}

	return 0;
}
