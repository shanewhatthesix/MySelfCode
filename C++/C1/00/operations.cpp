#include<bits/stdc++.h>
using namespace std;
int main(){
	float sma=0,c;
	cin>>c;
	for(float i=0;i<c;++i){
		float n;
		cin>>n;

		if(sma>n && n!=0){
			sma=n;
		}
	}
	cout<<sma<<endl;

	return 0;
}
