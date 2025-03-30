#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int sz[n];
	for(int i=0;i<n;i++){
		cin>>sz[i];
	}
	reverse(sz+n/2,sz+n);
	for(int i=0;i<n;i++){
		cout<<sz[i]<<" ";
	}
	return 0;
}

