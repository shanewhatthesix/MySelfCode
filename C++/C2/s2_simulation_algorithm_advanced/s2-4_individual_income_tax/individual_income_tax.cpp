#include<bits/stdc++.h>
using namespace std;
int main(){

	int m,k;//定义每个月的月工资以及每月各类总扣除。
	cin>>m>>k;
	int y=(m-5000-k)*12;//定义个人全年应纳税所得额。

	if(y<=0){
		cout<<"0.0";
		return 0;
	}

	float l1=36000*0.03;
	float l2=(144000-36000)*0.1;
	float l3=(300000-144000)*0.2;
	float l4=(420000-300000)*0.25;
	float l5=(660000-420000)*0.3;
	float l6=(960000-660000)*0.35;

	double s=0;
	if(y<=36000)
		s=y*0.03;
	else if(y<=144000)
		s=l1+(y-36000)*0.1;
	else if(y<=300000)
		s=l1+l2+(y-144000)*0.2;
	else if(y<=420000)
		s=l1+l2+l3+(y-300000)*0.25;
	else if(y<=660000)
		s=l1+l2+l3+l4+(y-420000)*0.3;
	else if(y<=960000)
		s=l1+l2+l3+l4+l5+(y-660000)*0.35;
	else
		s=l1+l2+l3+l4+l5+l6+(y-960000)*0.45;

	cout<<s<<endl;
	printf("%.1f",s);

	return 0;
}
