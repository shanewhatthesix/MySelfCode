#include<bits/stdc++.h>
using namespace std;
/*
int main(){
	int a,b;
	cin>>a>>b;
	int y=a%b;
	cout<<"��1�δ�������"<<a<<" "<<b<<" "<<y<<endl;
	int m=1;

	while(y>0){
		m+=1;cout<<"��"<<m<<"�δ�������";
		a=b;cout<<a<<" ";
		b=y;cout<<b<<" ";
		y=a%b;cout<<y<<endl;
	}

	cout<<"���ս����b��"<<b;

	return 0;
}
*/
int cf(int a,int b){
	int y=a%b;
	while(y>0){
		a=b;
		b=y;
		y=a%b;
	}
	return b;
}

int main(){
	int a,b;
	cin>>a>>b;
	cout<<cf(a,b);
}

