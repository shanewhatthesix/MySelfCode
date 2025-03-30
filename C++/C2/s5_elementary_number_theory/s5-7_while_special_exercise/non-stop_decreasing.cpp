#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a=2,n;
	cin>>n;
	while(n>1){
		while(n%a==0){
			cout<<a<<" ";
			n/=a;
		}
		a++;
	}
}

