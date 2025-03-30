#include<bits/stdc++.h>
using namespace std;
int main(){
	
	int n,m;
	cin>>n>>m;
	int s[n][m];
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cin>>s[i][j];
		}
	}
	int x,y;
	cin>>x>>y;
	cout<<s[x-1][y]<<" "<<s[x+1][y]<<" "<<s[x][y-1]<<" "<<s[x][y+1];
	
	return 0;
}
