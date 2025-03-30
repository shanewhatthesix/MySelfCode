#include<bits/stdc++.h>
using namespace std;
int main(){
	double r,m,y,a=0;
	cin>>r>>m>>y;
	r=r/100+1;
	while(m<y){
		m*=r;
		a+=1;
	}
	cout<<a;
	
	return 0;
}
