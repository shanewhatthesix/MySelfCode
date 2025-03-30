#include<bits/stdc++.h>
using namespace std;
int main(){
	int bigger;
	for(int i=0;i<10;++i){
		int n;
		cin>>n;
		if(n>bigger){
			bigger=n;
			printf("The bigger number is %d .",bigger);
			cout<<endl;
		}
	}

	return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,zx=1000000000;
	cin>>n;
	for(int i=0;i<3;++i){
		int m,p,c;
		cin>>m>>p;
		if(n%m==0){
			c=n/m*p;
		}
		else{
			c=n/m*p+p;
		}

		if(zx>c){
			zx=c;
		}
	}
	cout<<zx;

	return 0;
}
*/
