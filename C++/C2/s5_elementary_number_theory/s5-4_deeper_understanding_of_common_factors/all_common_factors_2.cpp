#include<bits/stdc++.h>
using namespace std;
int main()
{

	int a,b;
	cin>>a>>b;
	long long a1=a,b1=b,y=a%b;
	
	while (y>0)
	{
		a=b;
		b=y;
		y=a%b;
	}

	for (int i=a; i>=1; --i)
	{
		if(a1%i==0 && b1%i==0)
		{
			cout<<i<<" ";
		}
	}
	return 0;
}

