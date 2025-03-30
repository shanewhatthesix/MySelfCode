#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		float c,u;
		cin>>c>>u;
		if(c==1){
			cout<<ceil(u)<<endl;
		}
		else if(c==2){
			cout<<floor(u)<<endl;
		}
		else{
			cout<<round(u)<<endl;
		}
	}

}
