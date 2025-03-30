#include<bits/stdc++.h>
using namespace std;
int main(){
	
	
	int a,b;
	cin>>a>>b;
	if(abs(a-b)!=2){
		cout<<"no";
		return 0;
	}
	
	int s=0;
	for(int i=2;i*i<=a;++i){
		if(a%i==0){
			s++;
			break;
		}
	}
	if(s!=0){
		cout<<"no";
		return 0;
	}
	
	s=0;
	for(int i=2;i*i<=b;++i){
		if(b%i==0){
			s++;
			break;
		}
	}
	if(s!=0){
		cout<<"no";
		return 0;
	}
	
	cout<<"yes";
	
	return 0;
}
