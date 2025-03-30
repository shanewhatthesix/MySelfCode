#include<bits/stdc++.h>
using namespace std;
int main()
{

	int n,s=0;
	cin>>n;
	for(int i=n-1; i>=1; --i)
	{
		if(n%i==0)
		{
			cout<<i;
			break;
		}
	}
	return 0;
}
