#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,x,m;
	cin>>n>>x>>m;
	int a[n];
	fill(a,a+n+1,x);
	for(int i=0;i<m;i++){
		int j=0,w=0;
		cin>>j>>w;
		a[j-1]=w;
	}
	for(int i=0;i<n-1;i++){
		if(a[i]>a[i+1]){
			swap(a[i],a[i+1]);
		}
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}

