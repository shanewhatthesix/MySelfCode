#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	
	int a[10000];
	int zgi=0;
	int zg=0;
	for(int i=0;i<n;++i){
		cin>>a[i];
		if(zg<a[i]){
			zg=a[i];
			zgi=i;
		}
	}
	
	for(int i=0;i<n;++i){
		if(zg==a[i]){
			cout<<i<<" ";
		}
	}
	
	return 0;
}
