#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int a[n];
	for(int j=0; j<n; j++) {
		cin>>a[j];
	}
	for(int k=n; k>0; --k) {
		for(int i=0; i<n-1; ++i) {
			if(a[i]>a[i+1]) {
				swap(a[i],a[i+1]);
			}
		}
	}
	for(int j=0; j<n; j++) {
		cout<<a[j]<<endl;
	}
}
