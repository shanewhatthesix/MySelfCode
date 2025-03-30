#include<bits/stdc++.h>
using namespace std;
int main() {

	int n,m;
	cin>>n>>m;
	int a[n][m];

	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			cin>>a[i][j];
		}
	}
	int x,y;
	cin>>x>>y;

	for(int j=0; j<m; ++j) {
		if(j!=y)
			cout<<a[x][j]<<" ";
	}
	cout<<endl;
	for(int i=0; i<n; ++i) {
		if(i!=y)
			cout<<a[i][y]<<" ";
	}
}

