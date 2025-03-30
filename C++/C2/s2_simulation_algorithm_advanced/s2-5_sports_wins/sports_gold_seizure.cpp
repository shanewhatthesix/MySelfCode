#include<bits/stdc++.h>
using namespace std;
int main(){
	
	int n,l=0;
	cin>>n;
	float z=0;

	for(int i=0;i<n;++i){
		int dis,sign;
		cin>>dis>>sign;
		float day =0;
		if(sign==1){
			l++;
			if(dis>=1000){
				day=0.3;
				day+=(dis-1000)/2000*0.1;
				if(day>3){
					day=3;
				}
			}
			if(l>=4){
				day*=2;
			}
		}
		else{
			l=0;
		}
		z+=day;
	}
	
	printf("%.1f",z);

	return 0;
}

