#include<bits/stdc++.h>
using namespace std;
int main(){
	double l,bt,wt,fast=1000000;
	string fo;
	cin>>l;
	bt=50+l/3.0;
	wt=l/1.2;
	//cout<<bt<<wt;
	if(bt<fast){
		fo="Bike";
	}
	if (wt<bt){
		fo="Walk";
	}
	else if (wt==bt){
		fo="All";
	}
	if(l<=0){
		fo="Error";
	}
	cout<<fo;
	
	return 0;
}
/*
描述

在大学校园里，没有自行车，上课、办事会很不方便。但实际上，并非去办任何事情都是骑车快，因为骑车总要找车、开锁、停车、锁车等，这要耽误一些时间。

假设，找到自行车，开锁并骑上自行车的时间为27秒；停车锁车的时间为23秒；步行每秒行走1.2米，骑车每秒行走3.0米。请判断走不同的距离去办事，是骑车快还是走路快。


输入
一行一个整数，0以上数字，表示一次办事要行走的距离，单位为米。


输出
一行一个单词，如果骑车快，则输出一行“Bike”；如果走路快，则输出一行“Walk”；如果一样快，输出一行“All”。如果输入是负数，则输出“Error”。
*/
