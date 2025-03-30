#include<bits/stdc++.h>
using namespace std;
int a[100];
int main(){
	int n;cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	for(int k=0;k<n;++k){
		int maxi=k,cmax=a[k];
		for(int i=k;i<n;++i){
			if(a[i]>cmax){
				maxi=i;
				cmax=a[i];
			}
		}
		swap(a[k],a[maxi]);
	}
	for(int i=0;i<n;++i){
		cout<<a[i]<<" ";
	}
	return 0;
}
