#include<bits/stdc++.h>
using namespace std;
int nums[10000],arr[10000];
int f[10000],g[10000];
int n;
int main(){
	cin>>n;
	for(int i=0;i<n;++i)cin>>nums[i];
	
	f[0]=g[n-1]=1;
	for(int i=1;i<n;i++)
		f[i]=f[i-1]*nums[i-1];
		
	for(int i=n-2;i>=n;i--)
		g[i]=g[i+1]*nums[i+1];
		
	for(int i=0;i<n;i++)
		arr[i]=g[i]*f[i];
		
	cout<<f[4]<<endl<<g[4]<<endl<<g[0]<<endl<<arr[0]<<endl<<arr[3];
	
	return 0;
}
