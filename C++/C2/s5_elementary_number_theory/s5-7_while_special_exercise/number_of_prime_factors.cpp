#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a=2,n,w=0;
	cin>>n;
	while(n>1)
	{
		while(n%a==0)
		{
			w++;
			n/=a;
		}
		a++;
	}
	cout<<w;
}

