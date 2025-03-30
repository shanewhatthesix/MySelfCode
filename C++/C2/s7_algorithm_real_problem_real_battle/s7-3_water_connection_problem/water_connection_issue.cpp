#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int n,m;
int main(){
	
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	
	int pd=m+1;
	
	for(int i=pd;i<=n;++i){
		int zx=1000000;
		int zxi=0;
		for(int j=1;j<=m;++j){
			if(a[j]<zx){
				zx=a[j];
				zxi=j;
			}
		}
		a[zxi]+=a[i];
	}
	
	int zd=0;
	for(int j=1;j<=m;++j){
		if(a[j]>zd){
			zd=a[j];
		}
	}
	cout<<zd;
	
	return 0;
}
