#include<bits/stdc++.h>
using namespace std;
int main()
{

	int c,s=0;
	cin>>c;
	for(int i=1; i<=c; i++)
	{
		if(c%i==0)
		{
			s++;
		}
	}
	cout<<s;
	return 0;
}
