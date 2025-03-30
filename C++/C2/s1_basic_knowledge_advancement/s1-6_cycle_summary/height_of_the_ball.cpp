#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,i=0;
	double h,j=0.0,b;
	cin>>h>>n;
	j=h;
	b=h;
	while(i<n-2){
		h/=2;
		j+=h;
		i++;
	}
	cout<<j+b<<endl;
	while(i<n){
		h/=2;
		j+=h;
		i++;
	}
	printf("%9f",h);

	return 0;
}
