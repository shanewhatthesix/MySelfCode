#include<bits/stdc++.h>
using namespace std;
int main(){

	//原数
	int ya,yb,L;
	cin>>ya>>yb>>L;
	
	int za,zb;
	//ra和rb都<=L
	//ra和rb互质
	float zx=100000;
	
	for(int ra=1;ra<=L;++ra){
		for(int rb =1;rb<=L;++rb){
			if(ra*1.0/rb<ya*1.0/yb){
				continue;
			}
			
			int n=ra,m=rb;
			int y=n%m;
			while(y>0){
				n=m;
				m=y;
				y=n%m;
			}
			if(m!=1){
				continue;
			}
			
			if(ra*1.0/rb-ya*1.0/yb<zx){
				zx=ra*1.0/rb-ya*1.0/yb;
				za=ra;
				zb=rb;
			}
		}
	}
	
	cout<<za<<" "<<zb;
	
	return 0;
}
