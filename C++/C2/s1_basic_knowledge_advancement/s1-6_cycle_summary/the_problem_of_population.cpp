#include<bits/stdc++.h>
using namespace std;
int main(){
	double x,n;
	cin>>x>>n;
	for(int i=0;i<n;i++){
		x*=1.001;
	}
	printf("%.4f",x);

	return 0;
}
