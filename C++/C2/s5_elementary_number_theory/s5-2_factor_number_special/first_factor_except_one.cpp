#include<bits/stdc++.h>
using namespace std;
int main()
{

	int n,y=1;
	cin>>n;
	for(int i=2; i<=n; ++i)
	{
		if(n%i==0)
		{
			y=i;
			break;
		}
	}
	
	int s=0;
	for(int i=2;i*i<=y;++i){
		if(y%i==0){
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

