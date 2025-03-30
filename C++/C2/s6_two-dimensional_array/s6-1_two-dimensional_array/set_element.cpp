#include<bits/stdc++.h>
using namespace std;
int main()
{
	int s[2][2];
	int n;
	for(int i=0; i<2; i++)
	{
		for(int j=0; j<2; j++)
		{
			cin>>s[i][j];
		}
	}
	cin>>n;
	s[0][0]=n;
	for(int i=0; i<2; i++)
	{
		cout<<s[i][0]<<" "<<s[i][1]<<endl;
	}
}

