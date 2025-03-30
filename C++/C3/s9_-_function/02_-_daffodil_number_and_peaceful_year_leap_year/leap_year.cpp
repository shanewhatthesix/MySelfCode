#include<bits/stdc++.h>
using namespace std;

bool year(int y) {
	if(y%100!=0)
		return y%4;
	else return 1;
}

main() {
	int y;
	cin>>y;
	if(year(y)) cout<<"no";
	else cout<<"yes";
}

