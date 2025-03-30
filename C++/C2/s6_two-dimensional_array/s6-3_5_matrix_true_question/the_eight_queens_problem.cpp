#include<bits/stdc++.h>
using namespace std;

int q[10][10];

int main() {

	for(int i=1; i<=8; ++i) {
		for(int j=1; j<=8; ++j) {
			char c;
			cin>>c;
			if(c=='#') {
				q[i][j]=1;
			}
		}
	}

	for(int i=1; i<=8; ++i) {
		for(int j=1; j<=8; ++j) {
			if(q[i][j]==1){
				for(int k=j-1;k>0;--k){
					if(q[i][k]==1){
						cout<<0;
						return 0;
					}
				}
				for(int k=i-1;k>0;--k){
					if(q[k][j]==1){
						cout<<0;
						return 0;
					}
				}
				
				for(int k=1;i-k>0 && j-k>0;++k){
					if(q[i-k][j-k]==1){
						cout<<0;
						return 0;
					}
				}
				
				for(int k=1;i-k>0 && j+k<=8;++k){
					if(q[i-k][j+k]==1){
						cout<<0;
						return 0;
					}
				}
			}
		}
	}
	c
}
