#include<bits/stdc++.h>
using namespace std;
/*
int main(){
	int a,b;
	cin>>a>>b;
	int y=a%b;
	cout<<"第1次处理结果："<<a<<" "<<b<<" "<<y<<endl;
	int m=1;

	while(y>0){
		m+=1;cout<<"第"<<m<<"次处理结果：";
		a=b;cout<<a<<" ";
		b=y;cout<<b<<" ";
		y=a%b;cout<<y<<endl;
	}

	cout<<"最终结果（b）"<<b;

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

