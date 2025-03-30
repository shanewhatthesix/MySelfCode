#include<bits/stdc++.h>
using namespace std;
int main(){
	long long sma=100000,dn=100000,c;
	cin>>c;
	for(int i=0;i<c;++i){
		int d,h,m;
		cin>>d>>h>>m;
		int n=60*h+m;
		if (n==0){
			continue;
		}
		if(sma>n){
			//cout<<n<<endl;
			sma=n;
			dn=d;
		}
	}
	cout<<dn<<" "<<sma/60<<" "<<sma%60;

	return 0;
}
