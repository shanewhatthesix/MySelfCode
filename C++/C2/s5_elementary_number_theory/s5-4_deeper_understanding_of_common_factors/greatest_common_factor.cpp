#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	long long y=a%b;
	while(y>0){
		a=b;
		b=y;
		y=a%b;

	}
	cout<<b;
	

	return 0;
}
