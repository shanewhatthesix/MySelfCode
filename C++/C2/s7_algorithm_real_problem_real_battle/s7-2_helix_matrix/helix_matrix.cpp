#include<bits/stdc++.h>
using namespace std;
int a[1000][1000];
int main(){
	
	int n;
	cin>>n;
	//在数组外面加一圈1
	for(int j=0;j<=n+1;++j){
		a[0][j]=1;
	}
	for(int i=0;i<=n+1;i++){
		a[i][n+1]=1;
	}
	for(int i=0;i<=n+1;++i){
		a[i][0]=1;
	}
	for(int j=0;j<=n+1;j++){
		a[n+1][j]=1;
	}
	
	int i=1,j=1,c=1;
	
	while(c<=n*n){
		while(a[i][j]==0){
			a[i][j]=c;
			c++;
			j++;
		}
		j--;i++;
		
		while(a[i][j]==0){
			a[i][j]=c;
			c++;
			i++;
		}
		i--;j--;
		
		while(a[i][j]==0){
			a[i][j]=c;
			c++;
			j--;
		}
		j++;i--;
		
		while(a[i][j]==0){
			a[i][j]=c;
			c++;
			i--;
		}
		i++;j++;
	}
	
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	
	return 0;
}
