#include<bits/stdc++.h>
using namespace std;
int main(){

	int d1,d2;
	cin>>d1>>d2;
	
	int year1=d1/10000;
	int month1=d1%10000/100;
	int day1=d1%100;
	
	int year2=d2/10000;
	int month2=d2%10000/100;
	int day2=d2%100;
	
	int zs=0;
	
	for(int cy=year1;cy<=year2;++cy){
		for(int cm=1;cm<=12;++cm){
			int n=31;
			if(cm==4 || cm==6 || cm==9 || cm==11)
				n=30;
			else if(cm==2)
				if(cy%400==0 ||cy%100!=0 && cy%4==0)
					n=29;
				else
					n=28;
			for(int cd=1;cd<=n;++cd){
				int date=cy*10000+cm*100+cd;
				if(date<d1 || date>d2)
					continue;

				//»ØÎÄ
				int t=date;
				int k=0;
				while(t>0){
					k=k*10+t%10;
					t/=10;
				}
				if(k==date){
					zs++;
				}
			}
		}
	}
	cout<<zs;
	return 0;
}
