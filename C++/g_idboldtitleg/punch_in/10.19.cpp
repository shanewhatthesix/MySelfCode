#include<bits/stdc++.h>
using namespace std;

int main(){
	int a[5]={7,2,30,27,10};
	
	sort(a+1,a+5);
	
	for(int i=0;i<5;++i){
		cout<<a[i]<<" ";
	}
}
