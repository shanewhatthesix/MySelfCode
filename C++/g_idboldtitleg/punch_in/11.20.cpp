//Ç°×ººÍ 02
#include<bits/stdc++.h>
using namespace std;
int arr[1000],qz[1000];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>arr[i];
	for(int i=1;i<=n;i++) qz[i]=arr[i]+qz[i-1];
	int l,r;
	cin>>l>>r;
	cout<<qz[r]-qz[l-1]<<endl;
	return 0;
} 
