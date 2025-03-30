#include<bits/stdc++.h>
using namespace std;

char mines[105][105];
int m,n;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			char c;
			cin>>c;
			if(c=='*'){
				mines[i][j]='*';
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(mines[i][j]==0){
				if(mines[i-1][j-1]=='*')mines[i][j]++;
				if(mines[i-1][j]=='*')mines[i][j]++;
				if(mines[i-1][j+1]=='*')mines[i][j]++;
				if(mines[i][j-1]=='*')mines[i][j]++;
				if(mines[i][j+1]=='*')mines[i][j]++;
				if(mines[i+1][j-1]=='*')mines[i][j]++;
				if(mines[i+1][j]=='*')mines[i][j]++;
				if(mines[i+1][j+1]=='*')mines[i][j]++;
				cout<<int(mines[i][j]);
			}
			else{
				cout<<'*';
			}
		}
		cout<<endl;
	}
}
