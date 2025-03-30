#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	double tall=0,num=1;
	cin>>n;
	double candy[n];
	for(int i=0;i<n;i++){
		cin>>candy[i];
		if (candy[i]>tall){
			tall=candy[i];
			num=i+1;
		}
	}
	cout<<tall<<" "<<num;

}
