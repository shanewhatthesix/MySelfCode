
#include<bits/stdc++.h>
using namespace std;

int a[1005];
int n,w;

int main() {
	cin>>n>>w;

	for(int i=1; i<=n; ++i) {
		cin>>a[i];
	}
	int zs=0;
	for(int i=1; i<=n; ++i) {
		int zd=a[i];
		for(int j=1; j+i-1<=n; ++j) {
			if(zd>a[i+j-1]) {
				zd=a[i+j-1];
			}
			int s=zd*j*w;
			//cout<<i<<" "<<j<<" "<<zd<<" "<<s<<endl;
			if(zs<s) {
				zs=s;
			}
		}
	}
	cout<<zs;
	return 0;
}
