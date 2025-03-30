#include<bits/stdc++.h>
using namespace std;

bool flower (int x){
	int c=x%10;int b=x/10%10;int a=x%100;
	if(c^3+b^3+a^2==x) return 1;
	else return 0;
}

int main(){
	int n;
	cin>>n;
	if(flower(n)) cout<<"yes";
	else cout<<"no";
}


