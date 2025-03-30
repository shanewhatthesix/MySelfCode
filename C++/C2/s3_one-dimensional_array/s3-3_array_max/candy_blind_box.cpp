#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,sma=1000,num=1;
	cin>>n;
	int candy[n];
	for(int i=0;i<n;i++){
		cin>>candy[i];
		if (candy[i]<sma){
			sma=candy[i];
			num=i+1;
		}
	}
	cout<<num;

}
